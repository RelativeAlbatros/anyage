PREFIX := /usr/local
SRC := src/*.cpp

all: options anyage

options:
	@echo anyage build options:
	@echo "LDFLAGS    = ${LDFLAGS}"
	@echo "CXXFLAGS   = ${CFLAGS}"
	@echo "CXX        = ${CXX}"

anyage: ${SRC}
	${CXX} -o bin/$@ $? -std=c++11 -lncurses

debug: ${SRC}
	time { ${CXX} -g -o bin/$@ $? -std=c++11 -lncurses; }

clean:
	rm -f bin/*

install: all
	cp bin/anyage ${PREFIX}/bin
