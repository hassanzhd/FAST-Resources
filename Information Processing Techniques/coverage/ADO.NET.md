# ADO.NET

ADO.NET provides consistent access to data sources such as SQL Server and XML, and to data sources exposed through OLE DB and ODBC.

Data-sharing consumer applications can use ADO.NET to connect to these data sources and retrieve, handle, and update the data that they contain.

ADO.NET separates data access from data manipulation into discrete components that can be used separately or in tandem.

ADO.NET includes .NET Framework data providers for connecting to a database, executing commands, and retrieving results.

Those results are either processed directly, placed in an ADO.NET DataSet object in order to be exposed to the user in an ad hoc manner, combined with data from multiple sources, or passed between tiers.

## Query Syntax

### Connection And Create Table

```csharp
import using System.Data.SqlClient;

public void CreatTable()
{
    SqlConnection con = null;

    // Creating Connection with a connection string
    con = new SqlConnection("data source=.; database=student; integrated security=SSPI");

    // Writing SQL Query
    SqlCommand cm = new SqlCommand("Create table student(id int not null, name varchar(100), email varchar(50), join_date date)", con);

    // Opening Connection
    con.Open();

    // Executing the SQL query
    // Executes a Transact-SQL statement against the connection and returns the number of rows affected.
    cm.ExecuteNonQuery();

    // Displaying a message
    Console.WriteLine("Table created successfully");
}
```

### INSERT Record

```csharp
import using System.Data.SqlClient;

public void CreatTable()
{
    SqlConnection con = null;

    // Creating Connection with a connection string
    con = new SqlConnection("data source=.; database=student; integrated security=SSPI");

    // Writing SQL Query
    SqlCommand cm = new SqlCommand("insert into student (id, name, email, join_date) values (`101`, `Ronald Trump`, `ronald@example.com`, `1/12/2017`)", con);

    // Opening Connection
    con.Open();

    // Executing the SQL query
    // Executes a Transact-SQL statement against the connection and returns the number of rows affected.
    cm.ExecuteNonQuery();

    // Displaying a message
    Console.WriteLine("Table created successfully");
}
```

## LINQ vs ADO.NET

| ------------------------------- | ------------------------------- |
| ADO.NET                         | LINQ                            |
| ------------------------------- | ------------------------------- |
| It is part of .NET Framework    | It is part of the .NET          |
| Framework 1.0                   | framework since .NET framework  |
| ------------------------------- | ------------------------------- |
| SqlConnection/OleDbConnection   | We can use context for database |
| is used for database            | connectivity                    |
| connectivity                    |                                 |
| ------------------------------- | ------------------------------- |
| Difficult to debug and cause    | Easy to debug and cause syntax  |
| syntax errors at runtime        | errors at compile time          |
| ------------------------------- | ------------------------------- |

## Usage

- Entity Framework
- EDM
- Object Services
- LINQ To Entities
- Entity SQL
- EntityClient
- Entity Data Model Tools
- LINQ To SQL
- WCF Data Services

## Extension Methods

The DataSet, DataTable, and DataColumn all have an ExtendedProperties property. ExtendedProperties is a PropertyCollection where you can place custom information, such as the SELECT statement that was used to generate the result set, or the time when the data was generated. The ExtendedProperties collection is persisted with the schema information for the DataSet.

## References

- OLE DB (Object Linking & Embedding Database): A connectivity method similar to ODBC
- ODBC (Open Database Connectivity): Uses the same core application programming interface
