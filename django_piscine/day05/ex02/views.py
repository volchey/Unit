from django.shortcuts import render
import psycopg2

# Create your views here.
def init(request):
    conn = 0
    try :
        conn = psycopg2.connect(
            database = 'formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except:
        result = "I am unable to connect to the database."
        print(result)
    curr = conn.cursor()
    try:
        curr.execute("""CREATE TABLE IF NOT EXISTS ex02_movies (
        episode_nb serial PRIMARY KEY,
        title VARCHAR(64) UNIQUE NOT NULL,
        opening_crawl TEXT ,
        director VARCHAR(32) NOT NULL,
        producer VARCHAR(128) NOT NULL,
        release_date DATE NOT NULL
        );
        """)
        conn.commit()
        conn.close()
        result = 'Ok'
    except psycopg2.DatabaseError as e:
        print(e)
        result = e

    return render(request, 'ex02/init.html', {'result': result})

def populate(request):
    conn = 0
    result = list()

    column_names = ("episode_nb", "title", "director", "producer", "release_date")
    
    data = {
        ('1', 'The Phantom Menace', 'George Lucas', 'Rick McCallum', '1999-05-19'),
        ('2', 'Attack of the Clones', 'George Lucas', 'Rick McCallum',  '2002-05-16'),
        ('3', 'Revenge of the Sith', 'George Lucas', 'Rick McCallum', '2005-05-19'),
        ('4', 'A New Hope', 'George Lucas', 'Gary Kurtz, Rick McCallum',  '1977-05-25'),
        ('5', 'The Empire Strikes Back', 'Irvin Kershner', 'Gary Kutz, Rick McCallum', '1980-05-17'),
        ('6', 'Return of the Jedi', 'Richard Marquand', 'Howard G. Kazanjian, George Lucas, Rick McCallum', '1983-05-25'),
        ('7', 'The Force Awakens', 'J. J. Abrams', 'Kathleen Kennedy, J. J. Abrams, Bryan Burk', '2015-12-11')
    }

    try:
        conn = psycopg2.connect(
            database='formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except:
        result = "Unable to connect to the database."
        print(result)

    curr = conn.cursor()
    for params in data:
        query = "INSERT INTO ex02_movies(%s , %s, %s, %s, %s) VALUES " % column_names
        query += "(" + params[0] + ',' + ','.join("'" + item + "'" for item in params[1:]) + ")"
        
        try:
            curr.execute(query)
            conn.commit()
            result.append('Ok')
        except psycopg2.DatabaseError as e:
            print(e)
            result.append(params[1])
            result.append(e)

    return render(request, 'ex02/populate.html', {'result': result})

def display(request):
    conn = 0
    result = list()
    try:
        conn = psycopg2.connect(
            database='formationdjango',
            host='localhost',
            user='djangouser',
            password='secret',
        )
    except:
        result = "Unable to connect to the database."
        print(result)
    curr = conn.cursor()
    try:
        curr.execute("""SELECT * FROM ex02_movies""")
        table = curr.fetchall()
        conn.close()
    except psycopg2.DatabaseError as e:
        table = 0
        print(e)
    return render(request, 'ex02/display.html', {'table':table})
