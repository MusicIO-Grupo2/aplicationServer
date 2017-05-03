#############################################################
# Archivo Dockerfile para ejecutar Application Server
# Basado en una imagen de Ubuntu
#############################################################

# Base image
FROM ubuntu:14.04

# Copio los directorios del repositorio
COPY ./ /home

# Set Locale otherwise some applications may behave strangely when
# the encoding looks like ANSI_X3.4-1968
RUN locale-gen en_GB.UTF-8
ENV LANG=en_GB.UTF-8 \
    LANGUAGE=en_GB:en \
    LC_ALL=en_GB.UTF-8

RUN apt-get update && apt-get -y install wget

RUN apt-get -y --no-install-recommends install \
  build-essential \
  clang-${LLVM_VERSION} \
  cmake \
  cmake-curses-gui \
  gcc \
  g++ \
  gdb \
  git-core \
  htop \
  mercurial \
  ncdu \
  ninja-build \
  python \
  python-dev \
  python-pip \
  subversion \
  tmux \
  tree \
  unzip \
  vim

# Establece el autor (maintainer) del archivo (tu nombre - el autor del archivo)
MAINTAINER Nicolas Alvarez

# Puerto para exponer (por defecto: 11211)
EXPOSE 11211

COPY ./ /home


RUN mkdir /home/build && cd /home/build/ && cmake .. && make

ENV LD_LIBRARY_PATH=/libs

ENV CPATH=/usr/include/c++/4.9:$CPATH

ENV CPLUS_INCLUDE_PATH=/libs/include

WORKDIR /home/build

CMD ["bash" , "./ApplicationServer"]
