FROM ubuntu:latest

USER root

COPY ./ /home
#COPY /include/ /usr/local/include/

#RUN cd ApplicationServer
RUN chmod +x /home/installdocker.sh
RUN ./home/installdocker.sh

#RUN apt-get update
#RUN apt-get -y install    clang-${LLVM_VERSION} \

#RUN apt-get update && apt-get install -y \

#    clang-${LLVM_VERSION} \
#    cmake \
#    cmake-curses-gui \
#    gcc \
#    g++ \
#    libcppunit-dev \
#    libmongoc-1.0-0 \
#    pkg-config\
#    libssl-dev\
#    libsasl2-dev \
#     gdb 

#RUN apt-get -y upgrade

# Establece el autor (maintainer) del archivo (tu nombre - el autor del archivo)
MAINTAINER Nicolas Alvarez

# Puerto para exponer (por defecto: 11211)
EXPOSE 11211

RUN mkdir /home/build && cd /home/build/ && cmake .. && make

ENV LD_LIBRARY_PATH=/libs

ENV CPATH=/usr/include/c++/4.9:$CPATH

ENV CPLUS_INCLUDE_PATH=/libs/include

WORKDIR /home/build

CMD ["/bin/bash" , "./ApplicationServer" , "0.0.0.0"]

