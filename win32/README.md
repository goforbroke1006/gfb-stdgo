# Installation on Windows

You need CygWIN and CMake

* Download https://curl.haxx.se/download/curl-7.20.0.zip
* Unzip to /c/some-folder/
* Go to /c/some-folder/curl-7.20.0 via CygWIN terminal
* Execute commands

        ./configure
        make
        make install

* And now you can prepare project

        cmake -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles" /cygdrive/c/Users/1/CLionProjects/gfb-stdgo

