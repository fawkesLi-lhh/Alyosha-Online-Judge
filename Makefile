CXX = g++
CFLAGS = -std=c++14 -Wall -g

TARGET = Alyosha
OBJS=src/core/Common.cpp \
	 src/core/Master.cpp \
	 src/core/Uringer.cpp \
	 src/core/Worker.cpp \
	 src/http/FileHandler.cpp \
	 src/http/HttpHandler.cpp \
	 src/http/HttpStatus.cpp \
	 src/http/Tire.cpp \
	 src/config/Config.cpp \
	 src/sql/MysqlPool.cpp \
	 src/server_base/BaseServer.cpp \
	 src/server_base/Request.cpp \
	 src/server_base/Response.cpp \
	 src/server_base/urldecode.cpp \
	 src/server_base/ServerManager.cpp \
	 src/server/ServerInit.cpp \
	 src/server/LoginServer.cpp \
	 src/server/SubmitServer.cpp \
	 src/main.cpp

CFLAGS += -Isrc/core
CFLAGS += -Isrc/http
CFLAGS += -Isrc/config
CFLAGS += -Isrc/sql
CFLAGS += -Isrc/server_base
CFLAGS += -Isrc/server

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(TARGET) -I $(INCLUDE) -pthread -lmysqlclient -luring

clean:
	rm -rf bin/$(OBJS) $(TARGET)