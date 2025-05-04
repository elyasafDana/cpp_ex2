#elidnana@gmail.com
CXX=g++ 

TARGET=main

SRCS=Mat.cpp main.cpp#

HDR=Mat.h

OBJS = $(SRCS:.cpp=.o)

$(TARGET): $(OBJS) 
	$(CXX) -o $@ $^

Mat: Mat.cpp Mat.h main.cpp
	$(CXX) -g -c $^ -o $@


test: test.o Mat.cpp
	$(CXX) Mat.cpp test.cpp -o test

test.o: Mat.cpp test.cpp
	$(CXX) Mat.cpp test.cpp -o test

Test:test
	./test
clean:
	rm $(OBJS) $(TARGET) test

valgrind:	Mat 
		valgrind --leak-check=full ./main 

Main:  $(TARGET)
		./main

.PHONY: clean Main