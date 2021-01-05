# Folder with '.hpp' files (declarations)
INCLUDE_DIR=./include

# Folder with '.cpp' files (definitions)
VPATH=./src

# Compilation flags
CXXFLAGS=-std=c++17 -Wall -I$(INCLUDE_DIR)

# Linked libraries
LINKFLAGS=-lX11 -lGL -lpthread -lpng -lstdc++fs -lm

# Files to be included
DEPENDENCIES=main.cpp olcPixelGameEngine.cpp TextGUI.cpp Application.cpp

# Executable
TARGETS=application

build: $(TARGETS)

$(TARGETS): $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $(TARGETS) $^ $(LINKFLAGS)

.PHONY: clean
clean:
	-rm -f $(TARGETS)
