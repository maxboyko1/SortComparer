.PHONY = all clean

CXX = g++
CXXFLAGS = -std=c++17 -Wall
EXECS = randomnumbers sortcomparer

all: $(EXECS)

randomnumbers: randomnumbers.o
	$(CXX) $(CXXFLAGS) -o $@ $<

sortcomparer: sortcomparer.o
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	@rm -f $(EXECS) *.o
