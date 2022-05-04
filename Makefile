CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_BIN = ./bin/
CC = gcc
TARGET = chessviz

SRC = $(wildcard $(PREF_SRC)*/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
POST_OBJ = $(patsubst ./%.c, $(PREF_OBJ)%.o, $(SRC))
STATIC = ./obj/libchessviz/static.a

$(PREF_BIN)$(TARGET) : $(OBJ) $(STATIC)
	$(CC) $(CFLAGS) $(POST_OBJ) -o $(PREF_BIN)$(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(PREF_SRC) -c $< -o $(PREF_OBJ)$@

-include %.d

$(STATIC) : %.o
	ar rcs $@ $^


.PHONY: clean
clean : 
	rm $(POST_OBJ) $(PREF_BIN)$(TARGET) $(PREF_OBJ)*/*/*.d
	

