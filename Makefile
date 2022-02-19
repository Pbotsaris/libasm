LIB_FOLDER=lib
OBJ_FOLDER=obj
SRC_FOLDER=src
BIN_FOLDER=bin

CC=gcc
ASM=nasm
CFLAGS += -m64 -g3
ASMFLAGS += -felf64

TARGET=$(BIN_FOLDER)/main
RM=rm -rf

$(shell mkdir -p obj bin)


LIBS=$(wildcard $(LIB_FOLDER)/*.asm)
OBJS=$(patsubst $(LIB_FOLDER)/%.asm, $(OBJ_FOLDER)/%.o, $(LIBS))
SRCS=src/main.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(SRC_FOLDER)/main.c $(CFLAGS) -o $(BIN_FOLDER)/main

$(OBJ_FOLDER)/%.o:$(LIB_FOLDER)/%.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	$(RM) $(TARGET) $(BIN)/*.dSYM $(OBJ)/*.o 

.PHONY:
	all clean
