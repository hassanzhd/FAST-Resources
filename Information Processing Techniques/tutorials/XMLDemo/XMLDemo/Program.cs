using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace XMLDemo
{
    class MyXML
    {
        static void Main(string[] args)
        {
            MyXML o = new MyXML();
            //o.CreateWrite();
            //o.OpenWrite();
            //o.OpenRead();
            //o.DeleteElement();
        }

        ///////////// Create a new XML file and write in it ///////////////////
        void CreateWrite()
        {
            //Declare a new XMLDocument object
            XmlDocument doc = new XmlDocument();
            XmlDeclaration xmlDeclaration = doc.CreateXmlDeclaration("1.0", "UTF-8", null);

            //Add the document header before root (works regardless of root already existing)
            XmlElement root = doc.DocumentElement;
            doc.InsertBefore(xmlDeclaration, root);
            
            // Add root element now
            XmlElement element1 = doc.CreateElement(string.Empty, "Mainbody", string.Empty);
            doc.AppendChild(element1);

            //  Add two new elements
            XmlElement element2 = doc.CreateElement(string.Empty, "level1", string.Empty);
            XmlElement element3 = doc.CreateElement(string.Empty, "level2", string.Empty);

            XmlText text1 = doc.CreateTextNode("Demo Text");

            // These functions define which elements go under which other elements
            element1.AppendChild(element2);
            element2.AppendChild(element3);
            element3.AppendChild(text1);

            // Adding another element
            XmlElement element4 = doc.CreateElement(string.Empty, "level2", string.Empty);
            XmlText text2 = doc.CreateTextNode("other text");
            element4.AppendChild(text2);
            element2.AppendChild(element4);

            // Saving XML file
            doc.Save(@"D:\IPT\XML Docs\XMLTest.xml");
        }

        /// <summary>
        /// ////////// Open an XML file and write data in it ///////////
        /// </summary>
        void OpenWrite()
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(@"D:\IPT\XML Docs\XMLTest2.xml");

            XmlNode root = doc.SelectSingleNode("Students");

            XmlElement student = doc.CreateElement("Student");
            root.AppendChild(student);

            XmlElement name = doc.CreateElement("Name");
            name.InnerText = "Ubaid";
            student.AppendChild(name);

            XmlElement id = doc.CreateElement("ID");
            id.InnerText = "k103539";
            student.AppendChild(id);

            // Save the XML file after changes
            doc.Save(@"D:\IPT\XML Docs\XMLTest2.xml");
        }

        ////////// Open an XML file and read from it /////////////
        ///
        void OpenRead()
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(@"D:\IPT\XML Docs\XMLTest3.xml"); // Open an existing XML file

            // Create a list of nodes and give XPATH to pin-point which nodes to add to this list
            XmlNodeList nodes = doc.SelectNodes("//Students/Student");

            // For every node in the list
            foreach(XmlNode node in nodes)
            {
                // Picking one node at each iteration
                XmlNode name = node.SelectSingleNode("Name");
                if (name != null)
                    Console.WriteLine("Student Name: " + name.InnerText); // Printing name i.e. inner text between Name element

                XmlNode id = node.SelectSingleNode("ID");
                if (id != null)
                    Console.WriteLine("ID: " + id.InnerText + "\n"); // Same as explained for Name
            }
        }

        ////////////// Delete a node from a XML file //////////////
        void DeleteElement()
        {
            // This function works exactly the same way
            // except it doesn't print the inner text
            // and rather deletes the node
            XmlDocument doc = new XmlDocument();
            doc.Load(@"D:\IPT\XML Docs\XMLTest3.xml");

            XmlNodeList nodes = doc.SelectNodes("//Students/Student");
            foreach (XmlNode node in nodes)
            {
                XmlNode name = node.SelectSingleNode("Name");
                if (name.InnerText == "Ali")
                    node.ParentNode.RemoveChild(node); //  Notice how indirect referencing works here
            }

            // Saving XML after changes
            doc.Save(@"D:\IPT\XML Docs\XMLTest4.xml");
        }
    }
}
