Basic understanding learnt from [this article](http://web.archive.org/web/20200121100942/https://blog.felixangell.com/virtual-machine-in-c/)

## Instruction set

- Registers : `A`, `B`, `C`, `D`, `E`, `F` are _general purpose_

- Virtual memory is a _stack based virtual mem_

Example implementation
```
PSH 5           ; Push 5 to the stack
PSH 10          ; Push 10 to the stack
ADD             ; Pop 2 values from the stack and add them
stack
POP             ; Pop the result from the stack and prints it
debugging
SET A 0         ; Set register A to 16
HLT             ; Halt the program
```

## Program Instructions

```C
typedef enum { PSH, ADD, POP, SET, HLT } InstructionSet;

/* Test Program */
const int prog[] = {
    PSH, 5, // push 5 to stack
    PSH, 6, // push 6 to stack
    ADD,    // pop 2 va
    POP,    // pop value and print
    HLT,    // halt execution
};
```

## Fetching Instructions & Evaluation

- We use an instruction pointer to keep track of the current instruction
- We create a basic fetch function to fetch data from the default program
```C
// fetch function
int fetch() { return prog[ip]; }

int main(void) {
  int x = fetch(); // PSH -> 0
  ip++;
  int y = fetch(); // 5
  return 0;
}
```

- we create a simple switch statement to evaluate fetched instructions
```C
void eval(int instr) {
  switch (instr) {
  case HLT:
    running = false;
    break;
  }
}

int main(void) {
    while (running) {
        eval(fetch());
        ip++;
    }
    return 0;
}
```

# Stack implementation

- for navigating a stack and keeping track, we require a stack pointer
```
PSH 5   => [5]
PSH 6   => [5, 6]
ADD     => [5], var a = 6
        => [], var a = 6, var b = 5
        => [], var result = b + a {this is done backwards}
        => [11]
```
- when `sp` is set to 1, we have an empty stack
- order of addition to stack is important. We need to increment sp and then add value to stack

```C
case (instr):
    PSH: {
        sp++; // eg moving from -1 to 0
        stack[sp] = prog[ip++];
        break;
    }

```
