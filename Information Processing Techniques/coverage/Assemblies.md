# Assemblies

Assemblies form the fundamental units of,

- Deployment
- Version control
- Reuse
- Activation scoping
- Security permissions

For .NET-based applications.

An assembly is a collection of types and resources that are built to work together and form a logical unit of functionality.

Assemblies take the form of executable (.exe) or dynamic link library (.dll) files, and are the building blocks of .NET applications.

They provide the common language runtime with the information it needs to be aware of type implementations.

## EXE

An exe always runs in its own address space i.e., It is a separate process.

The purpose of an EXE is to launch a separate application of its own.

## DLL

1. A dll always needs a host exe to run. i.e., it can never run in its own address space.
2. The purpose of a DLL is to have a collection of methods/classes which can be re-used from some other application.
3. DLL is Microsoft's implementation of a shared library.
