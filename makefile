CXX = g++
CXXFLAGS = -O2 --std=c++11
OBJS = main.o dist_from_ll.o
PROGRAM = main.exe
.SUFFIXES: .cpp .o
$(PROGRAM): $(OBJS)
	$(CXX) $(OBJS) -o $(PROGRAM) $(LDFLAGS)
.cpp.o:
	$(CXX) $< -c $(CXXFLAGS)
clean:
	rm *.o $(PROGRAM)