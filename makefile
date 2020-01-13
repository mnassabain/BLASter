# ne pas oublier de mkdir bin/ pcq git le regarde pas

TARGET = blaster

all:
	cd src/ && make final_target
	mv src/$(TARGET) ./$(TARGET)

test-ast:
	./$(TARGET) src/test.c src/spec.c -a -o output.output

test-lvl0:
	./$(TARGET) src/level0.c src/nospec.c -a

test-lvl1:
	./$(TARGET) src/level1.c src/nospec.c -a

test-tds:
	./$(TARGET) src/test.c src/nospec.c -t 

clean:
	cd src/ && make clean
	rm -f $(TARGET)


