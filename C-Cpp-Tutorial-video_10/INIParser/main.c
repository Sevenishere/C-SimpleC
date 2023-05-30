#include "INIparser.h"

#include <stdio.h>

#define XD "Config Input by i-stream needed: "


int main() {
	char c = 'H';
	const char* INIContent = 
		"; last modified 1 April 2001 by John Doe\n"
		"[owner]\n"
		"	name = John Doe\n"
		"	organization = Acme Widgets Inc.\n"
		"\n"
		"[database]\n"
		"	; use IP address in case network name resolution is not working\n"
		"	server = 192.0.2.62  djskgksfjgk   \n"
		"	port = 143\n"
		"	file = \"payroll.dat\"\n";
	printf("====  RAW INI FILE  ====\n");
	printf(INIContent);
	printf("====  PARSED DATA  ====\n");
	ini_parseINI(INIContent);
	
}


