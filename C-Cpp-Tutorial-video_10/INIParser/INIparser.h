#pragma once

#include <string.h>
#include <stdint.h>

void parseINI(const char* INIcontent);
void appendBuffer(char* buffer, char c);
void stripBuffer(char* buffer);
