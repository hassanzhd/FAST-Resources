using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WS_Cal1
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1, num2, operation = -1;

            while (operation != 0)
            {
                Console.Write("Enter Number 1:");
                num1 = GetInput();

                Console.Write("Enter Number 2:");
                num2 = GetInput();

                PrintMenu();
                Console.Write("Select your choice:");
                operation = GetInput();

                MyCalculatorService.MyCalculatorSoapClient myCalculator = new MyCalculatorService.MyCalculatorSoapClient();
                if(operation == 1)
                {
                    Console.WriteLine(myCalculator.Add(num1, num1));
                }
                

                //MyCalculator.MyCalculatorSoapClient cal_Obj = new MyCalculator.MyCalculatorSoapClient();

                //switch (operation)
                //{
                //    case 0:
                //        Console.WriteLine("Terminating...");
                //        break;
                //    case 1:
                //        Console.WriteLine("Answer : {0}", cal_Obj.Add(num1, num2));
                //        break;
                //    case 2:
                //        Console.WriteLine("Answer : {0}", cal_Obj.Subtract(num1, num2));
                //        break;
                //    case 3:
                //        Console.WriteLine("Answer : {0}", cal_Obj.Multiple(num1, num2));
                //        break;
                //    case 4:
                //        Console.WriteLine("Answer : {0}", cal_Obj.Divide(num1, num2));
                //        break;
                //    default:
                //        Console.WriteLine("Invalid selection");
                //        break;
                //}
            }

            Console.ReadLine();
        }

        public static void PrintMenu()
        {
            Console.WriteLine("Press 1 to Add");
            Console.WriteLine("Press 2 to Subtract");
            Console.WriteLine("Press 3 to Multiple");
            Console.WriteLine("Press 4 to Divide");
            Console.WriteLine("Press 0 to Exit");
        }
        public static int GetInput()
        {
            int returnVal = 0;
            string input = Console.ReadLine();
            int.TryParse(input, out returnVal);
            return returnVal;
        }

    }
}
