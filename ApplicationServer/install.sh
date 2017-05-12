#!/bin/bash

root_dir=`pwd`
install_dir="$root_dir/temp_install"

# Remove old libraries, ensure use right versions
echo "Search and remove old libs"
    find / -type f -name "librocksdb.a" -exec rm {} \;
    find / -type f -name "libjsoncpp.a" -exec rm {} \;
    find / -type f -name "libgtest.a" -exec rm --force {} \;
    find / -type f -name "libgtest_main.a" -exec rm --force {} \;
    find / -type f -name "libgtest.so" -exec rm --force {} \;
    find / -type f -name "libgtest_main.so" -exec rm --force {} \;
echo "Search end"

# Instalación de dependencias y herramientas
echo "Installing tools and dependencies"
apt-get update
apt-get install -y --assume-yes --force-yes libsnappy-dev zlib1g-dev libbz2-dev libgflags-dev cmake libcppunit-doc libcppunit-dev lcov libboost-all-dev libssl-dev git

## Instala las librerías
echo "Installing libraries"
apt-get install -y wget
mkdir -p temp_install && \
cd temp_install && \


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


mv /usr/local/include/bsoncxx/v_noabi/ /usr/local/include/bsoncxx
mv /usr/local/include/mongocxx/v_noabi/ /usr/local/include/mongocxx

echo "Make and install"
mkdir -p build && cd build && \
cmake .. && make
