var:=$(patsubst %.c, %.o, $(wildcard *.c))
calc.out:$(var)
	gcc -o calc.out $(var)
clean:
	rm *.out *.o