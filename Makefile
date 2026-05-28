CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

RAYLIB_PATH = ./raylib-5.5_linux_amd64

INCLUDES = -I$(RAYLIB_PATH)/include -I./include
LIBS = -L$(RAYLIB_PATH)/lib -lraylib \
-Wl,-rpath=$(RAYLIB_PATH)/lib \
-lGL -lm -lpthread -ldl -lrt -lX11

SRC = src/main.cpp
OUT = game

all:
	$(CXX) $(SRC) $(CXXFLAGS) $(INCLUDES) $(LIBS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)