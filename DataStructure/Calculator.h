#pragma once
#include <string.h>
char* Infix_To_PostFix(const char* input);
int PostFix_To_Result(char* input);
bool IsDigit(char input);