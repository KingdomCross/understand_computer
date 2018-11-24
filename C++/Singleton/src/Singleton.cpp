/*
 * @description 
 */

#include "Singleton.h"
#include <iostream>


int Singleton::mCount = 0;
Singleton::Singleton()
{
	mCount++;
}


Singleton::~Singleton()
{
	
}

Singleton& Singleton::getInstance()
{
	static Singleton uniqueInstance;
	std::cout << "Singleton initial times: " 
			  << mCount
			  << std::endl;
	return	uniqueInstance;
}


void Singleton::print()
{
	for (auto iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << "\t" << *iter << std::endl;
	
}

void Singleton::read()
{
	in.open("../src/test.cpp", std::ifstream::in);
	if(!in)
		std::cout << "Open file failed!\n";
	else
	{
		std::string line;
	
		while(getline(in, line))
		{
			vec.push_back(line);
		}
	}
}
