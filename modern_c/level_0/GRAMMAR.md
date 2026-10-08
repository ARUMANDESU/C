In getting-started.c we used these special words(keywords):
`#include`, `int`, `maybe_unused`, `char`, `void`, `doudle`, `for`, `return`

# Grammar

## Punctuation
There are 6 kinds of brackets: `{...}`, `(...)`, `[...]`, `[[...]]`, `/*...*/` and `<...>`.
Fortunately, the `<...>` brackets are rare in C.

`/*...*/` tells compiler that everything inside is a comment.
```c
/* This a one line comment. */
// Can also written as this. (This is C++ style comment)
/*
    This is a
    multiline comment.
*/
```

## Literals
Our program contains several items that refer to fixed values that are part of the program: `0`, `1`, `3`, `4`, `5`, `9.0`, `2.9`, `3.E+25`, `.00007`, and `"element %zu is %g, \tits square is %g\n"`. These are called literals.

## Identifiers

Identifiers are "names" that we (or the C standard) give to an entities in the program. For example: `A`, `i`, `main`, `printf`, `size_t`, `EXIT_SUCCESS`.

Another example:
```c
int count = 0;              // "count" identifies a variable
void reset(int *p) { ... }  // "reset" identifies a function, "p" a parameter
```

So we (or the C standard) gives name to entity, which is identifier, so we can refer to them later by that identifier.

What can we give identifiers to?
- varables
- functions
- types
- structs
- constants
- enums
- labels (for goto)


# Declaration
Before we may use(refer to) identifiers we should give a compiler a *declaration* that specifies what the identifier is supposed to represent.

Identifiers vs. Keywords
--
Keywords are predefined by the language, and must not be declared or redifined.

> [!Takeaway]
> All Identifiers in a program have to be declared

# Scope
Scope is a part of a program where an identifier is visible.

> [!Takeaway]
> Declarations are bound to the scope in which they appear.

> The first two and the last types of scope are called block scope with a block being a structure in the grammar that encapsulates such declarations. A function like main, together with its parameter list (enclosed in ()) and the whole body (enclosed in {}), forms a single block of its own. The for construct forms a primary block , and the loop body (usually also given with surrounding { . . . }) forms a secondary block . You can see that blocks are nested : the block of main contains the primary block of the for loop, which, in turn, contains its secondary block. The third type of scope, as used for the name main itself, which is not inside a ( . . . ) or { . . . } pair, is called file scope . Identifiers in file scope are often referred to as globals .

# Definitions
Generally, declarations only specify the kind of object an identifier refers to, not what concrete value of an identifier is, nor where the object it refers to can be found. This important role is filled by a **definition**.

> [!Takeaway]
> Declarations specify identifiers, whereas definitions specify objects.

For example:
```c
int some_func(void) {
    // this is declaration and definition: we specify identifier `a` with type int,
    // and note: for local variables compiler reserves storage,
    // thus `a` has already allocated memory (and not guaranteed that it's on stack, might be a CPU register).
    int a; // declaration & definition
    a = 2; // this is assignment
    return a;
}
```

## Assignment & Initialization
Assignment is an operation that stores a new value into an existing object.
Initialization is giving an object its first value as part of its definition.

Example:
```c
// local scope of function
int a; // declaration & definition
a = 2; // assignment: assigning 2 to variable `a`

int b = 3; // declaration & initialization(is part of definition)
```

> [!Takeaway]
> An object is defined at the same time it is initialized.

### array

A bit complex example:
```c
double A[5] = {
    [0] = 9.0,
    [1] = 2.9,
    [4] = 3.E+25,
    [3] = .00007
};
```
This initializes the 5 items in `A` to the values `9.0`, `2.9`, `.00007` and `3.E+25`.
The form of the initializer we see here is called *designated*: a pair of brackets with an integer designates which item of the array is initialized with the corresponding value. For example, `[4] = 3.E+25` sets the last item of the array `A` to the value `3.E+25`. As a special rule, any position that is not listed in the initializer is set to 0. In our example, the missing `[2]` is filled with `0.0`.

> [!Takeaway]
> Missing elements in initializers default to 0.

### function

For a function, we have a definition if its declaration is followed by braces `{...}` containing the code of the function (or body):
```c
// this is declaration: we tell compiler that there is function called add that returns int, and has two parameters: a, b, and both are int.
int add(int a, int b);

// this is definition: has a body
int add(int a, int b) {
    return a + b;
}

// declaration & definition
int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
...
}
```

> [!IMPORTANT]
> For C program to be operational any object (in our examples `a`, `b`, `A`) or function (`main`, `printf`, `add`) used must have a definition (otherwise, the execution would not know where to look for them), and there must be no more than 1 definition (otherwise, the execution could become inconsistent).

> [!Takeaway]
> Each object or function must have exactly one definition.

## Statements
Statements are instructions that tell the compiler what to do with the identifiers that have been declared so far.
