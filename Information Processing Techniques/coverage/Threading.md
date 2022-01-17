# Threading

## Threads

- Thread is the fundamental unit of execution
- More than one thread can be executing code inside the same process (application)
- On a single-processor machine, the operating system is switching rapidly between the threads, giving the appearance of simultaneous execution

### Usefulness

- Responsive user interface while background tasks are executing
- Distinguish tasks of varying priority
- Perform operations that consume a large amount of time without stopping the rest of the application

### Advantages

- Timers
- UI Responsiveness
- Multiple Processors

### Dangers

- Race Conditions
- Deadlock

### Constructor

Delegate

## System.Threading Namespace

- Provides classes and interfaces that enable multi-threaded programming
- Consists of classes for synchronizing thread activities
- Chief among the namespace members isThread class

## Thread Class

- Implements various methods & properties that allows to manipulate concurrently running threads.
- Some of them are,
  - CurrentThread
  - IsAlive
  - IsBackground
  - Name
  - Priority
  - ThreadState

### Methods

- `Start()`
- `Suspend()`
- `Resume()`
- `Interrupt()`

## Synchronization Classes And Constructs

- `lock` keyword
- `Mutex` class
- `Monitor` class
- `Interlocked` class

## Monitor Class (static)

- `Enter`
- `Exit`
- `TryEnter`
- `Wait`
- `Pulse`
- `PulseAll`

## Thread Synchronization / Monitors

- Thread Synchronization
  - Threads must be coordinated to prevent data corruption
- Monitors
  - Monitors allow us to obtain a lock on a particular object and use that lock to restrict access to critical section of code
  - While a thread owns a lock for an object, no other thread can acquire that lock
  - Monitor.Enter(object) claims the lock but blocks if another thread already owns it
  - Monitor.Exit(object) releases the lock

## References

- [Lecture 10](https://docs.google.com/presentation/d/1T_b4bKKnizypwz3hevTWZjDUTsl0WP5p/edit#slide=id.p2)
- [Thread Class](https://docs.microsoft.com/en-us/dotnet/api/system.threading.thread?view=net-6.0)
