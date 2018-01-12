###########
#
# Makefile
#
###########

CC = gcc
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = monitall
DEBUG = yes
CFLAGS = -Wall -O2 -Os
INC = -I/usr/include


ifeq ($(DEBUG), yes)
	CFLAGS += -ggdb -DDEBUG
endif

$(TARGET) : $(OBJS)
	$(CC) $^ -o $@

# Objects files
%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Direttive phony
.PHONY: clean

# pulizia progetto ($(RM) è di default "rm -f")
clean:
	$(RM) $(OBJS) $(TARGET)

