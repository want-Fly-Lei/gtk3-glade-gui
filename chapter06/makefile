PKG_GTK3 := `pkg-config gtk+-3.0 --cflags --libs`
U_NAME := $(shell uname)  

ifeq ($(strip $(U_NAME)), Linux)
%.out:%.c
	gcc $^ -o $@ $(PKG_GTK3)
%.t:%.out
	./$^
else ifeq ($(strip $(U_NAME)), Windows)
%.exe:%.c
	gcc -w $^ -o $@ $(PKG_GTK3)
%.t:%.exe
	$^
endif
