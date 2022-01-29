# WCF

## What

Windows Communication Foundation (WCF) is a framework for building service-oriented applications.

Using WCF, you can send data as asynchronous messages from one service endpoint to another.

A service endpoint can be part of a continuously available service hosted by IIS, or it can be a service hosted in an application.

An endpoint can be a client of a service that requests data from a service endpoint.

The messages can be as simple as a single character or word sent as XML, or as complex as a stream of binary data.

A few sample scenarios include,

- A secure service to process business transactions
- A service that supplies current data to others, such as a traffic report or other monitoring service
- A chat service that allows two people to communicate or exchange data in real time
- A dashboard application that polls one or more services for data and presents it in a logical presentation
- Exposing a workflow implemented using Windows Workflow Foundation as a WCF service.

While creating such applications was possible prior to the existence of WCF, WCF makes the development of endpoints easier than ever.

WCF is designed to offer a manageable approach to creating Web services and Web service clients.

## Features

### Service Orientation

One consequence of using WS standards is that WCF enables you to create service oriented applications. Service-oriented architecture (SOA) is the reliance on Web services to send and receive data.

The services have the general advantage of being loosely-coupled instead of hard-coded from one application to another.

A loosely-coupled relationship implies that any client created on any platform can connect to any service as long as the essential contracts are met.

### Interoperability

WCF implements modern industry standards for Web service interoperability. For more information about the supported standards, see, [Interoperability and Integration](https://docs.microsoft.com/en-us/dotnet/framework/wcf/feature-details/interoperability-and-integration).

### Multiple Message Patterns

For more information about how to implement different message exchange patterns using WCF see [Contracts](https://docs.microsoft.com/en-us/dotnet/framework/wcf/feature-details/contracts).

### Service Metadata

WCF supports publishing service metadata using formats specified in industry standards such as WSDL, XML Schema and WS-Policy.

### Data Contracts

WCF includes a comprehensive system for working with data in this easy manner.

Once you have created the classes that represent data, your service automatically generates the metadata that allows clients to comply with the data types you have designed.

For more information, see [Using Data Contracts](https://docs.microsoft.com/en-us/dotnet/framework/wcf/feature-details/using-data-contracts).

## Objects -> Services

1. OBject-oriented
   1. Polymorphism
   2. Encapsulation
   3. Sub Classing
2. Component-based
   1. Interface-based
   2. Dynamic loading
   3. Runtime metadata
3. Service-oriented
   1. Message-based
   2. Schema-contract
   3. Binding via policy

## The Challenge

- Different programming models for different tasks
- Need for security and reliable messaging
- Interoperability with applications on other platforms
- Productive service-oriented programming model needed

## Standard

- Windows Communication Foundation (WCF) is used to create a distributed and interoperable Application
- WCF is used to exchange messages using any format via any transport protocol like HTTP, TCP/IP, MSMQ, Named Pipes and and so on
- Its default format is SOAP
- A Web Service that can be consumed by different clients

## Why do we need WCF?

Why do we need WCF when we already have ASMX Web Services?

- **Problem**: Suppose we have two clients. One wants to use a Web Service, which sends data over the network, using Http protocol and want reply in XML format and the other wants to send the data using TCP protocol and replying in binary format

We’ll need to create two different services for two different clients

- **Solution**: WCF!

It allows you to develop applications that can communicate using different communication mechanisms

It can use any transport protocol like HTTP, TCP/IP, MSMQ, Named Pipes

It supports different hosting.

## Address, Binding, Contract

- Address: Where
- Binding: How
- Contract: What

## WCF Architecture: Messaging Runtime

- Client (Contract & Behaviors)
  - Protocol(s) (Binding)
  - Encoder (Binding)
  - Transport (Binding)
- Service (Contract & Behaviors)
- Dispatch (Contract & Behaviors)
  - Protocol(s) (Binding)
  - Encoder (Binding)
  - Transport (Binding)
- Transport (Address + Binding)

## Contracts

1. Service Contract
2. Data Contract
3. Message Contract
4. Fault Contract

### Service Contract

1. ServiceContract
2. OperationalContract

### Data Contract

1. DataContract
2. DataMember

### Message Contract

1. MessageContract
2. MessageHeader
3. MessageBody

### Descriptions

- Service Contract
  - Defines operations, behaviors and communication shape
  - What does your service do
- Data Contract
  - Defines schema and versioning strategies
  - What object data is used
- Message Contract
  - Allows defining application-specific headers and unwrapped body content
  - Allows control over the SOAP structure of messages

## Bindings

The ***How***.

- It describes the way or mechanism by which the user will communicate with Web Service

- It is nothing but a set of choices regarding the  transport protocol, message encoding, communication pattern (whether communication is asynchronous, synchronous,  message queued etc.), security protocols.

- WCF supports 9 bindings

## Bindings & Binding Elements

HTTP -> Text -> Security -> Reliability -> TX

1. HTTP,
   1. TCP
   2. HTTP
   3. MSMQ
   4. IPC
   5. Custom
2. Encoders,
   1. Text
   2. Binary
   3. Custom
3. Protocol,
   1. Security
   2. Reliability
   3. TX
   4. .NET
   5. Custom

## Ways To Talk

1. One Way,
   1. Datagram-style delivery
2. Request-Reply,
   1. Immediate Reply on same logical thread
3. Duplex,
   1. Reply "later" and on back-channel (callback-style)

## Hosting

- IIS Hosting
- Self Hosting
- WAS Hosting

## Resources

- [Lecture 11 | WCF](https://docs.google.com/presentation/d/1DamqD5AXpx02gnSZKOmJXrfgcGbs4UKi/edit#slide=id.p2)
- [Microsoft Docs - WCF](https://docs.microsoft.com/en-us/dotnet/framework/wcf/whats-wcf)
