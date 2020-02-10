from django.conf.urls import url
from . import views

urlpatterns = [
    url(r'^populate', views.populate, name='populate'),
    url(r'^display', views.display, name='display'),
]