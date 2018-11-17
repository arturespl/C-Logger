#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "LOG.hpp"


using namespace std;


int main(int argc, char** argv)
{
	LOG_DEBUG("slaby blad : %s ", "asdfaf");
	LOG_INFO("slaby blad : %s ", "asdfaf");
	LOG_WARNING("slaby blad : %s ", "asdfaf");
	LOG_ERROR("slaby blad : %s ", "asdfaf");

	LOG_INFO("slaby blad", 1);

	cout << "\nProject Name: " << getenv("PROJECT_NAME") << flush;

	return 0;
}



