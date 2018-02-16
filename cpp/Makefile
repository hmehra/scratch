CFLAGS := -ggdb -std=c++11

SRCS    = $(shell find . -name '*.cpp')
OBJS    = $(patsubst %.cpp, %.o,$(SRCS))

all: $(OBJS)

%.o: %.cpp
	@mkdir -p bin
	g++ $(CFLAGS) $< -o bin/$@

clean:
	rm -rf bin
	rm -rf *.out
