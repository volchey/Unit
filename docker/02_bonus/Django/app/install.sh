brew install postgresql

pg_ctl start
psql -d postgres
CREATE DATABASE formationdjango;
CREATE USER djangouser WITH PASSWORD 'secret';
ALTER DATABASE formationdjango OWNER TO djangouser;
GRANT ALL ON DATABASE formationdjango TO djangouser