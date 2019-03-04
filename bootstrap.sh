#!/usr/bin/env bash

set -e


#sudo apt-get install -y curl
#PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
#mkdir -p ${PROJECT_ROOT}/vendor
#curl https://raw.githubusercontent.com/HowardHinnant/date/master/include/date/date.h > ${PROJECT_ROOT}/vendor/date.h

unameOut="$(uname -s)"
SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

mkdir -p ${SCRIPT_DIR}/vendor/
cd ${SCRIPT_DIR}/vendor

if [[ ! -d curl ]]; then
    git clone --branch curl-7_64_0 --depth 1 https://github.com/curl/curl.git
    cd curl
    mkdir -p build && cd build
    if [[ ${unameOut} =~ CYGWIN* ]] || [[ ${unameOut} =~ MINGW* ]]; then
        cmake ..
        cmake --build . --target install
    fi
    if [[ ${unameOut} =~ Linux* ]]; then
        sudo apt-get install -y libssl-dev
        cmake ..
        sudo cmake --build . --target install
    fi
fi

cd ${SCRIPT_DIR}/vendor
