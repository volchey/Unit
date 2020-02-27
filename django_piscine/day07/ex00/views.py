from django.shortcuts import HttpResponse, render, redirect, HttpResponseRedirect, reverse
from django.views.generic import ListView, FormView, RedirectView, DetailView, TemplateView
from django.contrib.auth.forms import AuthenticationForm
from .models import Article, UserFavouriteArticle, MyForm
from django.contrib.auth.models import User
from django.contrib.auth.decorators import login_required
from django.contrib.auth import authenticate, login, logout

class Articles(ListView):
    model = Article
    template_name = 'ex00/articles.html'

class LoginForm(FormView):
    form_class = MyForm
    template_name = 'ex00/login.html'
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
            return HttpResponseRedirect(reverse('home'))
        return render(request, self.template_name, {'form':form})


class MyLogout(RedirectView):
    def get(self, request):
        logout(request)
        return redirect('../')

class Home(RedirectView):
    url = '/articles'

class Favorites(ListView):
    context_object_name='object_list'
    def get_queryset(self, **kwargs):
        if self.request.user.is_authenticated:
            print(self.request.user)
            return UserFavouriteArticle.objects.filter(user=self.request.user)
        return UserFavouriteArticle.objects.none
    template_name = 'ex00/favorites.html'

class Publications(ListView):
    context_object_name='object_list'
    def get_queryset(self, **kwargs):
        if self.request.user.is_authenticated:
            print(self.request.user)
            return Article.objects.filter(author=self.request.user)
        return Article.objects.none
    template_name = 'ex00/publications.html'

class Detail(DetailView):
    model = Article

    template_name = 'ex00/detail.html'