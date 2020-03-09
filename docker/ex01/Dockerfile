FROM debian

MAINTAINER vchechai <vchechai@student.unit.ua>

ENV TS3SERVER_LICENSE=accept

EXPOSE 9987/udp 10011 30033

RUN apt-get update && \
    apt-get -y upgrade && \
    apt install -y wget bzip2

RUN wget http://dl.4players.de/ts/releases/3.0.12.4/teamspeak3-server_linux_amd64-3.0.12.4.tar.bz2 && \
    tar -jxvf teamspeak3-server_linux_amd*.tar.bz2

ENTRYPOINT sh teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh