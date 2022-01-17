using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using MVCExample.Models;

namespace MVCExample.Controllers
{
    public class UserController : Controller
    {
        // GET: User
        public ActionResult Purchase()
        {
            var currView = new User { name = "Ali", userID = "U123" };
            return View();
        }
    }
}