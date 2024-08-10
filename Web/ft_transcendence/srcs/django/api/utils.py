import os
from pathlib import Path
from oauthlib.oauth2 import BackendApplicationClient
from requests_oauthlib import OAuth2Session
from django.conf import settings
import random
from django.core.mail import send_mail

def add_to_allowed_hosts():
	client_id = os.getenv('CLIENT_ID')
	client_secret = os.getenv('CLIENT_SECRET')
	
	try:
		client = BackendApplicationClient(client_id=client_id)
		oauth = OAuth2Session(client=client)
		token = oauth.fetch_token(token_url="https://api.intra.42.fr/oauth/token", client_id=client_id, client_secret=client_secret)
		
		response = oauth.get("https://api.intra.42.fr/v2/users/abiddane/locations")
		data = response.json()
		host_name = data[0]['host']

		if host_name:
			settings.ALLOWED_HOSTS.append(host_name)
	except Exception as e:
		print(f"Error fetching OAuth token or host information: {e}")


def generate_otp():
    return ''.join(random.choices('0123456789', k=6))

def send_otp_email(email, otp):
    subject = 'Your OTP Code'
    message = f'Your OTP code is {otp}.'
    from_email = 'no.replyy.4242@gmail.com'
    recipient_list = [email]
    send_mail(subject, message, from_email, recipient_list)
