# Expression
An expression is something that produces a value. An expression is a combination of values, variables, operators and function calls that evaluates to a value of some type:
```c
5.0             // value 5.0, type double
x               // the current value of x
x * 1.5         // value 7.5 (if x is 5.0)
a > b           // value 0 or 1, type int
printf("hi\n")  // value 3, the number of characters printed (int)
a = 3           // value 3, and also stores 3 in a
```
Experssions nest.
```c
x = (x * 1.5) - y
```
is one big expression built from the subexpressions `x`, `x * 1.5`, `y`, `7.5 - 3.0` and the assignment

Some expressions also have side effects: they change state besides producing a value. Assignment `a = 3` has the value `3` and changes `a`. That’s why `b = a = 3;` works: `a = 3` is an expression whose value gets assigned to `b`. Other examples are `i++` and `printf(...)`, which writes output.

# Statement
A statement is something that gets executed: it's a step in the program, and it has no value of its own.
A statement is a unit of execution. It doesn't produce a value; it **does** something or **controls flow**.

The main kinds are:
- Expression statement: any expression followed by ;, for example x = x + 1; or printf("hi\n");. The value is thrown away, and only the side effects matter.
- Compound statement (block): { ... }, which groups statements into one.
- Selection: if, switch.
- Iteration: for, while, do ... while.
- Jump: return, break, continue, goto.


Statements are the steps of the machine. Each one moves the point of execution forward and decides where to go next. if and while are literally choosing the next transition.
Expressions compute values. Their intermediate results, like 7.5 in the book’s example, are usually not observable, which is why the compiler can fold them away.
Side effects are what actually change the data part of the state: assignments, ++, output. The ; at the end of an expression statement marks the point where those side effects must be complete before the next step begins.
