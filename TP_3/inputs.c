/*
 * inputs.c
 *
 *  Created on: 7 oct. 2021
 *      Author: franc
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

int getString(char *_str, char *_msg, char *_errMsg, int _strMaxLen)
{
	char str[200];
	int len;

	if(_str!=NULL)
	{
		printf("%s", _msg);
		fflush(stdin);
		scanf("%[^\n]", str);
		len = strlen(str);

		if(len>_strMaxLen)
		{
			printf(_errMsg);
			return -1;
		}
		strcpy(_str, str);
		return 0;
	}
	return -1;
}

int isLetter(char *_str, char *_errMsg)
{
    int i=0;

    if(_str!=NULL)
    {
		while(_str[i]!='\0')
		{
			if((_str[i]!=' ') && (_str[i]<'a'||_str[i]>'z') && (_str[i]<'A'||_str[i]>'Z'))
			{
				printf("%s", _errMsg);
				return -1;
			}
			i++;
		}
    }
    return 0;
}

int isNotBlank(char *_str, char *_errMsg)
{
	int flagNotBlank=0;
    int i=0;

    if(_str!=NULL)
    {
        while(_str[i]!='\0')
        {
            if(_str[i]!=' ')
            {
            	flagNotBlank=1;
            }
            i++;
        }
        if (flagNotBlank==1)
        {
        	return 0;
        }
    }
    printf("%s", _errMsg);
    return -1;
}

int getName(char *_str, char *_msg, char *_errMsgOnLen, char *_errMsgNotLetter, char *_errMsgIsBlank, int _strMaxLen)
{
	char str[_strMaxLen];

	if(_str!=NULL)
	{
		if(getString(str, _msg, _errMsgOnLen, _strMaxLen)==0 && isLetter(str, _errMsgNotLetter)==0 && isNotBlank(str, _errMsgIsBlank)==0)
		{
			strcpy(_str, str);
			return 0;
		}
	}
	getName(_str, _msg, _errMsgOnLen, _errMsgNotLetter, _errMsgIsBlank, _strMaxLen);
	return -1;
}

int getInt(char *_msg, char *_errMsg, int _min, int _max)
{
	int num;
	int resOperation;

	printf("%s", _msg);
	fflush(stdin);
	resOperation=scanf("%d", &num);

	while(resOperation!=1 || (num < _min || num > _max))
	{
		printf("%s", _errMsg);
		fflush(stdin);
		resOperation=scanf("%d", &num);
	}
	return num;
}

long int getlong(char *_msg, char *_errMsg, long int _min, long int _max)
{
	long int num;
	int resOperation;

	printf("%s", _msg);
	fflush(stdin);
	resOperation=scanf("%ld", &num);

	while(resOperation!=1 || (num < _min || num > _max))
	{
		printf("%s", _errMsg);
		fflush(stdin);
		resOperation=scanf("%ld", &num);
	}
	return num;
}

double getDouble(char *_msg, char *_errMsg, double _min, double _max)
{
	double num;
	int resOperation;

	printf("%s", _msg);
	fflush(stdin);
	resOperation=scanf("%lf", &num);

	while(resOperation!=1 || (num < _min || num > _max))
	{
		printf("%s", _errMsg);
		fflush(stdin);
		resOperation=scanf("%lf", &num);
	}
	return num;
}

float getFloat(char *_msg, char *_errMsg, int _min, int _max)
{
	float num;
	int resOperation;

	printf("%s", _msg);
	fflush(stdin);
	resOperation=scanf("%f", &num);

	while(resOperation!=1 || (num < _min || num > _max))
	{
		printf("%s", _errMsg);
		fflush(stdin);
		resOperation=scanf("%f", &num);
	}
	return num;
}

int getCharacter(char *_char, char *_msg)
{
	if(_char!=NULL && _msg!=NULL)
	{
		printf("%s", _msg);
		fflush(stdin);
		*_char = getchar();
		return 0;
	}
	return -1;
}

int verify(char *_msg)
{
	char ver;

	getCharacter(&ver, _msg);
	if(ver == 's' || ver == 'S')
	{
		return 0;
	}
	return -1;
}

void printLine(char *_msg)
{
	printf("\n----------------%s----------------\n", _msg);
}
