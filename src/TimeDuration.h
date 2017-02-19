#ifndef TimeDuration_H
#define TimeDuration_H

#include "CTimer.hpp"
#include "CFormatter.hpp"
#include "CTimeDuration.hpp"
#include "COutputter.hpp"
#include "OutStreamTemplates.hpp"

/*@Usage:
 *	{// Parentheses is necessary.
 *		CTimeDurationObject obj_records_running_time(COutputterScreen, NULL);//create CTimeDurationObject object
 *		...//business code
 *	}
 * */
typedef CTimeDuration<CTimer, COutputterBase > CTimeDurationObject;
typedef COutputter<CTimer, CFormatter<CTimer>, CScreenStream> COutputterScreen;
typedef COutputter<CTimer, CFormatter<CTimer>, CFileStream> COutputterFile;

#endif
