from django.db import models
from django.contrib.auth.models import AbstractUser

class User(AbstractUser):
	nickname = models.CharField(max_length=20)
	email = models.EmailField(unique=True)
	friends = models.ManyToManyField("self")
	profil_image = models.ImageField(upload_to='profile_images/', default='profile_images/default.png')
	online = models.BooleanField(default=False)
	ingame = models.BooleanField(default=False)
	is_oauth = models.BooleanField(default=False)
	is_2fa = models.BooleanField(default=False)
	otp_code = models.CharField(max_length=6, blank=True, null=True)


class Stat(models.Model):
	user = models.OneToOneField(User, on_delete=models.CASCADE, related_name='stat')
	number_of_game = models.PositiveIntegerField(default=0)
	number_of_win = models.PositiveIntegerField(default=0)
	number_of_defeat = models.PositiveIntegerField(default=0)
	win_percentage = models.PositiveSmallIntegerField(default=0)

class Game(models.Model):
	user = models.ForeignKey(User, on_delete=models.CASCADE, related_name='games')
	win = models.BooleanField(blank=True, null=True)
	opponent = models.CharField(blank=True, null=True)
	my_score = models.PositiveSmallIntegerField(blank=True, null=True)
	opponent_score = models.PositiveSmallIntegerField(blank=True, null=True)
	date = models.DateField(auto_now_add=True)