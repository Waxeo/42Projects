import requests, os, re, random, string
from django.shortcuts import render, redirect
from django.contrib import messages
from django.contrib.auth import login, logout, authenticate
from django.core.validators import validate_email
from django.core.exceptions import ValidationError
from django.http import HttpResponse, JsonResponse
from django.conf import settings
from django.views.decorators.csrf import csrf_exempt, ensure_csrf_cookie
from django.middleware.csrf import get_token
from rest_framework import status
from rest_framework.views import APIView
from rest_framework.response import Response # type: ignore
from rest_framework.permissions import IsAuthenticated
from rest_framework.decorators import api_view
from rest_framework_simplejwt.tokens import AccessToken
from .models import User, Stat, Game
from .serializers import OauthUserSerializer, loginSerializer, registerSerializer, friendSerializer, statsSerializer, tournamentSerializer
from .serializers import OauthUserSerializer, loginSerializer, registerSerializer, friendSerializer, statsSerializer
from .models import User, Stat
from .serializers import OauthUserSerializer, loginSerializer, registerSerializer, friendSerializer, statsSerializer, otpSerializer, nicknameSerializer

from django.contrib.auth import authenticate
from rest_framework_simplejwt.tokens import RefreshToken
import random
import string
from django.contrib.auth import authenticate, login
from .utils import generate_otp, send_otp_email


@api_view(['POST'])
def add_friend(request):
	try:
		serializer = friendSerializer(data=request.data)
		if serializer.is_valid():
			friend_data = serializer.validated_data
			username = friend_data['username']
			if username == request.user.nickname:
				return Response({"error":"You cannot add yourself as a friend."}, status=400)
			try:
				user_to_add = User.objects.get(username=username)
				if user_to_add in request.user.friends.all():
					return Response({"error":f"{username} is already your friend."}, status=400)
				else:
					request.user.friends.add(user_to_add)
					return Response({"message":f"{username} added as friend."}, status=200)
			except User.DoesNotExist:
				return Response({"error":"User does not exist."}, status=400)
	except Exception as e:
		return Response({'error': str(e)}, status=400)

@api_view(['POST'])
def accept_friend_request(request):
	return Response({"message":"salut"})



@api_view(['POST'])
def login_view(request):
	try:
		serializer = loginSerializer(data=request.data)
		if serializer.is_valid():
			login_data = serializer.validated_data
			username = login_data['username']
			password = login_data['password']
			user = authenticate(username=username, password=password)
			if user is not None:
				if not user.is_2fa:
					login(request, user)
					user.online = True
					user.save()
					token = AccessToken.for_user(user)
					encoded_token = str(token)
					user_data = {
						'message' : 'Login successful',
						'username' : getattr(user, 'username', 'unknown'),
						'nickname' : getattr(user, 'nickname', 'unknown'),
						'email' : getattr(user, 'email', 'unknown'),
						'jwt_token': encoded_token,
					}
					return Response(user_data, status=200)
				else:
					otp = generate_otp()
					user.otp_code = otp
					user.save()
					send_otp_email(user.email, otp)
					return Response({'message': 'OTP sent to email', 'username': username}, status=200)
			else:
				return Response({'error': 'Invalid login credentials'}, status=400)
		else:
			return Response(serializer.errors, status=401)
	except Exception as e:
		return Response({'error': str(e)}, status=400)
		
def logout_view(request):
	try:
		if request.method == 'POST':
			if request.user.is_authenticated:
				request.user.online = False
				request.user.save()
				logout(request)
			return JsonResponse({"message": "Logout Successful"}, status=200)
		else:
			return JsonResponse({'error': 'Unknown method'}, status=401)	
	except Exception as e:
		return JsonResponse({'error': str(e)}, status=400)		

def oauth2_login(request):
	redirect_url = 'https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-115cd61e7027f57123f0c3e86b1d5165c460c57ed30ee134ffe15ea960790b7d&redirect_uri=https%3A%2F%2Flocalhost%3A3000%2Fapi%2Fcallback%2F&response_type=code'
	return redirect(redirect_url)
	
@api_view(['POST'])
def register_view(request):
	try:
		serializer = registerSerializer(data=request.data)
		if serializer.is_valid():
			register_data = serializer.validated_data
			username = register_data['username']
			email = register_data['email']
			password = register_data['password1']
			confirmed_password = register_data['password2']

			try:
				validate_email(email)
			except ValidationError:
				return Response({'error': 'Email is not valid'}, status=400)


			if password != confirmed_password:
				return Response({'error': 'Passwords do not match'}, status=400)

			if len(password) < 8:
				return Response({'error': 'Your password must contain at least 8 character.'}, status=400)

			if not re.findall('[A-Z]', password):
				return Response({'error': 'Your password must contain at least 1 uppercase letter.'}, status=400)

			if not re.findall('[a-z]', password):
					return Response({'error': 'Your password must contain at least 1 lowercase letter.'}, status=400)

			if not re.findall('[0-9]', password):
				return Response({'error': 'Your password must contain at least 1 number.'}, status=400)

			if not re.findall(r'\W', password):
				return Response({'error': 'Your password must contain at least 1 special character.'}, status=400)

			if (User.objects.filter(username=username).exists()):
				return Response({'error': 'Username already used'}, status=400)

			if (User.objects.filter(email=email).exists()):
				return Response({'error': 'Email already used'}, status=400)

						

			user = User.objects.create_user(username=username, email=email, password=password, nickname=username)
			user.stat = Stat.objects.create(user=user)
			return Response({'message': 'User registered successfully.'}, status=200)
		else:
			return Response(serializer.errors, status=401)
	except Exception as e:
		return Response({'error': str(e)}, status=400)

class OauthCallbackView(APIView):
	def get(self, request):
		try:
			code = request.GET['code']
			data    = {
				'grant_type': 'authorization_code',
				'client_id': os.getenv('CLIENT_ID'),
				'client_secret': os.getenv('CLIENT_SECRET'),
				'code': code,
				'redirect_uri': 'https://localhost:3000/api/callback/',
			}
			response = requests.post('https://api.intra.42.fr/oauth/token', data=data)

			if response.status_code == 200:
				access_token = response.json().get('access_token')

				user_data_response = requests.get('https://api.intra.42.fr/v2/me', headers={'Authorization': f'Bearer {access_token}'})
				user_serializer = OauthUserSerializer(data=user_data_response.json())
				if user_serializer.is_valid():
					try:
						user = User.objects.get(username=user_serializer.validated_data['login'])
						if not user.is_oauth:
							return redirect('/login')
						if user.is_2fa:
							otp = generate_otp()
							user.otp_code = otp
							user.save()
							username = user_serializer.validated_data['login']
							token = AccessToken.for_user(user)
							encoded_token = str(token)
							is_2fa = 'True'
							send_otp_email(user.email, otp)
							redirect_url = f'/return?jwtToken={encoded_token}&2fa={is_2fa}&username={username}'
							return redirect(redirect_url)
						else:
							login(request, user)
							user.online = True
							user.save()
							username = user_serializer.validated_data['login']
							is_2fa ='False'
							token = AccessToken.for_user(user)
							encoded_token = str(token)
							redirect_url = f'/return?jwtToken=e{encoded_token}&2fa={is_2fa}&username={username}'
							return redirect(redirect_url)
					except User.DoesNotExist:
						try:
							user = User.objects.get(email=user_serializer.validated_data['email'])
							if not user.is_oauth:
								return redirect('/login')
						except User.DoesNotExist:
							user = user_serializer.save()
							user.is_oauth = True
							user.online = True
							user.nickname = user.username
							stat = Stat.objects.create(user=user)
							stat.save()
							user.save()
							login(request, user)
							token = AccessToken.for_user(user)
							encoded_token = str(token)
							redirect_url = '/return?jwtToken={encoded_token}'
							return redirect(redirect_url)
				else:
					return JsonResponse(user_serializer.errors, status=400)   

			else:
				return JsonResponse({"error": response.text}, status=400)
		except Exception as e:
			return JsonResponse({'error': str(e)}, status=400)

@ensure_csrf_cookie
def get_csrf_token(request):
    try:
        csrf_token = get_token(request)
        return JsonResponse({'csrfToken': csrf_token})
    except Exception as e:
        return JsonResponse({'error': str(e)}, status=400)

class profilView(APIView):
	def get(self, request):
		try:
			user = request.user
			if user is not None:	
				stat = user.stat
				friend_lst = []
				if user.friends.all().count() > 0:
					for friend in user.friends.all():
						friend_lst.append({
							'username': friend.username,
							'nickname': friend.nickname,
							'ingame': friend.ingame,
							'online': friend.online,
							'profil_image': friend.profil_image.url,
						})
				game_lst = []
				if user.games.all().count() > 0:
					for game in user.games.all():
						if game.opponent == 'Tournament':
							game_lst.append({
								'opponent': game.opponent,
								'win': game.win,
								'date': game.date,
							})
						else:
							game_lst.append({
								'opponent': game.opponent,
								'win': game.win,
								'my_score': game.my_score,
								'opponent_score': game.opponent_score,
								'date': game.date,
							})
				data = {
					'nickname': user.nickname,
					'email': user.email,
					'profil_image': user.profil_image.url,
					'number_of_game': stat.number_of_game,
					'number_of_win': stat.number_of_win,
					'number_of_defeat': stat.number_of_defeat,
					'win_percentage': stat.win_percentage,
					'friends': friend_lst,
					'games': game_lst,
				}
				return JsonResponse({'data': data}, status=200)
		except Exception as e:
			return JsonResponse({'error': str(e)}, status=400)

	def post(self, request):		
		try:
			try:
				user = User.objects.get(username=request.data['username'])
			except User.DoesNotExist:
				return Response({"error":"User does not exist."}, status=400)	
			if user is not None:	
				stat = user.stat
				friend_lst = []
				if user.friends.all().count() > 0:
					for friend in user.friends.all():
						friend_lst.append({
							'username': friend.username,
							'nickname': friend.nickname,
							'ingame': friend.ingame,
							'online': friend.online,
							'profil_image': friend.profil_image.url,
						})
				game_lst = []
				if user.games.all().count() > 0:
					for game in user.games.all():
						if game.opponent == 'Tournament':
							game_lst.append({
								'opponent': game.opponent,
								'win': game.win,
								'date': game.date,
							})
						else:
							game_lst.append({
								'opponent': game.opponent,
								'win': game.win,
								'my_score': game.my_score,
								'opponent_score': game.opponent_score,
								'date': game.date,
							})
				data = {
					'message': 'Other profile',
					'nickname': user.nickname,
					'email': user.email,
					'profil_image': user.profil_image.url,
					'number_of_game': stat.number_of_game,
					'number_of_win': stat.number_of_win,
					'number_of_defeat': stat.number_of_defeat,
					'win_percentage': stat.win_percentage,
					'friends': friend_lst,
					'games': game_lst,
				}
				return JsonResponse({'data': data}, status=200)	
		except Exception as e:
			return JsonResponse({'error': str(e)}, status=400)


def generate_otp():
    return ''.join(random.choices(string.digits, k=6))

@api_view(['POST'])
def verify_otp_view(request):
	try:
		serializer = otpSerializer(data=request.data)
		if serializer.is_valid():
			otp_data = serializer.validated_data
			user = User.objects.get(username=otp_data['username'])
			if user.otp_code == otp_data["otp_code"]:
				login(request, user)
				user.online = True
				user.save()
				token = AccessToken.for_user(user)
				encoded_token = str(token)
				user_data = {
					'message': 'Login successful',
					'username': getattr(user, 'username', 'unknown'),
					'nickname': getattr(user, 'nickname', 'unknown'),
					'email': getattr(user, 'email', 'unknown'),
					'jwt_token': encoded_token,
				}
				return Response(user_data, status=200)
			else:
				return Response({'error': 'Invalid OTP'}, status=400)
	except Exception as e:
		return Response({'error': str(e)}, status=400)
	

def upload_view(request):
	if request.method == 'POST' and request.FILES.get('image'):
		user = request.user
		user.profil_image = request.FILES.get('image')
		user.save()
		return JsonResponse({'profil_image': user.profil_image.url}, status=200)
	return JsonResponse({'error': 'No image provided or invalid request.'}, status=400)

@api_view(['POST'])
def game_end_view(request):
	try:
		serializer = statsSerializer(data=request.data)
		if serializer.is_valid():
			game_data = serializer.validated_data
			user = request.user
			stat = user.stat
			stat.number_of_game += 1
			if game_data['win'] == True:
				stat.number_of_win += 1
			else:
				stat.number_of_defeat += 1
			stat.win_percentage = stat.number_of_win / user.stat.number_of_game * 100
			stat.save()
			user.save()
			new_game = Game.objects.create(user=user, win=game_data['win'], opponent=game_data['opponent'], my_score=game_data['my_score'], opponent_score=game_data['opponent_score'])
			new_game.save()
			return Response({'message': 'Data send successfully'}, status=200)    
		else:
			return Response({'error': serializer.errors}, status=400)
	except Exception as e:
		return Response({'error': str(e)}, status=400)

@api_view(['POST'])
def tournament_view(request):
	try:
		serializer = tournamentSerializer(data=request.data)
		if serializer.is_valid():
			game_data = serializer.validated_data
			user = request.user
			user.stat.number_of_game += 1
			if game_data['win'] == True:
				user.stat.number_of_win += 1
			else:
				user.stat.number_of_defeat += 1
			user.stat.win_percentage = user.stat.number_of_win / user.stat.number_of_game * 100
			user.game = Game.objects.create(user=user, win=game_data['win'], opponent=game_data['opponent'])
			user.save()
			return Response({'message': 'Data send successfully'}, status=200)    
		else:
			return Response({'error': serializer.errors}, status=400)
	except Exception as e:
		return Response({'error': str(e)}, status=400)				

@api_view(['GET'])
def ingame_view(request):
	try:
		user = request.user
		user.ingame = True
		user.save()
		return Response(status=200)
	except Exception as e:
		return Response({'error': str(e)}, status=400)

@api_view(['GET'])
def not_ingame_view(request):
	try:
		if request.user.is_authenticated:
			user = request.user
			user.ingame = False
			user.save()
		return Response(status=200)
	except Exception as e:
		return Response({'error': str(e)}, status=400)

@api_view(['POST'])
def change_nickname(request):
	try:
		serializer = nicknameSerializer(data=request.data)
		if serializer.is_valid():
			data = serializer.validated_data
			nickname = data['nickname']
			request.user.nickname = nickname
			request.user.save()
			return Response({'message': 'Update successful'}, status=200)    
		else:
			return Response({'error': serializer.errors}, status=400)
	except Exception as e:
		return Response({'error': str(e)}, status=400)
