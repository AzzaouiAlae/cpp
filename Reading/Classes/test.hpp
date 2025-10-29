#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>
#define cout std::cout
#define endl std::endl

struct Vector 
{
	int x;
	int y;
	int z;
};

class ClsVector {
	public:
	int x;
	int y;
	int z;
};

class A final {
	public:
	int value;
};
class B //: public A  //can not use final class
{

};

class A2 {

};
class B2 final : A2 {

};
class C2 //: public B2 
{

};


#endif