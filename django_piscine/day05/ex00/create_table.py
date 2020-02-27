import psycopg2

if __name__ == '__main__':
    conn = psycopg2.connect(
        database='formationdjango',
        host='localhost',
        user='djangouser',
        password='secret'
    )

    curr = conn.cursor()

    curr.exute(""" CREATE TABLE IF NOT EXISTS ex00_movies (
        title varchar(64) NOT NULL,
        episode_nb PRIMARY KEY,
        opening_crawl text,
        director varchar(32) NOT NULL,
        producer varchar(128) NOT NULL,
        date date NOT NULL)
        """)
    conn.commit()
    conn.close()