#!/usr/bin/env bash

set -e


#sudo apt-get install -y curl
#PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
#mkdir -p ${PROJECT_ROOT}/vendor
#curl https://raw.githubusercontent.com/HowardHinnant/date/master/include/date/date.h > ${PROJECT_ROOT}/vendor/date.h



sudo apt-get update
sudo apt-get install -y libcurl4-gnutls-dev

