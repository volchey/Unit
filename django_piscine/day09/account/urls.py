from django.conf.urls import url
from account.views import LoginForm
from django.urls import path
from . import views

urlpatterns = [
    url(r'^account', LoginForm.as_view(), name='account'),
    url(r'^logout', views.my_logout, name='logout'),
]