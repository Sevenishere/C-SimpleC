#pragma once

#include <string.h>
#include <stdint.h>

void ini_parseINI(const char* INIcontent);
void ini_appendBuffer(char* buffer, char c);
void ini_stripBuffer(char* buffer);
