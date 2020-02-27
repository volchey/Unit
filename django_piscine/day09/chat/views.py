from django.shortcuts import HttpResponse, render, redirect, HttpResponseRedirect, reverse
from django.views.generic import FormView, RedirectView
from .models import MyForm, Rooms
from django.contrib.auth import authenticate, login, logout


def index(request):
    rooms = Rooms.objects.all()
    return render(request, 'chat/index.html', {
        'rooms': rooms
        })

def room(request, room_name):
    return render(request, 'chat/room.html', {
        'room_name': room_name
    })

class LoginForm(FormView):
    form_class = MyForm
    template_name = 'chat/login.html'
    success_url = "/"
    def post(self, request, *args, **kwargs):
        form = MyForm(request.POST)
        if not form.is_valid():
            return render(request, self.template_name, {'form':form})
        username = form.cleaned_data.get('name')
        password = form.cleaned_data.get('password')

        print(username)
        user = authenticate(request, username=username, password=password)
        if user:
            login(request, user)
            print('return index')
            return index(request)
        return render(request, self.template_name, {'form':form})

    def get(self, request):
        form = MyForm(request.POST)
        if self.request.user.is_authenticated:
            return index(request)
        return render(request, self.template_name, {'form':form})
        
class MyLogout(RedirectView):
    def get(self, request):
        logout(request)
        return redirect('/chat')