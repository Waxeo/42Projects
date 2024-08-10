from django.apps import AppConfig
from .utils import add_to_allowed_hosts

class ApiConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'api'

    def ready(self):
        add_to_allowed_hosts()
