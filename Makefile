all: classes
	

classes:
	c++ -g Reading/Classes/test.cpp
	./a.out

namespace: lib
	c++ -g theirs.o Reading/namespace/mine.cpp
	./a.out

lib_namespace: 
	c++ -c -o theirs.o Reading/namespace/theirs.cpp