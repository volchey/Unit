from django.shortcuts import render

import psycopg2


def ex00(request):
    conn = psycopg2.connect(
        database='formationdjango',
        host='localhost',
        user='djangouser',
        password='secret'
    )

    result = "OK"
    curr = conn.cursor()
    try:
        curr.execute(""" CREATE TABLE IF NOT EXISTS ex00_movies (
            title varchar(64) NOT NULL,
            episode_nb integer PRIMARY KEY,
            opening_crawl text,
            director varchar(32) NOT NULL,
            producer varchar(128) NOT NULL,
            date date NOT NULL)
            """)

        conn.commit()
        conn.close()
    except Exception as e:
        result = e

    return render(request, "ex00/index.html", {'result': result})