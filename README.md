# memping
Quick and dirty Linux memory latency timer.

[![Build Status](https://travis-ci.org/heathtechnical/memping.svg?branch=master)](https://travis-ci.org/heathtechnical/memping)

Compile with:

    # gcc memping.c -o memping -lrt

Run like:

    $ ./memping -s 1024
    filled 1024 kb buffer in 0.50 ms
    filled 1024 kb buffer in 0.13 ms
    filled 1024 kb buffer in 0.13 ms
    filled 1024 kb buffer in 0.15 ms
