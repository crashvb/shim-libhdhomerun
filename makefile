#!/usr/bin/make -f

default: build

build: shim_libhdhomerun.so test.out test

shim_libhdhomerun.so: shim_libhdhomerun.c
	gcc -Wall -O2 -fpic -shared -o shim_libhdhomerun.so shim_libhdhomerun.c -ldl

test.out: test.c
	gcc -Wall -O2 -o test.out test.c -lhdhomerun

test: shim_libhdhomerun.so test.out
	LD_PRELOAD=./shim_libhdhomerun.so SHIM_LIBHDHOMERUN_ADDR=192.168.0.1 ./test.out

clean:
	rm --force shim_libhdhomerun.so test.out
