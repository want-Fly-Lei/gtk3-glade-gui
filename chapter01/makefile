U_NAME := $(shell uname)  

ifeq ($(strip $(U_NAME)), Linux)  
test.out:test.c
	gcc test.c -o test.out `pkg-config gtk+-3.0 --cflags --libs`
else ifeq ($(strip $(U_NAME)), Windows)
test.exe:test.c
	gcc -Wall test.c -o test.exe `pkg-config gtk+-3.0 --cflags --libs`
endif
