CXX = g++

CXXFLAGS = -Wall -framework OpenGL -framework GLUT -Wno-deprecated

SOURCES = $(shell find . -name '*.cpp')
HEADERS = $(shell find . -name '*.h')

OUTPUT = mario

all: $(OUTPUT) run

$(OUTPUT): $(SOURCES) $(HEADERS)
	$(CXX) -o $(OUTPUT) $(SOURCES) $(CXXFLAGS)

clean:
	$(RM) $(OUTPUT)

run:
	./$(OUTPUT)