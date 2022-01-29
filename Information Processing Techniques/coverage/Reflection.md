# Reflection

Reflection is the feature in .NET, which enables us to get some information about object in runtime.

Information can be,

- Data of the class
- Names of the methods
- Constructors of that object

It provides features such as,

- Objects (of type Type) that describe `assemblies`, `modules`, and `types`
- You can use reflection to,
  - Dynamically create an instance of a type
  - Bind the type to an existing object
  - Get the type from an existing object
  - Invoke its methods or access its fields and properties
  - If you are using attributes in your code, reflection enables you to access them.

## Uses Of Reflection

- Explore assembly metadata
- Creating objects dynamically
- Invoking methods dynamically
- Write `generic` code that works with different types
- Implement sophisticated programming techniques
- Highly dynamic and language independent
- Types may be extended and built at run-time
- Allows on-the-fly creation of assemblies
- .NET compilers use .NET to emit .NET code

## Metadata

- Single location for type information and code
- Types' metadata can be explored with reflection
- Code is literally obtained within type information
- Every .NET object can be queried for its type
- `Structural metadata` is about the design and specification of data structures and is more properly called "data about the containers of data";
- `Descriptive metadata`, on the other hand, is about individual instances of application data, the data content.

## Questions

1. Where are the information and the code stored?
2. What does the meta data include?
3. What do you mean by `generic` code using reflection?
4. How are assemblies created with reflections?
5. How closely coupled are the concepts of Reflection with language dependency?

## Answers

1. They are stored together - the code can literally be found within the type information
2. 