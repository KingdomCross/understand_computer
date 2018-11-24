/*
 *
 */

#include <iostream>
#include "Singleton.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello main !!!" << std::endl;	
	
	auto m = &Singleton::getInstance();
	m->read();
	
	auto n = &Singleton::getInstance();
	n->print();
	
	Singleton* q = &Singleton::getInstance();
	q->print();
	
	return 0;
}
