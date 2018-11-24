/*
 * @description 
 */

#ifndef SINGLETON_H_
#define SINGLETON_H_

#include<fstream>
#include<vector>
#include<string>

class Singleton//: public SOMECLASS
{
private: 
	static int mCount;
	std::ifstream in;
	std::vector<std::string> vec;
	Singleton();
	~Singleton();

public: 
	static Singleton& getInstance();
	void print();
	void read();

};

#endif
