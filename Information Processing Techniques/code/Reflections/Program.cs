using System.Reflection;

Users users = new Users("Saif", 22);

Type type = users.GetType();

Console.WriteLine("{0}, {1}, {2}, {3}, {4}" ,users.GetType().ToString(), users.Age.GetType().ToString(), users.Name.GetType().ToString(), users.title.GetType().ToString(), users.CalculatePenalty(2, 2).GetType().ToString());

public class Users
{
    int address;
    public string title;
    public string Name { get; set; }
    public int Age { get; set; }
    public Users(string name, int age)
    {
        Name = name;
        Age = age;
        address = 0;
        title = "";
    }
    public void GetUserDetails()
    {
        Console.WriteLine("Name: {0}, Age: {1}", Name, Age);
    }
    public float CalculatePenalty(float debt, int months)
    {
        return debt * months;
    }
    public void Work(float accuracy, string dept)
    {
        // some code
    }
}
