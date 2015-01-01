#ifndef AFXSTD_860013BE_C31D_4099_9995_6573EC72878A
#define AFXSTD_860013BE_C31D_4099_9995_6573EC72878A

#if _MSC_VER >= 1200
#pragma once
#endif //_MSC_VER >= 1200

#ifndef EXPORTDLL_EXPORTS
    #define EXPORTDLL_CLASS _declspec(dllimport)
#else
    #define EXPORTDLL_CLASS _declspec(dllexport)
#endif//!EXPORTDLL_EXPORTS


/************************************************************************/
/*                          1. 字符串                                    */
/************************************************************************/
//1.1 字符串作为输入参数
EXPORTDLL_CLASS int Str_Output(WCHAR *pInStr);

//1.2 字符串作为参数,需要进行修改返回
EXPORTDLL_CLASS int Str_Change(WCHAR *pOutStr);

//1.3 字符串数组作为参数
EXPORTDLL_CLASS int Str_ChangeArr(WCHAR **ppStr, int len);


/************************************************************************/
/*                          2. 枚举类型                                   */
/************************************************************************/
enum  DataEnum
{
    DATA_READ  = 0,
    DATA_WRITE,
};
//2.1 枚举类型作为输入参数
EXPORTDLL_CLASS int Enum_Output(DataEnum  type);

//2.2 枚举类型作为输出参数
EXPORTDLL_CLASS int Enum_Change(DataEnum  &type);


/************************************************************************/
/*                          3. 结构体                                    */
/************************************************************************/
//3.1 结构体作为输入输出参数
typedef struct _testStru1
{
	int		iVal;
	char	cVal;
	__int64 llVal;
}testStru1;
EXPORTDLL_CLASS  void Struct_Change(testStru1 *pStru);

//3.2 结构体边界对齐
#pragma pack(push)
#pragma pack(1)
typedef struct _testStru2
{
	int		iVal;
	char	cVal;
	__int64 llVal;
}testStru2;
#pragma pack(pop)
EXPORTDLL_CLASS  void Struct_PackN(testStru2 *pStru);

//3.3 结构体中含有内置数据类型的数组
typedef struct _testStru3
{
	int		iValArrp[30];
	WCHAR	szChArr[30];
}testStru3;
EXPORTDLL_CLASS  void Struct_ChangeArr(testStru3 *pStru);

//3.4 union类型中含有结构体
typedef union _testStru4
{
	int		iValLower;
	int		iValUpper;
	struct 
	{
		__int64 llLocation;
	};
}testStru4;
EXPORTDLL_CLASS  void Struct_Union(testStru4 *pStru);

//3.5 结构体数组作为参数
typedef struct _testStru5
{
	int		iVal;
}testStru5;
EXPORTDLL_CLASS  void Struct_StruArr(testStru5 *pStru, int len);


/************************************************************************/
/*                          4. 类                                        */
/************************************************************************/
class  EXPORTDLL_CLASS CAddSub
{
public:
    CAddSub(){
        m_len = 0;
    }
    ~CAddSub(){

    }

public:
    int  Add(int x, int y){
        return x+y;
    }

    int  Sub(int x, int y){
        return x-y;
    }

    int  GetLength()
    {
        return(m_len);
    }

    void  SetLength(int len){
        m_len = len;
    }

private:
    int   m_len;
};


#ifndef EXPORTDLL_EXPORTS
#pragma comment(lib, "ExportDll.lib")
#endif


#endif //!AFXSTD_860013BE_C31D_4099_9995_6573EC72878A