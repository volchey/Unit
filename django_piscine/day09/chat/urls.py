from django.urls import path
from chat.views import LoginForm, MyLogout
from . import views

urlpatterns = [
    # path('', views.index, name='index'),
    path('', LoginForm.as_view(), name='index'),
    path('logout/', MyLogout.as_view(), name='logout'),
    path('<str:room_name>/', views.room, name='room-detail'),
]