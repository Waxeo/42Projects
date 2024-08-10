from django.urls import path, include
from rest_framework_simplejwt.views import TokenObtainPairView, TokenRefreshView
from . import views

urlpatterns = [
	path('addfriend/', views.add_friend, name='addfriend'),
	path('login/', views.login_view, name='login'),
	path('logout/', views.logout_view, name='logout'),
	path('register/', views.register_view, name='register'),
	path('callin/', views.oauth2_login, name='oauth'),
	path('callback/', views.OauthCallbackView.as_view(), name='callback'),
	path('o/', include('oauth2_provider.urls', namespace='oauth2_provider')),
	path('get-csrf-token/', views.get_csrf_token, name='csrf_token'),
	path('token/', TokenObtainPairView.as_view(), name='token_obtain_pair'),
    path('token/refresh/', TokenRefreshView.as_view(), name='token_refresh'),
	path('profile/', views.profilView.as_view(), name='profile'),
	path('upload/', views.upload_view, name='upload'),
	path('game_end/', views.game_end_view, name='game_end'),
	path('tournament/', views.tournament_view, name='tournament'),
    path('check_2fa/', views.verify_otp_view, name='check_2fa'),
    path('ingame/', views.ingame_view, name='ingame'),
    path('not_ingame/', views.not_ingame_view, name='not_ingame'),
    path('nickname/', views.change_nickname, name='nickname'),
]