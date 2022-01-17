# Windows Services

## What

- A Windows service is a long-running program
- It is designed to run as a background task with no interaction with the screen
- UNIX calls these processes daemons
- They often implement key system tasks such as,
  - Anti Virus
  - Indexing
  - DNS
  - Time Synchronization
  - SSH
  - HTTP
  - IIS

## View

- Command Prompt
- Task Manage
- Services Manager
- Computer Manager

## ServiceBase Class

- The ServiceBase class is in the System.Service.Process namespace
- All services are derived from this class
- It provides several methods which should be overloaded to define the actions of the service

```csharp
void onStart(string[] args)
```

This is sent by the system when the service is started

Normally, the work performed by the service will be done by this method

```csharp
void OnPause()
```

Called when the service is paused

A service is usually resumed after a pause and it is not necessary to release all resources held by the service.

```csharp
void OnContinue()
```

This resumes normal processing after the service has been paused.

```csharp
void OnStop()
```

This attempts to stop the service.

The service might be started again at a later time.

## Properties

- `ServiceName`,
  - Allows the name o the service to be set or retrieved
- `CanStop`,
  - Boolean indicating whether the service can be stopped

## Sample Service

- We will now write a sample service
- We must provide,
  - A service
  - A main program for the service
  - A service installer
- Our sample service will periodically write the time to a file

## Installing The Service

- Before your can install the service, you must write an installer
- This extends System.Configuration.Install.Installer
- It is included in the same assembly as the service it should install
- It installs the service by using the service name, which must be set in the service

## Installing / Uninstall The Service

- To install the service use `installutil` which is located in `C:\WINDOWS\Microsoft.NET\Framework\<version>`.
- To uninstall the service, use `installutil` /u `<service.exe>`.

## Windows Service v/s Task Scheduler

| ------------------------------- | ------------------------------- |
| Windows Service                 | Task Scheduler                  |
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
