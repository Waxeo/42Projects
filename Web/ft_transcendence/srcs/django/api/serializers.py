from rest_framework import serializers
from . import models
from django.contrib.auth import login, authenticate

class	OauthUserSerializer(serializers.Serializer):
	login = serializers.CharField()
	email = serializers.EmailField()

	def create(self, validated_data):
		user = models.User.objects.create(
			username = validated_data['login'],
			email = validated_data['email']
		)
		return user

class	loginSerializer(serializers.Serializer):
	username = serializers.CharField()
	password = serializers.CharField(write_only=True)

class	registerSerializer(serializers.Serializer):
	username = serializers.CharField()
	email = serializers.EmailField()
	password1 = serializers.CharField(write_only=True)
	password2 = serializers.CharField(write_only=True)

class friendSerializer(serializers.Serializer):
	username = serializers.CharField()

class statsSerializer(serializers.Serializer):
	opponent = serializers.CharField()
	my_score = serializers.CharField()
	opponent_score = serializers.CharField()
	win = serializers.BooleanField()

class tournamentSerializer(serializers.Serializer):
	opponent = serializers.CharField()
	win = serializers.BooleanField()

class otpSerializer(serializers.Serializer):
	otp_code = serializers.CharField()
	username = serializers.CharField()

class nicknameSerializer(serializers.Serializer):
	nickname = serializers.CharField()


