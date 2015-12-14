UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CXX=clang++
else
	CXX=g++
endif

CXXFLAGS = -std=c++11 -Wall -Wextra 
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

bot2: main.o main_loop.o game_object.o image_loader.o setting.o setup.o ship.o config.o angle.o shot.o explosion.o
	$(CXX) *.o -o bot2 $(LDFLAGS)

main.o: *.h
main_loop.o: main_loop.h make_uniq.h setting.h 
setting.o: setting.h guid_set.h shot.h game_object.h ship.h 
setup.o: setup.h ship.h guid_set.h setting.h 
ship.o: ship.h game_object.h angle.h shot.h
shot.o: shot.h game_object.h

.Phony: run
run: bot2
	./bot2

.Phony: clean
clean: 
	rm *.o
	rm bot2
