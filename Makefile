CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

SRC = src/LanguageModel.cpp src/TextGenerator.cpp src/main.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = slm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
