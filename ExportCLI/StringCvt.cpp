#include "Stdafx.h"
#include "StringCvt.h"

//返回的值需要释放内存
wchar_t *ManagedStr2UnmanagedUniStr(String^ str)
{
    IntPtr p = Marshal::StringToHGlobalUni(str);
    if (p == IntPtr::Zero)
        return(NULL);

    const wchar_t *pTemp = static_cast<const wchar_t *>(p.ToPointer());
    if (pTemp == NULL) return NULL;

    size_t  len = wcslen(pTemp) + 1;
    wchar_t *pOut = new wchar_t[len];

    wcscpy_s(pOut, len, pTemp);

    Marshal::FreeHGlobal(p);
    return(pOut);
}

//非托管字符串转托管的Unicode字符串
String ^ UnmanagedStr2ManagedUniStr(wchar_t *str)
{
    return Marshal::PtrToStringUni((IntPtr)str);
}

