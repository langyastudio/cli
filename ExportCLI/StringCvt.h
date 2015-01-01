#ifndef AFX_STD_9E4DD083_59FA_4C0F_9638_65FB0992BAB8_INCLUDE
#define AFX_STD_9E4DD083_59FA_4C0F_9638_65FB0992BAB8_INCLUDE

#if _MSC_VER >= 1200
#pragma  once
#endif //!_MSC_VER >= 1200

using namespace System;
using namespace System::Runtime::InteropServices;

#include <string>
using namespace std;


//托管字符串转非托管的Unicode字符串
//返回的值需要释放内存
wchar_t *ManagedStr2UnmanagedUniStr(String^ str);

//非托管字符串转托管的Unicode字符串
String ^ UnmanagedStr2ManagedUniStr(wchar_t *str);


#endif //!AFX_STD_9E4DD083_59FA_4C0F_9638_65FB0992BAB8_INCLUDE

