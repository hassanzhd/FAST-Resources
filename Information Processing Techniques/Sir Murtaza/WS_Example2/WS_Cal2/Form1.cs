using System;
using System.Windows.Forms;

namespace WS_Cal2
{
    public partial class Form1 : Form
    {
        string Num1;
        string OperationToPerform = String.Empty;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            OperationButtonVisibility(false);
        }

        private void OperationButtonVisibility(bool isVisible)
        {
            //if (String.IsNullOrEmpty(OperationToPerform))
            btnAdd.Enabled = btnSubtract.Enabled = btnMultiple.Enabled = btnDivide.Enabled = isVisible;
        }


        private void btn1_Click(object sender, EventArgs e)
        {
            txtValue.Text += "1";
            OperationButtonVisibility(true);
        }

        private void btn2_Click(object sender, EventArgs e)
        {
            txtValue.Text += "2";
            OperationButtonVisibility(true);
        }

        private void btn3_Click(object sender, EventArgs e)
        {
            txtValue.Text += "3";
            OperationButtonVisibility(true);
        }

        private void btn4_Click(object sender, EventArgs e)
        {
            txtValue.Text += "4";
            OperationButtonVisibility(true);
        }

        private void btn5_Click(object sender, EventArgs e)
        {
            txtValue.Text += "5";
            OperationButtonVisibility(true);
        }

        private void btn6_Click(object sender, EventArgs e)
        {
            txtValue.Text += "6";
            OperationButtonVisibility(true);
        }

        private void btn7_Click(object sender, EventArgs e)
        {
            txtValue.Text += "7";
            OperationButtonVisibility(true);
        }

        private void btn8_Click(object sender, EventArgs e)
        {
            txtValue.Text += "8";
            OperationButtonVisibility(true);
        }

        private void btn9_Click(object sender, EventArgs e)
        {
            txtValue.Text += "9";
            OperationButtonVisibility(true);
        }

        private void btn0_Click(object sender, EventArgs e)
        {
            txtValue.Text += "0";
            OperationButtonVisibility(true);
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            Num1 = txtValue.Text;
            OperationToPerform = "Add";
            OperationButtonVisibility(false);
            txtValue.Text = "";
        }

        private void btnResult_Click(object sender, EventArgs e)
        {
            int number1 = 0, number2 = 0;
            int.TryParse(Num1, out number1);
            int.TryParse(txtValue.Text, out number2);

            //Calculator cal_Obj = new Calculator();
            //MyCalculator.MyCalculatorSoapClient cal_Obj = new MyCalculator.MyCalculatorSoapClient();
            MyCalculator.MyCalculatorSoap calculatorSoap = new MyCalculator.MyCalculatorSoapClient();
            
            switch (OperationToPerform)
            {
                case "Add":
                    txtValue.Text = calculatorSoap.Add(number1, number2).ToString();
                    break;
                case "Subtract":
                    txtValue.Text = calculatorSoap.Subtract(number1, number2).ToString();
                    break;
                case "Multiply":
                    txtValue.Text = calculatorSoap.Multiple(number1, number2).ToString();
                    break;
                case "Divide":
                    txtValue.Text = calculatorSoap.Divide(number1, number2).ToString();
                    break;
                default:
                    break;
            }

        }

        private void btnSubtract_Click(object sender, EventArgs e)
        {
            Num1 = txtValue.Text;
            OperationToPerform = "Subtract";
            OperationButtonVisibility(false);
            txtValue.Text = "";
        }

        private void btnMultiple_Click(object sender, EventArgs e)
        {
            Num1 = txtValue.Text;
            OperationToPerform = "Multiply";
            OperationButtonVisibility(false);
            txtValue.Text = "";
        }

        private void btnDivide_Click(object sender, EventArgs e)
        {
            Num1 = txtValue.Text;
            OperationToPerform = "Divide";
            OperationButtonVisibility(false);
            txtValue.Text = "";
        }
    }
}