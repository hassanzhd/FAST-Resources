using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Linq;
using System.ServiceProcess;
using System.Text;
using System.Threading.Tasks;
using System.Timers;
using System.IO;

namespace ServiceDemo
{
    public partial class Service1 : ServiceBase
    {
        Timer tmr = new Timer();
        public Service1()
        {
            
            InitializeComponent();
        }

        protected override void OnStart(string[] args)
        {
            WriteLog("Service started at: " + DateTime.Now);
            tmr.Elapsed += new ElapsedEventHandler(OnElapsedTime);
            tmr.Interval = 5000;
            tmr.Enabled = true;
        }

        protected override void OnStop()
        {
            WriteLog("Service stopped at: " + DateTime.Now);
        }

        private void OnElapsedTime(Object source, ElapsedEventArgs e)
        {
            WriteLog("Service restarted at: " + DateTime.Now);
        }

        public void WriteLog(string txt)
        {
            string dirPath = AppDomain.CurrentDomain.BaseDirectory + "\\Log";
            if (!Directory.Exists(dirPath))
                Directory.CreateDirectory(dirPath);

            string filePath = AppDomain.CurrentDomain.BaseDirectory + "\\Log\\file" + DateTime.Now.Date.ToShortDateString().Replace('/', '_') + ".txt";
            if(!File.Exists(filePath))
            {
                using (StreamWriter sw = File.CreateText(filePath))
                {
                    sw.WriteLine(txt);
                }
            }
            else
            {
                using (StreamWriter sw = File.AppendText(filePath))
                {
                    sw.Write(txt);
                }
            }
        }
    }
}
