# memping
Quick and dirty Linux memory latency timer.

Compile with:

    # gcc memping.c -o memping -lrt

Run like:

    $ ./memping -s 1024
    filled 1024 kb buffer in 0.50 ms
    filled 1024 kb buffer in 0.13 ms
    filled 1024 kb buffer in 0.13 ms
    filled 1024 kb buffer in 0.15 ms
