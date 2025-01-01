CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++20

APP_SRC = main.cpp account.cpp
APP_OBJ = $(APP_SRC:.cpp=.o)
APP_EXE = app

# Default target
all: $(APP_EXE)

# Build the executable
$(APP_EXE): $(APP_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(APP_OBJ) $(APP_EXE)

# Add a phony target for clean
.PHONY: all clean
