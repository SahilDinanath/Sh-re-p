BINARY=main
#Directories of C files
CODEDIRS=. ./RegexEngine
#Directories of Header files
INCDIRS=. ./RegexEngine/

CC=gcc
OPTS=-O0
DEPS=-MP -MD
#for each header directory, tell $(CC) to include it
CFLAGS=-Wall -Wextra -pedantic -g $(foreach D, $(INCDIRS), -I$(D)) $(OPTS) $(DEPS)

#find all the .c files by searching the directories listed in $(CODEDIRS) 
CFILES=$(foreach D, $(CODEDIRS), $(wildcard $(D)/*.c))
#Take in each *.c file and replace .c with .o 
OBJECTS=$(patsubst %.c, %.o, $(CFILES))
DEPFILES=$(patsubst %.c, %.d, $(CFILES))

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(BINARY) $(DEPFILES)

-include $(DEPFILES)

test: all
	@./main "char" main.c
.PHONY: clean all


