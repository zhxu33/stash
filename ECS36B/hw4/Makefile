CXX=g++
CXXFLAGS=-Wall
EXECS=wfreq
all: $(EXECS)
wfreq: wfreq.o
	$(CXX) -o $@ $^
clean:
	rm -f *.o $(EXECS)
