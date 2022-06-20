PREFIX := /usr/local
SRC := src/*.cpp src/util/*.cpp src/actors/*.cpp src/items/*.cpp
CXXFLAGS := -std=c++17 -Iactors -Iitems -lncurses -Wall -Wextra -pedantic

all: options anyage

options:
	@echo anyage build options:
	@echo "LDFLAGS    = ${LDFLAGS}"
	@echo "CXXFLAGS   = ${CXXFLAGS}"
	@echo "CXX        = ${CXX}"

anyage: ${SRC}
	${CXX} -o bin/$@ $? ${CXXFLAGS}

run: all
	bin/anyage
	rm -f bin/anyage

debug: ${SRC}
	time { ${CXX} -g -o bin/$@ $? ${CXXFLAGS}; }

clean:
	rm -f bin/*

install: all
	cp bin/anyage ${PREFIX}/bin

.PHONY: clean install debug run ncurses options all
