using System;
using System.Runtime.InteropServices;

namespace DLL
{
    class Program
    {
        [DllImport("dll/DllFromScratch.dll")]
        private static extern void hello_world();
        [DllImport("dll/DllFromScratch.dll")]
        private static extern int hello_number();
        [DllImport("dll/DllFromScratch.dll")]
        private static extern int new_test();

        static void Main(string[] args)
        {
            Console.WriteLine("---- PDF Management ----");
            hello_world();
            Console.WriteLine(hello_number());
            Console.WriteLine(new_test());
        }
    }
}
