CC=g++
CFLAGS=-std=c++11 -Wall
TARGET = a.out

ifdef DEBUG
	CFLAGS += -g
endif

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include

${BUILD_DIR}/${TARGET}: ${BUILD_DIR}/main.o ${BUILD_DIR}/mmc.o ${BUILD_DIR}/mdc.o
	${CC} ${CFLAGS} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/${TARGET}

${BUILD_DIR}/main.o : ${SRC_DIR}/main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o

${BUILD_DIR}/mmc.o : ${INCLUDE_DIR}/mmc.hpp ${SRC_DIR}/mmc.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/mmc.cpp -o ${BUILD_DIR}/mmc.o

${BUILD_DIR}/mdc.o : ${INCLUDE_DIR}/mdc.hpp ${SRC_DIR}/mdc.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR} -c ${SRC_DIR}/mdc.cpp -o ${BUILD_DIR}/mdc.o

clear:
	rm ${BUILD_DIR}/*