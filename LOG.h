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

#ifdef DEBUG

#define LOG_INFO1(s,...) 	myLOG("INFO   ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_INFO2(s)	 	myLOG("INFO   ", __FILE__, __LINE__, s)
#define LOG_INFO(...) GET_MACRO(__VA_ARGS__, LOG_INFO1, LOG_INFO2)(__VA_ARGS__)

#define LOG_DEBUG1(s,...) 	myLOG("DEBUG  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_DEBUG2(s) 	myLOG("DEBUG  ", __FILE__, __LINE__, s)
#define LOG_DEBUG(...) GET_MACRO(__VA_ARGS__, LOG_DEBUG1, LOG_DEBUG2)(__VA_ARGS__)

#define LOG_WARNING1(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_WARNING2(s) 		myLOG("WARNING", __FILE__, __LINE__,  s)
#define LOG_WARNING(...) GET_MACRO(__VA_ARGS__, LOG_WARNING1, LOG_WARNING2)(__VA_ARGS__)

#define LOG_ERROR1(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_ERROR2(s) 		myLOG("ERROR  ", __FILE__, __LINE__, s)
#define LOG_ERROR(...) GET_MACRO(__VA_ARGS__, LOG_ERROR1, LOG_ERROR2)(__VA_ARGS__)


#elif defined INFO
#define LOG_INFO1(s,...) 	
#define LOG_INFO2(s)	 	
#define LOG_INFO(...) GET_MACRO(__VA_ARGS__, LOG_INFO1, LOG_INFO2)(__VA_ARGS__)

#define LOG_DEBUG1(s,...) 	myLOG("DEBUG  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_DEBUG2(s) 	myLOG("DEBUG  ", __FILE__, __LINE__, s)
#define LOG_DEBUG(...) GET_MACRO(__VA_ARGS__, LOG_DEBUG1, LOG_DEBUG2)(__VA_ARGS__)

#define LOG_WARNING1(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_WARNING2(s) 		myLOG("WARNING", __FILE__, __LINE__,  s)
#define LOG_WARNING(...) GET_MACRO(__VA_ARGS__, LOG_WARNING1, LOG_WARNING2)(__VA_ARGS__)

#define LOG_ERROR1(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_ERROR2(s) 		myLOG("ERROR  ", __FILE__, __LINE__, s)
#define LOG_ERROR(...) GET_MACRO(__VA_ARGS__, LOG_ERROR1, LOG_ERROR2)(__VA_ARGS__)


#elif defined WARNING
#define LOG_INFO1(s,...) 	
#define LOG_INFO2(s)	 	
#define LOG_INFO(...) GET_MACRO(__VA_ARGS__, LOG_INFO1, LOG_INFO2)(__VA_ARGS__)

#define LOG_DEBUG1(s,...) 	
#define LOG_DEBUG2(s) 	
#define LOG_DEBUG(...) GET_MACRO(__VA_ARGS__, LOG_DEBUG1, LOG_DEBUG2)(__VA_ARGS__)

#define LOG_WARNING1(s,...) 	myLOG("WARNING", __FILE__, __LINE__,  s, __VA_ARGS__)
#define LOG_WARNING2(s) 		myLOG("WARNING", __FILE__, __LINE__,  s)
#define LOG_WARNING(...) GET_MACRO(__VA_ARGS__, LOG_WARNING1, LOG_WARNING2)(__VA_ARGS__)

#define LOG_ERROR1(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_ERROR2(s) 		myLOG("ERROR  ", __FILE__, __LINE__, s)
#define LOG_ERROR(...) GET_MACRO(__VA_ARGS__, LOG_ERROR1, LOG_ERROR2)(__VA_ARGS__)


#elif defined ERROR
#define LOG_INFO1(s,...) 	
#define LOG_INFO2(s)	 	
#define LOG_INFO(...) GET_MACRO(__VA_ARGS__, LOG_INFO1, LOG_INFO2)(__VA_ARGS__)

#define LOG_DEBUG1(s,...) 	
#define LOG_DEBUG2(s) 	
#define LOG_DEBUG(...) GET_MACRO(__VA_ARGS__, LOG_DEBUG1, LOG_DEBUG2)(__VA_ARGS__)

#define LOG_WARNING1(s,...) 	
#define LOG_WARNING2(s) 		
#define LOG_WARNING(...) GET_MACRO(__VA_ARGS__, LOG_WARNING1, LOG_WARNING2)(__VA_ARGS__)

#define LOG_ERROR1(s,...) 	myLOG("ERROR  ", __FILE__, __LINE__, s, __VA_ARGS__)
#define LOG_ERROR2(s) 		myLOG("ERROR  ", __FILE__, __LINE__, s)
#define LOG_ERROR(...) GET_MACRO(__VA_ARGS__, LOG_ERROR1, LOG_ERROR2)(__VA_ARGS__)


#else
#define LOG_DEBUG(s,...)
#define LOG_INFO(s,...)
#define LOG_WARNING(s,...)
#define LOG_ERROR(s,...)
#endif




#endif /* LOG_H_ */
