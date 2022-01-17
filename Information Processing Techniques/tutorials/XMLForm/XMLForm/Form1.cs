using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;
using System.IO;

namespace XMLForm
{
    public partial class Form1 : Form
    {
        // We need to Serialize the object in order to write it to XML file
        XmlSerializer xs; // This provides us with the necessary stuff to do it

        List<User> ls; // A simple list to store several objects of User class
        public Form1()
        {
            InitializeComponent();

            ls = new List<User>(); // Initalize list
            xs = new XmlSerializer(typeof(List<User>)); // Initialize our Serializer

        }

        private void button1_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream("D:\\IPT\\XML Docs\\Webusers.xml", FileMode.Create, FileAccess.Write);
            // Creating a simple object with input values (provided by user via WinForm)
            User ob = new User();
            ob.email = textBox1.Text;
            ob.username = textBox2.Text;


            ls.Add(ob); // Add that object to list (it may contain more than one objects)
            xs.Serialize(fs, ls); // Write it in file

            fs.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            FileStream fs = new FileStream("D:\\IPT\\XML Docs\\Webusers.xml", FileMode.Open, FileAccess.Read);
            ls = (List<User>)xs.Deserialize(fs); // Read the object from file after Deserializing it

            //  OPTIONAL: Display the read data to Gridview control
            dataGridView1.DataSource = ls;

            fs.Close();
        }
    }
}
