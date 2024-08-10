#!/bin/bash

# Wait for PostgreSQL to be ready
while ! nc -z -w 2 $DB_HOST $DB_PORT; do
    echo "Postgres isn't up...waiting..."
    sleep 2
done

echo "Postgres is up!"

cd /django

# Run Django migrations
python manage.py makemigrations
python manage.py migrate

# Start Django server
python manage.py runserver 0.0.0.0:8000

