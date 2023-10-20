#!/bin/bash

wget -P /tmp/ https://raw.github.com/A7mdos/alx-low_level_programming/master/0x18-dynamic_libraries/nrandom.so
export LD_PRELOAD=/tmp/nrandom.so
