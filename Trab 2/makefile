C = gcc
STD = -std=c99
OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g -fstack-protector-all
LIBRARIES = -lm
OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c))
OBJECTS2 := $(patsubst %.c,%.o,$(wildcard *.o))

siguel: $(OBJECTS)
	$(C) $^ -o $@ $(STD) $(OPTIONS) $(LIBRARIES)
	
clean: 
	@rm $(OBJECTS2) siguel
	@echo "Limpin :)"