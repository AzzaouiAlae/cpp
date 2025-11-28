#include "Data.hpp"
#include "Serialize.hpp"

int main()
{
	Data d;
	uintptr_t ptr = Serialize::serialize(&d);
	d.Number = 50;
	cout << "ptr : 0x" << std::hex << ptr << '\n';
	cout << "data: " << &d << '\n';

	Data *obj = Serialize::deserialize(ptr);
	cout << "obj : " << obj << '\n';

	obj->Number = 15;
	cout << "data number: " << std::dec  << (int)d.Number << '\n';
	return 0;
}
