CXX = g++
CXXFLAGS = -O3 -std=c++11 -march=native -DOCL
LIBS = -lOpenCL
TARGET = ocl-stream
SOURCES = main.cpp OCLStream.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(LIBS) -o $@

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
