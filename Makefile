cmsh:
	gcc src/main.c -o bin/cmsh -I src/include

clean:
	rm bin/cmsh

run:
	make
	./bin/cmsh