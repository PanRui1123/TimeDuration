#ifndef CTimer_HPP
#define CTimer_HPP

#include <string>
#include <stdexcept>
#include <sys/time.h>

class CTimer
{
public:
	
	friend CTimer operator - (CTimer, CTimer);
	CTimer(){}

	~CTimer(){}

	void Timing()
	{
		gettimeofday(&this->__current, NULL);				
	}
	
	std::string to_sec()
	{
		return std::to_string(
				((double)(this->__current.tv_sec + this->__current.tv_usec * 1000000))/1000000.0
				);	
	}

	std::string to_usec()
	{
		return std::to_string(
				this->__current.tv_sec * 1000000 + this->__current.tv_usec
				);	
	}

	
private:
	
	timeval __current; 

};

CTimer operator-(CTimer end, CTimer beg)
{
	CTimer result;
	if(beg.__current.tv_sec > end.__current.tv_sec)
		throw std::logic_error("CTime operator-(CTimer end, CTimer beg)"); 
	else if(beg.__current.tv_sec == end.__current.tv_sec && beg.__current.tv_usec > end.__current.tv_usec)
		throw std::logic_error("CTime operator-(CTimer end, CTimer beg)");

	result.__current.tv_sec = end.__current.tv_sec - beg.__current.tv_sec;
	result.__current.tv_usec = end.__current.tv_usec - beg.__current.tv_usec;

	while(result.__current.tv_usec < 0)
	{
		--result.__current.tv_sec;
		result.__current.tv_usec += 1000000;
	}

	while(result.__current.tv_usec > 1000000)
	{
		++result.__current.tv_sec;
		result.__current.tv_usec -= 1000000;
	}

	return result;
}

#endif
