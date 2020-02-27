from django.db import models
from django import forms

class MyForm(forms.Form):
    name = forms.CharField(max_length=64)
    password = forms.CharField(max_length=64, widget = forms.PasswordInput)
