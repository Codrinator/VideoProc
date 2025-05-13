# Makefile for building main.cpp with OpenCV

# Compiler
CXX = cl.exe

# Directories
OPENCV_DIR = C:/opencv/build
INCLUDES = /I"$(OPENCV_DIR)/include" /I"$(OPENCV_DIR)/include/opencv2"
LIB_DIR = /LIBPATH:"$(OPENCV_DIR)/x64/vc16/lib"
LIBS = opencv_world4110.lib

# Source and Target
SRC = main.cpp
TARGET = main.exe

# Build rule
all:
	$(CXX) /EHsc $(INCLUDES) $(SRC) /link $(LIB_DIR) $(LIBS)

# Clean rule
clean:
	del /Q *.exe *.obj
