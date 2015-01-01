#include "stdafx.h"
#include "ExportCLI.h"

System::Int32 ExportCLI::StrCls::StrOutput( String^ pInStr )
{
    if (String::IsNullOrEmpty(pInStr))
    {
        return(-1);
    }

    WCHAR   *pStr = ManagedStr2UnmanagedUniStr(pInStr);
    HRESULT  hr   = Str_Output(pStr);

    //内存释放
    if (NULL != pStr)
    {
        delete []pStr;
        pStr = NULL;
    }

    return(hr);
}

System::Int32 ExportCLI::StrCls::StrChange( String^ %pOutStr )
{
    if (String::IsNullOrEmpty(pOutStr))
    {
        return(-1);
    }

    WCHAR   *pStr = ManagedStr2UnmanagedUniStr(pOutStr);
    HRESULT  hr   = Str_Change(pStr);

    pOutStr = UnmanagedStr2ManagedUniStr(pStr);

    //内存释放
    if (NULL != pStr)
    {
        delete []pStr;
        pStr = NULL;
    }

    return(hr);
}

System::Int32 ExportCLI::StrCls::StrChangeArr( array<String^>^ %ppStr )
{
    if (ppStr == nullptr)
    {
        return(-1);
    }

    int     len  = ppStr->Length; //数据元素的个数
    WCHAR   **pp = new WCHAR *[len];

    for (int ix=0; ix<len; ix++)
    {
        pp[ix] = ManagedStr2UnmanagedUniStr(ppStr[ix]);
    }
    HRESULT  hr   = Str_ChangeArr(pp, len);
    for (int ix=0; ix<len; ix++)
    {
        ppStr[ix] = UnmanagedStr2ManagedUniStr(pp[ix]);
    }

    //内存释放
    for (int ix=0; ix<len; ix++)
    {
        delete [](pp[ix]);
        pp[ix] = NULL;
    }
    delete []pp;
    pp = NULL;

    return(hr);
}

System::Int32 ExportCLI::EnumCls::EnumOutput( DataType type )
{
    return( Enum_Output(safe_cast<DataEnum>(type)) );
}

System::Int32 ExportCLI::EnumCls::EnumChange( DataType %type )
{
    DataEnum   t;
    HRESULT hr = Enum_Change(t);
    type = safe_cast<DataType>(t);
    
    return(hr);
}

void ExportCLI::StructCls::StructChange( test1^ %pStru )
{
    if (pStru == nullptr)
    {
        return;
    }

    testStru1  strT;

    strT.iVal = pStru->iVal;
    strT.cVal = pStru->cVal;
    strT.llVal = pStru->llVal;

    Struct_Change(&strT);
    pStru->UnmanagedPtr2ManagedStru(IntPtr(&strT));
}

void ExportCLI::StructCls::StructPackN( test2^ %pStru )
{
    if (pStru == nullptr)
    {
        return;
    }

    testStru2  strT;

    strT.iVal = pStru->iVal;
    strT.cVal = pStru->cVal;
    strT.llVal = pStru->llVal;

    Struct_PackN(&strT);
    pStru->UnmanagedPtr2ManagedStru(IntPtr(&strT));
}

void ExportCLI::StructCls::StructChangeArr( test3^ %pStru )
{
    if (pStru == nullptr)
    {
        return;
    }

    testStru3  strT;
    for (int ix=0; ix<pStru->iValArrp->Length; ix++)
    {
        strT.iValArrp[ix] = pStru->iValArrp[ix];
        strT.szChArr[ix] = pStru->szChArr[ix];
    }

    Struct_ChangeArr(&strT);
    pStru->UnmanagedPtr2ManagedStru(IntPtr(&strT));
}

void ExportCLI::StructCls::StructUnion( test4^ %pStru )
{
    if (pStru == nullptr)
    {
        return;
    }

    testStru4  strT;
    strT.llLocation = pStru->llLocation;

    Struct_Union(&strT);
    pStru->UnmanagedPtr2ManagedStru(IntPtr(&strT));
}

void ExportCLI::StructCls::StructStruArr( List<test5^>^ pStru )
{
    if (pStru == nullptr)
    {
        return;
    }

    int        len      = pStru->Count;
    testStru5 *pStruArr = new testStru5[len];

    for (int ix=0; ix<len; ix++)
    {
        pStruArr[ix].iVal = pStru[ix]->iVal;
    }

    Struct_StruArr(pStruArr, len);

    //内存释放
    if (NULL != pStruArr)
    {
        delete []pStruArr;
        pStruArr = NULL;
    }
}
