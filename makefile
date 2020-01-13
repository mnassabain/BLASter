# ne pas oublier de mkdir bin/ pcq git le regarde pas

TARGET = blaster

all:
	cd src/ && make final_target
	mv src/blaster ./blaster

test-ast:
	./blaster src/test.c src/spec.c -a -o output.output

clean:
	cd src/ && make clean
	rm -f blaster