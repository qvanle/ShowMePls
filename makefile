all: run

run: BUILD 
	build/ShowMePls

BUILD:
	cmake -B build/
	make -C build

.PHONY: all run
