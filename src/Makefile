# Compiler
CXX = g++
CFLAGS = -Wall
LDFLAGS = -lSDL2

# Files
SOURCES = test.cpp window.c
OBJECTS = $(SOURCES:.cpp=.o) $(SOURCES:.c=.o)
EXECUTABLE = test

# Targets
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $@

%.o: %.cpp %.c
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
