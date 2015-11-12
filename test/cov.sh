#!/bin/bash

lcov --directory . --zerocounters
./test
lcov --directory . --capture --output-file tuvieja.info
lcov --remove tuvieja.info '/test/*' '/usr/*' '/gtest/*' --output-file tuvieja.info
lcov --list tuvieja.info
