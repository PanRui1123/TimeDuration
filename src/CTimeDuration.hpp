#ifndef CTimeDuration_HPP
#define CTimeDuration_HPP

#include <list>
#include <cstdarg>
#include <cstddef>

template<class CTimer, class COutputter>
class CTimeDuration
{
public:

	CTimeDuration(COutputter * outputter, ...)
	{
		va_list OutputterIterator;
		va_start(OutputterIterator, outputter);
		
		COutputter * current_outputter = outputter; 
		while(current_outputter != NULL)
		{
			__outputter_list.push_back(current_outputter);	
			current_outputter = va_arg(OutputterIterator, COutputter *);
		}

		va_end(OutputterIterator);

		__begin.Timing();
	}

	~CTimeDuration()
	{
		__end.Timing();

		for(auto outputter : __outputter_list)
		{
			outputter->output(__begin, __end);
			delete outputter;
		}
	}

private:

	CTimer __begin, __end;
	std::list<COutputter *> __outputter_list;
};

#endif
