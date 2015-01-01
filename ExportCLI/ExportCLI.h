#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

#include "ExportDllAPI.h"
#include "StringCvt.h"

namespace ExportCLI {

    /// <summary>
    /// 1 字符串测试类
    /// </summary>
	public ref class StrCls
	{
    public:
        /// <summary>
        /// 1.1 字符串作为输入参数
        /// </summary>
        /// <param name="pInStr">字符串</param>  
        /// <returns>成功返回0</returns> 
        static Int32 StrOutput(String^ pInStr);       
        /// <summary>
        /// 1.2 字符串作为参数,需要进行修改返回
        /// </summary>
        /// <param name="pOutStr">字符串</param>  
        /// <returns>成功返回0</returns> 
        static Int32 StrChange(String^ %pOutStr);        
        /// <summary>
        /// 1.3 字符串数组作为参数
        /// </summary>
        /// <param name="ppStr">字符串数组</param>  
        /// <returns>成功返回0</returns> 
        static Int32 StrChangeArr(array<String^>^ %ppStr);
	};

    /// <summary>
    /// 枚举类型
    /// </summary>
    [Serializable]
    [FlagsAttribute]
    public enum class DataType
    {
        READ  = 0,
        WRITE,
    };
    /// <summary>
    /// 2 枚举类型测试类
    /// </summary>
    public ref class EnumCls
    {
    public:        
        /// <summary>
        /// 2.1 枚举类型作为输入参数
        /// </summary>
        /// <param name="type">枚举类型</param>  
        /// <returns>成功返回0</returns> 
        static Int32 EnumOutput(DataType  type);
        /// <summary>
        /// 2.2 枚举类型作为输出参数
        /// </summary>
        /// <param name="type">枚举类型</param>  
        /// <returns>成功返回0</returns> 
        static Int32 EnumChange(DataType  %type);
    };

    [Serializable]
    public ref struct test1
    {
        Int32	iVal;
        SByte   cVal;
        Int64   llVal;

        void UnmanagedPtr2ManagedStru(IntPtr ptr)
        {
            testStru1 *ptStru = static_cast<testStru1 *>(ptr.ToPointer());
            if (NULL == ptStru)
                return;

            iVal = ptStru->iVal;
            cVal = ptStru->cVal;
            llVal= ptStru->llVal;
        }
    };

    [Serializable]
    [StructLayoutAttribute(LayoutKind::Sequential, Pack=1)]
    public ref struct test2
    {
        Int32	iVal;
        SByte	cVal;
        Int64   llVal;

        void UnmanagedPtr2ManagedStru(IntPtr ptr)
        {
            testStru2 *ptStru = static_cast<testStru2 *>(ptr.ToPointer());
            if (NULL == ptStru)
                return;

            iVal = ptStru->iVal;
            cVal = ptStru->cVal;
            llVal= ptStru->llVal;
        }
    };    

    [Serializable]
    public ref struct test3
    {
        array<Int32>^	iValArrp;
        array<Char>^	szChArr;

        test3()
        {
            iValArrp = gcnew array<Int32>(30);
            szChArr  = gcnew array<WCHAR>(30);
        }

        void UnmanagedPtr2ManagedStru(IntPtr ptr)
        {
            testStru3 *ptStru = static_cast<testStru3 *>(ptr.ToPointer());
            if (NULL == ptStru)
                return;

            for (int ix=0; ix<30; ix++)
            {
                iValArrp[ix] = ptStru->iValArrp[ix];
                szChArr[ix]  = ptStru->szChArr[ix];
            }
        }
    };
    
    [Serializable]
    [StructLayoutAttribute(LayoutKind::Explicit)]
    public ref struct test4
    {    
        [FieldOffsetAttribute(0)]
        Int32		iValLower;
        [FieldOffsetAttribute(4)]
        Int32		iValUpper;  
        [FieldOffsetAttribute(0)]
        Int64       llLocation; 

        void UnmanagedPtr2ManagedStru(IntPtr ptr)
        {
            testStru4 *ptStru = static_cast<testStru4 *>(ptr.ToPointer());
            if (NULL == ptStru)
                return;

            llLocation = ptStru->llLocation;
        }
    };

    [Serializable]
    public ref struct test5
    {
        Int32		iVal;

        test5()
        {
            iVal = 5;
        }
    };
    /// <summary>
    /// 3 结构体测试类
    /// </summary>
    public ref class StructCls
    {
    public:     
        /// <summary>
        /// 3.1 结构体作为输入输出参数
        /// </summary>
        /// <param name="pStru">结构体</param>  
        static void StructChange(test1^ %pStru);
        /// <summary>
        /// 3.2 结构体边界对齐
        /// </summary>
        /// <param name="pStru">结构体</param>  
        static  void StructPackN(test2^ %pStru);
        /// <summary>
        /// 3.3 结构体中含有内置数据类型的数组
        /// </summary>
        /// <param name="pStru">结构体</param>  
        static  void StructChangeArr(test3^ %pStru);
        /// <summary>
        /// 3.4 union类型中含有结构体
        /// </summary>
        /// <param name="pStru">结构体</param>  
        static  void StructUnion(test4^ %pStru);
        /// <summary>
        /// 3.5 结构体数组作为参数
        /// </summary>
        /// <param name="pStru">结构体数组</param>  
        static  void StructStruArr(List<test5^>^ pStru);              
    };

    /// <summary>
    /// 4 类测试
    /// </summary>
    public ref class AddSubCls
    {
    public:        
        AddSubCls()
        {
            m_pCls = new CAddSub();
        }

        !AddSubCls() //确定性释放
        {
            delete m_pCls;
        }

        ~AddSubCls() //非确定性释放
        {
            this->!AddSubCls();
        }

    public:
        Int32  Add(Int32 x, Int32 y)
        {
            return(m_pCls->Add(x, y));   
        }

        Int32  Sub(Int32 x, Int32 y)
        {
            return(m_pCls->Sub(x, y));  
        }

        property Int32 Length
        {
            Int32 get()
            {
                return(m_pCls->GetLength());
            }

            void set(Int32 len)
            {
                m_pCls->SetLength(len);
            }
        }
        
    private:
        CAddSub     *m_pCls;
    };
}
