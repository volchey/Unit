from django.conf.urls import url
from ex00.views import Articles, LoginForm, Home, Publications, Detail, MyLogout, Favorites
from django.urls import path

urlpatterns = [
    url(r'^articles', Articles.as_view(), name='articles'),
    url(r'^login', LoginForm.as_view(), name='login'),
    url(r'^logout', MyLogout.as_view(), name='logout'),
    url(r'^publications', Publications.as_view(), name='publications'),
    url(r'^favorites', Favorites.as_view(), name='favorites'),
    path('article/<int:pk>/', Detail.as_view(), name='article-detail'),
    url(r'^', Home.as_view(), name='home'),
]