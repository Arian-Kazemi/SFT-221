#pragma once
#ifndef STRINGHELP_H
#define STRINGHELP_H

#define MAX_STRING_SIZE 511
#define MAX_INDEX_SIZE 100
#define MAX_WORD_SIZE 23

struct StringIndex
{
    char str[MAX_STRING_SIZE + 1];
    int wordStarts[MAX_INDEX_SIZE];
    int lineStarts[MAX_INDEX_SIZE];
    int numberStarts[MAX_INDEX_SIZE];
    int numWords, numLines, numNumbers;
};

int nextWhite(const char* str);
int isNumber(const char* str, const int len);
struct StringIndex indexString(const char* str);
int getNumberLines(const struct StringIndex* idx);
int getNumberWords(const struct StringIndex* idx);
int getNumberNumbers(const struct StringIndex* idx);
void getWord(char word[], const struct StringIndex* idx, int wordNum);
void getNumber(char word[], const struct StringIndex* idx, int numberNum);
char* getLine(struct StringIndex* idx, int lineNum);
void printUntil(const char* s, const int start, const char terminator);
void printUntilSpace(const char* s, const int start);

#endif
