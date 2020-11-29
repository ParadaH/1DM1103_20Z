DEPS = main.o operacje.o calculate.o

main: $(DEPS)
	gcc $(DEPS) -o $@ -Wall -pedantic -lm

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -f main
	rm -f *.o

# test: zad6
