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

class CFileStream
{
public:
	CFileStream()
	{
	}

	void output(string & str_output)
	{
		ofstream ofs("runningtime.log", ios::app);
		ofs << str_output << endl;
	}			
private:
};

#endif
