# Compiler
CXX = g++
CFLAGS = -Wall
LDFLAGS = -lSDL2

# Files
SOURCES = test.c window.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = test

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.c
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
