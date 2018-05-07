TARGET := game
SOURCES := test-sfml.cpp
LIBS := -lsfml-graphics -lsfml-window -lsfml-system
all:
	g++ -o $(TARGET) $(SOURCES) $(LIBS)

clean:
	rm -f $(TARGET)
