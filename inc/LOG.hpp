/*
 * LOG.h
 *
 *  Created on: 12.01.2017
 *      Author: artur
 */

#ifndef LOG_H_
#define LOG_H_

#define DEBUG
//#define BUILD

void myLOG(const char* LOG_LVL
		,const char* FILEN
		,int LINE
		,const char* format, ...);

void myLOG(const char* LOG_LVL
		,const char* FILEN
		,int LINE);

char* getLogFileName(char* buff, int buflen);
void setLogFileName(char* buff, int buflen);

#define GET_MACRO(_1,_2,NAME,...) NAME

//#define LOG_INIT(s) setLogFileName(s, strlen(s))

#ifdef DEBUG

#define LOG_INFO(s,...) 	myLOG("INFO   ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_DEBUG(s,...) 	myLOG("DEBUG  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_WARNING(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_ERROR(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)

#elif defined INFO
#define LOG_INFO(s,...) 	
#define LOG_DEBUG(s,...) 	myLOG("DEBUG  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_WARNING(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_ERROR(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)

#elif defined WARNING
#define LOG_INFO(s,...) 	
#define LOG_DEBUG(s,...) 	
#define LOG_WARNING(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_ERROR(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)

#elif defined ERROR
#define LOG_INFO(s,...) 
#define LOG_DEBUG(s,...)
#define LOG_WARNING(s,...)
#define LOG_ERROR(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)


#else
#define LOG_DEBUG(s,...)
#define LOG_INFO(s,...)
#define LOG_WARNING(s,...)
#define LOG_ERROR(s,...)
#endif




#endif /* LOG_H_ */
