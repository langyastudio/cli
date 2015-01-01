#include "stdafx.h"
#include "ExportDllAPI.h"

/************************************************************************/
/*                          1. 字符串                                    */
/************************************************************************/
//1.1 字符串作为输入参数
EXPORTDLL_CLASS int Str_Output( WCHAR *pInStr )
{
	if (NULL == pInStr)
	{
		return(-1);
	}

	wprintf(L"Str_Output %s\n", pInStr);

	return(0);
}

//1.2 字符串作为参数,需要进行修改返回
EXPORTDLL_CLASS int Str_Change( WCHAR *pOutStr)
{
	if (NULL == pOutStr)
	{
		return(-1);
	}

    int len = wcslen(pOutStr);
	for (int ix=0; ix<len-1; ix++)
	{
		pOutStr[ix] = 'a' + (ix) % 26;
	}
	pOutStr[len-1] = '\0\0';

	wprintf(L"Str_Change %s\n", pOutStr);
	return(0);
}

//1.3 字符串数组作为参数
EXPORTDLL_CLASS int Str_ChangeArr( WCHAR **ppStr, int len )
{
	if (NULL == ppStr)
	{
		return(-1);
	}

	for (int ix=0; ix<len; ix++)
	{
		if (NULL != ppStr[ix])
		{
			lstrcpyn(ppStr[ix], L"abc", wcslen(ppStr[ix]));
		}
	}

	wprintf(L"Str_ChangeArr \n");
	return(0);
}

/************************************************************************/
/*                          2. 枚举类型                                   */
/************************************************************************/
//2.1 枚举类型作为输入参数
EXPORTDLL_CLASS int Enum_Output(DataEnum  type)
{
    wprintf(L"Enum_Output %d\n", type);

    return(0);
}

//2.2 枚举类型作为输出参数
EXPORTDLL_CLASS int Enum_Change(DataEnum  &type)
{
    type = DataEnum::DATA_WRITE;
    wprintf(L"Enum_Change %d\n", type);

    return(0);
}

/************************************************************************/
/*                          3. 结构体                                    */
/************************************************************************/
//4.1 结构体作为输入输出参数
EXPORTDLL_CLASS void Struct_Change( testStru1 *pStru )
{
	if (NULL == pStru)
	{
		return;
	}

	pStru->iVal = 1;
	pStru->cVal = 'a';
	pStru->llVal = 2;

	wprintf(L"Struct_Change \n");
}

//4.2 结构体边界对齐
EXPORTDLL_CLASS void Struct_PackN( testStru2 *pStru )
{
	if (NULL == pStru)
	{
		return;
	}

	pStru->iVal = 1;
	pStru->cVal = 'a';
	pStru->llVal = 2;

	wprintf(L"Struct_PackN \n");
}

//4.3 结构体中含有内置数据类型的数组
EXPORTDLL_CLASS void Struct_ChangeArr( testStru3 *pStru )
{
	if (NULL == pStru)
	{
		return;
	}

	pStru->iValArrp[0] = 8;
	lstrcpynW(pStru->szChArr, L"as", 30);

	wprintf(L"Struct_ChangeArr \n");
}

//4.4 union类型中含有结构体
EXPORTDLL_CLASS void Struct_Union( testStru4 *pStru )
{
	if (NULL == pStru)
	{
		return;
	}
	
	pStru->llLocation = 1024;
	wprintf(L"Struct_Union \n");
}

//4.5 结构体数组作为参数
EXPORTDLL_CLASS void Struct_StruArr( testStru5 *pStru, int len )
{
	if (NULL == pStru)
	{
		return;
	}

	for ( int ix=0; ix<len; ix++)
	{
		pStru[ix].iVal = ix;
	}

	wprintf(L"Struct_StruArr \n");
}