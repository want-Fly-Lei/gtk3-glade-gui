U_NAME := $(shell uname)

ifeq ($(strip $(U_NAME)), Linux)
%.out:%.c
	gcc $^ -o $@
%.t:%.out
	./$^
else ifeq ($(strip $(U_NAME)), Windows)
%.exe:%.c
	gcc -w $^ -o $@
%.t:%.exe
	$^
endif
