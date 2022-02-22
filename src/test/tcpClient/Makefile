CXX = g++
CFLAGS = -std=c++14 -Wall -g

TARGET = client
OBJS=*.cpp

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET)  -pthread -lmysqlclient -luring

clean:
	rm -rf bin/$(OBJS) $(TARGET)