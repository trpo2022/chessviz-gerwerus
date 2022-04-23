CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_BIN = ./bin/
PREF_TEST = ./test/
PREF_LIB = ./src/libchessviz/

CC = gcc
TARGET = chessviz
TEST_TARGET = chessviz_test

TEST = $(wildcard $(PREF_TEST)*.c)
TEST_OBJ = $(patsubst %.c, %.o, $(TEST))
POST_TEST = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(TEST))

SRC = $(wildcard $(PREF_SRC)*/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
POST_OBJ = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(SRC))

LIB = $(wildcard $(PREF_LIB)*.c)
LIB_OBJ = $(patsubst %.c, %.o, $(LIB))
POST_LIB = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(LIB))

all : $(PREF_BIN)$(TARGET)

$(PREF_BIN)$(TARGET) : $(OBJ)
	$(CC) $(CFLAGS) $(POST_OBJ) -o $(PREF_BIN)$(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(PREF_SRC) -c $< -o $(PREF_OBJ)$@

-include %.d

.PHONY: test
test : $(TEST_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(PREF_SRC) $(POST_LIB) $(POST_TEST) -o $(PREF_BIN)$(TEST_TARGET)
