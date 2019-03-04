#!/usr/bin/env bash

set -e


#sudo apt-get install -y curl
#PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
#mkdir -p ${PROJECT_ROOT}/vendor
#curl https://raw.githubusercontent.com/HowardHinnant/date/master/include/date/date.h > ${PROJECT_ROOT}/vendor/date.h

unameOut="$(uname -s)"
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"


if [[ ${unameOut} =~ Linux* ]]; then
    sudo apt-get install -y unzip libssl-dev libcurl4-gnutls-dev
fi

if [[ ${unameOut} =~ CYGWIN* ]] || [[ ${unameOut} =~ MINGW* ]]; then
    wget https://curl.haxx.se/download/curl-7.20.0.zip
    unzip curl-7.20.0.zip -d ~/
    cd ~/curl-7.20.0
    ./configure
    make
    make install
fi


mkdir -p ${SCRIPT_DIR}/vendor/
cd ${SCRIPT_DIR}/vendor

# ---------------------
# ---------------------

cd ${SCRIPT_DIR}/vendor
