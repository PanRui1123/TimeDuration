#ifndef CFormatter_HPP
#define CFormatter_HPP

#include <string>

template<class CTimer>
class CFormatter
{
public:

	std::string format(CTimer begin, CTimer end)
	{
		CTimer during = end - begin;
		return std::string("running time is:") + during.to_sec();
	}

private:	
};

#endif
