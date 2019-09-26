using System;
using System.Runtime.InteropServices;

namespace CppBind
{
    class Program
    {
        [DllImport(@"cpp/")]
        public static extern void writePNGData();        
        
        static void Main(string[] args)
        {
            writePNGData();
        }
    }
}