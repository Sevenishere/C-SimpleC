#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define XD "Toh kaise hai aap: "

void parseINI(const char* INIcontent);
void appendINI(char* buffer, char c);
void stripChar(char* buffer);

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
		"	server = 192.0.2.62     \n"
		"	port = 143\n"
		"	file = \"payroll.dat\"\n";
	printf("====  RAW INI FILE  ====\n");
	printf(INIContent);
	printf("====  PARSED DATA  ====\n");
	parseINI(INIContent);
	
}

void parseINI(const char* INIcontent) {
	int8_t state =0;
	char buffer[256];
	*buffer = '\0';
	char currentSectionName[256];
	char currentKeyName[256];
	char currentValueName[256];
	/*for (int32_t i = 0; INIcontent[i]; i++)
	{
		char c = INIcontent[i];
		printf("'%c'",c);
	}*/
	/*
	* STATES OF STATEMACHINE
	* 0. READY FOR INI DATA
	* 1. COMMENT STARTED
	* 2. SECTION STARTED
	* 3. KEY STARTED
	* 4. KEY ENDED
	* 5. READY FOR VALUE
	* 6. VALUE STARTED
	* 7/ FOUND INVALID DATA
	*/
	
	for (const char* c = INIcontent; *c; c++)
	{
		// READY TO INI
		if (state == 0) {

			if (*c == ';') state = 1;//COMMENT STARTED
			else if (*c == '[') {
				state = 2;
			}//SECTION NAME STARTED
			else if (!(*c == ' ' || *c == '\t' || *c =='\n')) {
				appendINI(buffer, *c);
				state = 3;
			};//KEY STARTED

		}

		else if (state == 1) {
			if (*c == '\n') state = 0;
		}

		else if (state == 2) {


			if (*c == ']') 
			{
				memcpy(currentSectionName,buffer,256*sizeof(char));
				*buffer = '\0';
				state = 0;
			}

			else if (*c == '\n') 
			{
				*buffer = '\0';
				state = 0;
			}
			else {
				appendINI(buffer, *c);
			}
		}

		else if (state == 3) {


			if (*c == ' ' || *c == '\t')
			{
				memcpy(currentKeyName, buffer, 256 * sizeof(char));
				*buffer = '\0';
				state = 4;
			}

			else if (*c == '\n')
			{
				*buffer = '\0';
				state = 0;
			}
			else {
				appendINI(buffer, *c);
			}
		}

		else if (state == 4) {
			if (*c == '=') {
				state = 5;
			}
			else if (*c == '\n') state = 0;
			else if (!(*c == ' ' || *c == '\t')) state = 7;//Invalid Pair
		}

		//GETS READY TO TAKE THE KEY
		else if (state == 5) {
			if (*c == '\n')state = 0;
			else if (!(*c == ' ' || *c == '\t')) {
				appendINI(buffer, *c);
				state = 6;
			};

		}
		//TAKES THE KEY
		else if (state == 6) {

			if (*c == '\n')
			{

				stripChar(buffer);
				memcpy(currentValueName, buffer, 256 * sizeof(char));
				*buffer = '\0';
				state = 0;
				printf("Propertie: \"%s/%s\": \"%s\"\n", currentSectionName, currentKeyName, currentValueName);
			}

			else {
				appendINI(buffer, *c);
			}
		}
		else if (state == 7)
		{
			if (*c == '\n') state = 0;
		}
	}
}

//APPENDS LETTER TO THE BUFFER
void appendINI(char* buffer, char c) {
	char* cursor;
	for (cursor = buffer;  *cursor ; cursor++);
	cursor[0] = c;
	cursor[1] = '\0';
}


//GETS RID OF THE SPACE AT THE END
void stripChar(char* buffer)
{
	char* cursor;
	for (cursor = buffer; !cursor[1]=='\0'; cursor++);
	while (cursor[0] == ' ') {
		cursor[0] = '\0';
		cursor--;
	}
}
