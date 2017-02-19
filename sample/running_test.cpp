#include "TimeDuration.h"

int main()
{
	int i, j, k = 0;

	{
		CTimeDurationObject obj( new COutputterScreen, new COutputterFile,  NULL);	
		for(i = 0; i < 2000; ++i)
			for(j = 0; j < 2000; ++j)
				++k;
	}
}






