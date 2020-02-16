from django.db import models
from django import forms

class MyImage(models.Model):
    title = models.CharField(max_length=64)
    img   = models.ImageField(upload_to ='files') 

    def __str__(self):
        return self.title

class MyForm(forms.ModelForm):
    # title = forms.CharField(max_length=64)
    # img   = forms.ImageField()
    class Meta:
        model = MyImage
        fields = ['title', 'img']

