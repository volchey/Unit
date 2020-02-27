from django.shortcuts import render
from .models import Movies
from django.db import IntegrityError

def populate(request):

    data = {
        1 : ('The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
        2 : ('Attack of the Clones', 'George Lucas', 'Rick McCallum',  '2002-05-16'),
        3 : ('Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
        4 : ('A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum',  '1977-05-25'),
        5 : ('The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'),
        6 : ('Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'),
        7 : ('The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
    }

    result = list()
    for key, params in data.items():        
        try:
            mov1 = Movies(episode_nb=key, title=params[0], director=params[1], producer=params[2], release_date=params[3])
            mov1.save()
            result.append('Ok')
        except IntegrityError as e:
            result.append(params[0])
            result.append(e)

    return render(request, 'ex03/populate.html', {'result': result})

def display(request):
    table = Movies.objects.all()
    print (table)
    return render(request, 'ex03/display.html', {"table":table})

