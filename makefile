# ne pas oublier de mkdir bin/ pcq git le regarde pas

TARGET = blaster

all:
	cd src/ && make final_target

clean:
	cd src/ && make clean