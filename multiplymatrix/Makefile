#TLPI_PATH = ..

#INCLUDES = -I $(TLPI_PATH)/lib
LIBS = -static #-ltlpi
CXXFLAGS = -g -Wall ${INCLUDES}  -L.. -L.

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp,%.exe,$(SRCS))

.PHONY: all clean

all: $(OBJS)

%.exe:%.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LIBS)

clean :
	rm -rf $(OBJS)

test:
	./$(OBJS)
