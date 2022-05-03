CXX = g++
CFLAGS = -std=c++14 -Wall -g

TARGET = Alyosha
OBJS=src/config/Config.cpp \
	 src/controllers/TestCtrl.cpp \
	 src/controllers/InitController.cpp \
	 src/core/Common.cpp \
	 src/core/Master.cpp \
	 src/core/Uringer.cpp \
	 src/core/Worker.cpp \
	 src/file/FileHandler.cpp \
	 src/file/Tire.cpp \
	 src/http/HttpRequest.cpp \
	 src/http/HttpResponse.cpp \
	 src/http/urldecode.cpp \
	 src/http/HttpStatus.cpp \
	 src/server/Server.cpp \
	 src/server/ControllerManager.cpp \
	 src/server/HttpController.cpp \
	 src/main.cpp

CFLAGS += -Isrc/config
CFLAGS += -Isrc/controllers
CFLAGS += -Isrc/core
CFLAGS += -Isrc/file
CFLAGS += -Isrc/http
CFLAGS += -Isrc/server
#CFLAGS += -Isrc/sql
#CFLAGS += -Isrc/server_base

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) -I $(INCLUDE) -pthread -lmysqlclient -luring

clean:
	rm -rf bin/$(OBJS) $(TARGET)