#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include "log4c.h"
int main(void)
{
	char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
	struct Log4cStruct log = l4cOpen("mylogfile.txt", 1);
	l4cError(&log, "error msg");
	l4cWarning(&log, "warning msg");
	l4cInfo(&log, "info msg");
	l4cPrintf(&log, L4C_INFO, "I am %d years old", 47);



	char testStr[] = { "This is a\n string with embedded newlinecharacters and \n12345 numbers inside it as well 7890" };
	struct StringIndex index = indexString(testStr);
	int i;
	printf("LINES\n");
	for (i = 0; i < index.numLines; i++)
	{
	printUntil(index.str, index.lineStarts[i], '\n');
	printf("\n");
	}
	printf("\nWORDS\n");
	for (i = 0; i < index.numWords; i++)
	{
	printUntilSpace(index.str, index.wordStarts[i]);
	printf("\n");
	}
	printf("\nNUMBERS\n");
	for (i = 0; i < index.numNumbers; i++)
	{
	printUntilSpace(index.str, index.numberStarts[i]);
	printf("\n");
	}
	l4cClose(&log);
	return 0;
	}