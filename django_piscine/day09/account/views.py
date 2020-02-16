from django.shortcuts import HttpResponse, render, redirect, HttpResponseRedirect, reverse
from django.contrib.auth import authenticate, login, logout
from django.views.generic import FormView, RedirectView, TemplateView
from django.contrib.auth.forms import AuthenticationForm
from .models import MyForm
from django.views.decorators.csrf import csrf_exempt


class LoginForm(FormView):
    form_class = MyForm
    template_name = 'account/login.html'
    success_url = "/"

    def post(self, request, *args, **kwargs):
        print('post')
        form = MyForm(request.POST)
        if not form.is_valid():
            return render(request, self.template_name, {'form':form})
        username = form.cleaned_data.get('name')
        password = form.cleaned_data.get('password')

        print(username)
        user = authenticate(request, username=username, password=password)
        if user:
            login(request, user)
            return self.get(request)
        return render(request, self.template_name, {'form':form})

    def get(self, request):
        form = MyForm(request.POST)
        if self.request.user.is_authenticated:
            user = self.request.user
            print(user)
            return render(request, 'account/logged_user.html', {'user':user})
        return render(request, self.template_name, {'form':form})

@csrf_exempt
def my_logout(request):
    print('logout')
    logout(request)
    return redirect('/account')