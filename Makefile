CXX := g++
INCLUDE_DIR := include/include
LIB_DIR := include/lib
TARGET := game
SRC := main.cpp
LIBS := -lmingw32 -lSDL2main -lSDL2
CXXFLAGS := -I$(INCLUDE_DIR)
LDFLAGS := -L$(LIB_DIR)

all: $(TARGET)

$(TARGET): $(SRC)
	@echo Compiling...
	@$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
	@echo Build complete!

c:
	@echo Cleaning up...
	@del $(TARGET).exe
	@echo Clean complete!

.PHONY: all clean
