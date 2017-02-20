#ifndef OutStreamTemplates_HPP
#define OutStreamTemplates_HPP

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CScreenStream
{
public:
	void output(string & str_output)
	{
		cout << str_output << endl;
	}			
};

class CScreenStreamError
{
public:
	void output(string & str_output)
	{
		cerr << str_output << endl;
	}
};

class CFileStream
{
public:
	void output(string & str_output)
	{
		ofstream ofs("runningtime.log", ios::app);
		ofs << str_output << endl;
	}			
};

#endif
