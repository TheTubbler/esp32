#!/bin/bash

read -p "Install esp32-idf to $(pwd)/esp-idf/? [y/N] " YN
case $YN in
	[Yy]* ) git clone --recursive https://github.com/espressif/esp-idf.git ;;
	* ) ;;
esac
