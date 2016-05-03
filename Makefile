b:
	g++ -Wall -g -lm -DDEBUG `pkg-config --cflags opencv` b.cpp `pkg-config --libs opencv` -o v


