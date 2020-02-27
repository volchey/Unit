from django.conf.urls import url
from ex00.views import MyImages
from django.urls import path

urlpatterns = [
    url(r'', MyImages.as_view(), name='my_images'),
]