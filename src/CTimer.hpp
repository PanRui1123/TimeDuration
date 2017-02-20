#ifndef CTimer_HPP
#define CTimer_HPP

#include <string>
#include <stdexcept>
#include <sys/time.h>

#define usecs_in_1_sec (1e6)
#define sec_to_usec(sec) ((double)(sec) * usecs_in_1_sec)
#define usec_to_sec(usec) ((double)(usec) / usecs_in_1_sec)

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
				this->__current.tv_sec + usec_to_sec(this->__current.tv_usec)
				);	
	}

	std::string to_usec()
	{
		return std::to_string(
				sec_to_usec(this->__current.tv_sec) + this->__current.tv_usec
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
		result.__current.tv_usec += usecs_in_1_sec;
	}

	while(result.__current.tv_usec > usecs_in_1_sec)
	{
		++result.__current.tv_sec;
		result.__current.tv_usec -= usecs_in_1_sec;
	}

	return result;
}

#endif
