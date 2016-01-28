/*
 * Log.cpp
 *
 *  Created on: 9 Oct 2015
 *      Author: mickael
 */

#include "Log.h"

#include <stdio.h>

#ifdef VERBOSE
LL_LOG log_level = LL_VERBOSE;
#elif RELEASE
LL_LOG log_level = LL_INFO;
#else
LL_LOG log_level = LL_INFO;
#endif

void setLogLevel(LL_LOG level){
	log_level = level;
}
LL_LOG getLogLevel(){
	return log_level;
}
