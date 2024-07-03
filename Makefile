# Define the compiler
CXX = g++

# Define the flags
CXXFLAGS = -Wall -std=c++11

# Define the executable name
EXEC = mineSweeperText

# Define the source and object files
SRCS = mineSweeperText.cpp Board.cpp Game.cpp
OBJS = $(SRCS:.cpp=.o)

# Default rule to build the executable
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to build object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJS) $(EXEC)

# Rebuild the project
rebuild: clean all
