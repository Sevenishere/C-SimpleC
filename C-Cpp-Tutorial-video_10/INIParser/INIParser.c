
#include "INIparser.h"

#include <string.h>
#include <stdio.h>

void ini_parseINI(const char* INIcontent) {
	int8_t state = 0;
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

		switch (state) {

			// READY TO INI
		case 0:

			switch (*c) {
			case ';':
				state = 1;
				break;
			case '[':
				state = 2;
				break;
			case ' ':
			case '\t':
			case '\n':
				break;
			default:
				ini_appendBuffer(buffer, *c);
				state = 3;

			}
			break;

		case 1:

			if (*c == '\n') state = 0;
			break;

		case 2:

			switch (*c) {
			case ']':
				strcpy_s(currentSectionName, 256, buffer);
				*buffer = '\0';
				state = 0;
				break;

			case '\n':
				*buffer = '\0';
				state = 0;
				break;

			default:
				ini_appendBuffer(buffer, *c);
				break;
			}
			break;
		case 3:
			switch (*c)
			{
			case ' ':
			case '\t':
				strcpy_s(currentKeyName, 256, buffer);
				*buffer = '\0';
				state = 4;
				break;
			case '\n':
				*buffer = '\0';
				state = 0;
				break;
			default:
				ini_appendBuffer(buffer, *c);
				break;
			}

			break;
		case 4:

			switch (*c)
			{
			case '=':
				state = 5;
				break;

			case '\n':
				state = 0;
				break;

			case ' ':
			case '\t':
				break;
			default:
				state = 7;
				break;
			}

			break;

			//GETS READY TO TAKE THE KEY
		case 5:

			switch (*c)
			{
			case '\n':
				state = 0;
				break;
			case ' ':
			case '\t':
				break;
			default:
				ini_appendBuffer(buffer, *c);
				state = 6;
				break;
			}

			break;

			//TAKES THE KEY			
		case 6:

			switch (*c)
			{
			case '\n':
				ini_stripBuffer(buffer);
				strcpy_s(currentValueName, 256, buffer);
				*buffer = '\0';
				state = 0;
				printf("Properties: \"%s/%s\": \"%s\"\n", currentSectionName, currentKeyName, currentValueName);
				break;

			default:
				ini_appendBuffer(buffer, *c);
				break;

			}
			break;

		case 7:
			if (*c == '\n') state = 0;
			break;

		}


	}
}

//APPENDS LETTER TO THE BUFFER
void ini_appendBuffer(char* buffer, char c) {
	char string[2] = { c,'\0' };
	strcat_s(buffer, 256, string);
}


//GETS RID OF THE SPACE AT THE END
void ini_stripBuffer(char* buffer)
{
	char* c = &buffer[strlen(buffer) - 1];
	if (*c == ' ' || *c == '\t') {
		*c = '\0';
		ini_stripBuffer(buffer);
	}
}