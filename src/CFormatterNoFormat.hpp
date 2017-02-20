#ifndef CFormatterNoFormat_HPP
#define CFormatterNoFormat_HPP

#include <string>

template<class CTimer>
class CFormatterNoFormat
{
public:

	std::string format(CTimer begin, CTimer end)
	{
		CTimer during = end - begin;
		return during.to_usec();
	}

private:	
};

#endif
