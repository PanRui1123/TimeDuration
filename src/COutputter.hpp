#ifndef COutputter_HPP
#define COutputter_HPP

#include <string>

class COutputterBase
{
public:
	virtual void output(CTimer __begin, CTimer __end) = 0;
};

template<class CTimer, class CFormatter, class COutStream>
class COutputter:public COutputterBase
{
public:

	COutputter()
	{
	
	};

	~COutputter()
	{
	
	}

	void output(CTimer __begin, CTimer __end)
	{
		CFormatter formatter;
		COutStream outstream;

		std::string str_output = formatter.format(__begin, __end);
		outstream.output(str_output);
	}

};

#endif
