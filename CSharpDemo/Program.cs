using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using ExportCLI;
using System.Runtime.InteropServices;

namespace CSharpDemo
{ 
    class Program
    {
        static void Main(string[] args)
        {
            //1. 字符串测试类
            string pInStr = "1.1";
            StrCls.StrOutput(pInStr);

            string pOutStr = "1.2";
            StrCls.StrChange(ref pOutStr);

            string[] ppStr = new string[2] { "1.31.......", "1.32......." };
            StrCls.StrChangeArr(ref ppStr);

            //2. 枚举类型测试类
            DataType tEnum = DataType.READ;

            EnumCls.EnumOutput(tEnum);
            EnumCls.EnumChange(ref tEnum);

            //3. 结构体测试类
            test1  tStru1 = new test1();
            tStru1.iVal  = 0;
            tStru1.cVal  = 0;
            tStru1.llVal = 0;
            StructCls.StructChange(ref tStru1);

            test2 tStru2 = new test2();
            tStru2.iVal  = 0;
            tStru2.cVal  = 0;
            tStru2.llVal = 0;
            int size = Marshal.SizeOf(tStru2.GetType());
            StructCls.StructPackN(ref tStru2);

            test3 tStru3 = new test3();
            tStru3.iValArrp[0] = 55;
            tStru3.szChArr[1] = '1';
            StructCls.StructChangeArr(ref tStru3);

            test4 tStru4 = new test4();
            tStru4.llLocation = 44444444444;
            StructCls.StructUnion(ref tStru4);

            List<test5> tStru5 = new List<test5>(0);
            tStru5.Add(new test5());
            StructCls.StructStruArr(tStru5);

            //4. 类测试
            AddSubCls addSubCls = new AddSubCls();
            int sum = addSubCls.Add(1, 4);
            addSubCls.Length = 6;
        }
    }
}
