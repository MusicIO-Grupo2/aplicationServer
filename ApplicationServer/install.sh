#!/bin/bash

root_dir=`pwd`
mkdir $root_dir/temp_install
install_dir="$root_dir/temp_install"


# Remove old libraries, ensure use right versions
echo "Search and remove old libs"
    find / -type f -name "libjsoncpp.a" -exec rm {} \;
    find / -type f -name "libgtest.a" -exec rm --force {} \;
    find / -type f -name "libgtest_main.a" -exec rm --force {} \;
    find / -type f -name "libgtest.so" -exec rm --force {} \;
    find / -type f -name "libgtest_main.so" -exec rm --force {} \;
echo "Search end"

# Instalación de dependencias y herramientas
echo "Installing tools and dependencies"
apt-get update
apt-get install -y --assume-yes --force-yes  libsnappy-dev zlib1g-dev libbz2-dev libgflags-dev cmake libcppunit-doc libcppunit-dev lcov libboost-all-dev libssl-dev git

## Instala las librerías
echo "Installing libraries"
apt-get install -y wget
mkdir -p temp_install && \
cd temp_install && \

echo "MONGO DRIVER 1.6.2"
apt-get install -y pkg-config libssl-dev libsasl2-dev
wget https://github.com/mongodb/mongo-c-driver/releases/download/1.6.2/mongo-c-driver-1.6.2.tar.gz
tar xzf mongo-c-driver-1.6.2.tar.gz
cd mongo-c-driver-1.6.2
./configure --disable-automatic-init-and-cleanup

echo "libbson"

make
sudo make install

echo "fin libbson"

apt-get install sudo
sudo apt-get install curl
echo "OK CURL"
sudo apt-get install zip unzip
echo "OK UNZIP"


curl -OL https://github.com/mongodb/mongo-cxx-driver/archive/r3.1.1.tar.gz
tar -xzf r3.1.1.tar.gz
cd mongo-cxx-driver-r3.1.1/build
echo "making mongo driver"
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
sudo make EP_mnmlstc_core
make && sudo make install


#curl -OL https://github.com/mongodb/mongo-cxx-driver/archive/r3.0.2.tar.gz
#tar -xzf r3.0.2.tar.gz
#cd mongo-cxx-driver-r3.0.2/build
#cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
#sudo make EP_mnmlstc_core
#make && sudo make install



cd $install_dir
echo "Installing jsoncpp"
wget https://github.com/open-source-parsers/jsoncpp/archive/0.y.z.zip && \
unzip 0.y.z.zip && \
cd jsoncpp-0.y.z && \
python amalgamate.py && \
cd dist && \
gcc -c jsoncpp.cpp && \
ar rvs libjsoncpp.a jsoncpp.o && \
sudo cp libjsoncpp.a /usr/lib && \


cd $install_dir
# Last release does not have cmake enabled, so we install it from master.
echo "Installing mongose-cpp"
wget https://github.com/Gregwar/mongoose-cpp/archive/master.zip && \
unzip master.zip && \
rm master.zip && \
cd mongoose-cpp-master && \
cmake . && \
make install && \


cd $root_dir
rm -rf temp_install

echo "Make and install"
mkdir -p build && cd build && \
cmake .. && make
