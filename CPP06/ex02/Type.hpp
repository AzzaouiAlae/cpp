#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

class Type
{
	Type();
	~Type();
	Type(const Type& obj);
	Type& operator=(const Type& obj);
public:
	static Base* generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
};