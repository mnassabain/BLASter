# ne pas oublier de mkdir bin/ pcq git le regarde pas

TARGET = blaster

all:
	cd src/ && make final_target
	mv src/blaster ./blaster

test-ast:
	./blaster src/test.c src/spec.c -a -o output.output

test-lvl0:
	./blaster src/level0.c src/nospec.c -a

test-lvl1:
	./blaster src/level1.c src/nospec.c -a

clean:
	cd src/ && make clean
	rm -f blaster
