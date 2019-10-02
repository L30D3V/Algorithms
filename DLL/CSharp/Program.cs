using System;
using System.Runtime.InteropServices;

namespace DLL
{
    class Program
    {
        [DllImport("dll/DllFromScratch.dll")]
        private static extern int dll_double(int a);

        static void Main(string[] args)
        {
            Console.WriteLine("---- PDF Management ----");
            Console.WriteLine(dll_double(2));
        }
    }
}
