#pragma once

#include <stdio.h>

#define MAX_CHAR_COUNT 50
#define MAX_INSTRUCTIONS 25

int ReadInstructionsFile(char* filePath, char** instructions);