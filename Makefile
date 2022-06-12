SOURCE := src/Game.cpp  \
					src/main.cpp

goblin-quest: ${SOURCE}
	${CXX} -o $@ $? -std=c++11
