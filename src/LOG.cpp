/*
 * LOG.c
 *
 *  Created on: 12.01.2017
 *      Author: artur
 */
#include <cstdarg>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <unistd.h>
#include <fstream>


#ifdef __linux__
#include <libgen.h>
#endif

#include "LOG.hpp"

#define logFileNameLength 512
char* logFileName = 0;

using namespace std;

void getTime(char* ret, int buflen){

	bzero(ret,buflen);

	time_t rawtime;
	struct tm timeinfo;

	time (&rawtime);
	timeinfo = *localtime (&rawtime);

	sprintf(ret, "%d:%d:%d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
}

void getDate(char* ret, int buflen){

	bzero(ret,buflen);

	time_t rawtime;
	struct tm timeinfo;

	time (&rawtime);
	timeinfo = *localtime (&rawtime);

	sprintf(ret, "%d %d %d", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900);
}



char* getLogFileName(char* buff, int len){
	
	if(logFileName==0){
		bzero(buff,len);
		return buff;
	}

	strncpy(buff,logFileName, (len > logFileNameLength ? logFileNameLength : len) );

	return buff;
}
void setLogFileName(char* buff, int len){
	if(logFileName==0) {
		logFileName = (char*)malloc(sizeof(char) * logFileNameLength);
		bzero(logFileName, logFileNameLength);
	}
	strncpy(logFileName,buff, (len > logFileNameLength ? logFileNameLength : len) );
}

char * getLogName(){
	char* path = 0;

	if(logFileName != 0)
		return logFileName;

	logFileName = (char*)malloc(sizeof(char)*logFileNameLength);
	bzero(logFileName, logFileNameLength);

	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);

#ifdef __linux__
	char result[logFileNameLength] = {0};
	ssize_t count = readlink("/proc/self/exe", result, logFileNameLength);
	if (count != -1)
	{
		path = dirname(result);
	}
	char cmd[logFileNameLength] = {0};
	sprintf(cmd, "mkdir -p %s/Logs", path);
	system(cmd);
#endif

	path==0 ?
	sprintf(logFileName, "Logs/LOG_%s", asctime(timeinfo)) :
	sprintf(logFileName, "%s/Logs/LOG_%s", path, asctime(timeinfo));

	sprintf(logFileName+strlen(logFileName)-1, ".txt");

	unsigned int i=0;
	for(;i<strlen(logFileName); ++i)
	{
		if(logFileName[i]==' ')
			logFileName[i] = '-';
	}

	return logFileName;
}

void myLOG(const char* LOG_LVL
		,const char* FILEN
		,int LINE
		,const char* format, ...)
{
	va_list arglist;
	int needed_length;
	char * buff1;
	char * buff2;
	char _date[512];
	char _time[512];
	FILE* pFile;

	getTime(_time, 512);
	getDate(_date, 512);

	int pid = getpid();

#ifdef BUILD
#define FORMAT "\n%s | pid:%d | %s | %s | %s"
	needed_length = (snprintf(NULL, 0, FORMAT, LOG_LVL, pid, _date, _time, format) + 1 ) * sizeof(char) ;
	buff1 = (char*)malloc( needed_length );
	sprintf(buff1, FORMAT, LOG_LVL, pid, _date, _time, format);
#else
#define FORMAT "\n%s | pid:%d | %s | %s | %s:%d | %s"
	needed_length = (snprintf(NULL, 0, FORMAT, LOG_LVL, pid, _date, _time, FILEN, LINE, format) + 1) * sizeof(char);
	buff1 = (char*)malloc( needed_length);
	sprintf(buff1, FORMAT, LOG_LVL, pid, _date, _time, FILEN, LINE, format);

#endif

	va_start( arglist, format );
	needed_length = (vsnprintf(NULL, 0, buff1, arglist)  + 1) * sizeof(char);
	va_end( arglist );
	buff2 = (char*)malloc(needed_length);
	bzero(buff2, needed_length);
	va_start( arglist, format );
	vsprintf(buff2, buff1, arglist);
	va_end( arglist );

	fwrite(buff2, needed_length, 1, stdout);
	fflush(stdout);

//TODO corrupted size vs prev_size 

	pFile = fopen (getLogName(),"a");
	if(pFile==NULL)
	{
		fprintf(stderr, "\nCan't open file: %s", getLogName());
	}
	else
	{
		fwrite(buff2, strlen(buff2), 1, pFile);
		fclose(pFile);
	}

	free(buff1);
	free(buff2);

}

