using System;
using System.Runtime.InteropServices;

namespace DLL
{
    class Program
    {
        [DllImport("dll/DllTest.dll")]
        private static extern void fibonacci_init(ulong a, ulong b);
        [DllImport("dll/DllTest.dll")]
        private static extern bool fibonacci_next();
        [DllImport("dll/DllTest.dll")]
        private static extern ulong fibonacci_current();

        static void Main(string[] args)
        {
            Console.WriteLine("---- Fibonacci Sequence ----");

            fibonacci_init(1, 1);

            for(int i = 0; i < 100; i++) {    
                fibonacci_next();

                Console.Write(fibonacci_current() + " ");
            }
        }
    }
}
