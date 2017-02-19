# TimeDuration
# Intro
It's a small tools which can test running time in cpp program.
# How to use
* #include "TimeDuration.h"
* use {...} wraps the code you wanna test.
* create temp object CTimeDurationObject and choose output ways. param should end up with NULL.
# Example
	...
	{
		CTimeDurationObject obj_records_running_time(COutputterScreen, NULL);
		...
	}
	...
