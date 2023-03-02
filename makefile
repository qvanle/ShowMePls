all: run

run: 
	find build/Makefile || make BUILD
	build/ShowMePls

BUILD:
	cmake -B build/
	make -C build

.PHONY: all run
