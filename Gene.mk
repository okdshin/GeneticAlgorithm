CXX = g++ -std=gnu++0x
CXXFLAGS = -Wall -g -D GENE_UNIT_TEST
INCLUDES = 
LIBS = -
OBJS = Gene.o
PROGRAM = Gene.out

all:$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(INCLUDES) $(LIBS) -o $(PROGRAM)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBS) -c $<

.PHONY: clean
clean:
	rm -f *o $(PROGRAM)
