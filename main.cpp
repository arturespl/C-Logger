#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "LOG.h"


using namespace std;

int main(int argc, char** argv)
{
	LOG_DEBUG("slaby blad : %s %d", "asdfaf", 2);
	LOG_INFO("slaby blad : %s %d", "asdfaf", 2);
	LOG_WARNING("slaby blad : %s %d", "asdfaf", 2);
	LOG_ERROR("slaby blad : %s %d", "asdfaf", 2);

	cout << "\nProject Name: " << getenv("PROJECT_NAME") << flush;

	return 0;
}



