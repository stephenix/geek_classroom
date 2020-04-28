CC = gcc
CXX = g++
CXXFLAGS += -Wall --std=c++11
# 变量
OBJS = main.o print.o
hello : $(OBJS)
	$(CXX) $(CXXFLAGS) -o hello $(OBJS)
main.o : main.cc print.h
	$(CXX) $(CXXFLAGS) -c main.cc print.h 
print.o : print.cc print.h
	$(CXX) $(CXXFLAGS) -c print.cc print.h 

# 伪目标, h.gch是g++做的一些优化
.PHONY: clean
clean:
	rm hello *.o *.h.gch
