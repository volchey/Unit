FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    # python3-venv \
    python-pip \
    libpq-dev

COPY ./requirements.txt /

RUN \
    python -m pip install -r /requirements.txt
    # python3 -m venv env && /bin/bash -c "source env/bin/activate" \