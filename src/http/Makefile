CXX = g++
CFLAGS = -std=c++14 -Wall -g

TARGET = Alyosha
OBJS=../../src/core/Common.cpp \
	 ../../src/core/Master.cpp \
	 ../../src/core/Uringer.cpp \
	 ../../src/core/Worker.cpp \
	 ../../src/http/FileHandler.cpp \
	 ../../src/http/HttpHandler.cpp \
	 ../../src/http/HttpStatus.cpp \
	 ../../src/http/Tire.cpp \
	 main.cpp

CFLAGS += -I../core
CFLAGS += -I../http

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) -I $(INCLUDE) -pthread -lmysqlclient -luring

clean:
	rm -rf bin/$(OBJS) $(TARGET)