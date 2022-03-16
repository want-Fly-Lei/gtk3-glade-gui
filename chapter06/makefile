gtk := `pkg-config gtk+-3.0 --cflags --libs`
%.t:%.exe
	./$^

%.exe:%.c
	gcc -w $^ -o $@ $(gtk)