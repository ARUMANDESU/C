# Abstract state machine

What is abstract state machine?
Why do we need this concept of abstract state machine?

Check [./STATE_MACHINE.md](./STATE_MACHINE.md) first.

We have a C program, and this program can run on different platforms.
We give our program to compiler then it produces an executable binary file for a target platform.

> [!IMPORTANT]
> Program executes **as-if** following the abstract state machine.

In order to fully understand what this means, we should first get introduced to a Value, Type and Representation.

## State
What is the state?
At any moment while our program runs, it's in a state. Think of it like a snapshot of a program.
Statements move(change) the state of the program. More precisely, statements drive execution, and the side effects of their expressions change the data.
```c
int a = 1;      // state: a = 1
a = a + 2;      // state: a = 3
printf("%d", a); // state: a = 3, output = "3"
```

The state of program execution is determined by:
- The executable
- The current point of execution
- The data
- Outside intervention, such as the IO from the user

### Expressions & Statements
Statements are the steps of the machine. Each one moves the point of execution forward and decides where to go next. if and while are literally choosing the next transition.
Expressions compute values. Their intermediate results, like 7.5 in the book’s example, are usually not observable, which is why the compiler can fold them away.
Side effects are what actually change the data part of the state: assignments, `++`, output. The `;` at the end of an expression statement marks the point where those side effects must be complete before the next step begins.

## Observable state
Not all state counts as an observable: the output, plus the variables whose values are actually used later. In standard-C terms, they are I/O, data written to files, and volatile accesses. Everything else is free for the compiler to change.


## Value: What state are we in?
A value is abstract. It's an idea of the number, independent of how your machine stores it. Values are the same everywhere. `0` is `0` on every platform, `5.0 + 1.5` is `7.5`, and adding `0` to `x` gives `x`. What changes from platform to platform is how those values are represented, and sometimes a few results that depend on that representation, such as how big a size_t can get or how precise a double is.

> [!NOTE]
> In C All Values are numbers or translated to numbers

## Data
The data of program execution is all the values of all objects at a given moment.

## Type: What does this state represent?
A type is a property C attaches to every value. It is fixed at compile time
(statically determined).
- The type determines which operations are possible on a value.
- The type determines the result of every operation.
  Example: `7 / 2` is `3` (int), but `7.0 / 2` is `3.5` (double).
  Same "numbers", different types, different result.

## Representation: How is the state distinguished(stored)?

There are two levels:

### Binary representation (the model)
How values of a type are represented on a given platform, described by observable constants from the headers (`SIZE_MAX`, `INT_MAX`, `DBL_DIG`, ...).
- It determines the results of all operations.
  Example: for `size_t`, `SIZE_MAX + 1` wraps to `0`, and *where* that happens depends on `SIZE_MAX`.
- It is observable: your program can inspect it, so results are always deducible from the operand values plus these platform constants.

### Object representation (the actual bytes)
How the value really sits in memory or on disk (byte order, padding, ...).
Usually not your concern, unless you poke at raw memory or exchange data between different machines.



## Back to ASM
How all of these are connected?
**States** are snapshots: all data(values of all objects) plus current point of execution.
**Transition** are evaluating expressions and executing statements. Each one moves the program to a new state according to fixed rules.
**The rules** are determined only by value, type and binary representation. That's what makes it a well-defined machine.

It’s abstract because this machine exists only in the C specification and your program text. Nobody runs it directly. The compiler builds a different machine, the real executable on real hardware. That machine’s states are registers, cache lines and so on, and they look nothing like the abstract one.

The two machines are allowed to differ internally. The only requirement is that they produce the same observable behaviour: the same output, and the same contents of the variables that matter. That’s the as-if rule.
