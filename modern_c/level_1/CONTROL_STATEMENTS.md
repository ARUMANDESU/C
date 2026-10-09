# Control Statements

C has 5 _control statements_: `if`, `for`, `do`, `while`, and `switch`.


## if
`if` introduces a conditional execution depending on a Boolean expression.
```c
if (i > 25) {
    j = i - 25;
}
```
In this example, `i > 25` is called **controlling expression**, and the part in `{...}` is called the **secondary block**.

There is more general form of `if` construct:
```c
if (i > 25) {
    j = i - 25;
} else {
    j = i;
}
```
It has another **secondary block** that is executed if the controlling condition is not fulfilled.

The `if` (...) ... `else` ... is a selection statement . It selects one of the two possible code paths according to the contents of ( ... ).
```
if (condition) secondary-block0
else secondary-block1
```

### numeric condition
```c
if (i) {
    j = i;
}
```
if i is 0 then condition is false
if i is not 0 then condition is true
=> The value `0` represents logical `false`, and any value different from `0` represents logical `true`.
