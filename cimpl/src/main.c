#include <stdbool.h>
#include <stdio.h>

// defining program suggestions, utilising enum
typedef enum { PSH, ADD, POP, SET, HLT } InstructionSet;
typedef enum {
  A,               // regisetr A
  B,               // regisetr B
  C,               // regisetr C
  D,               // regisetr D
  E,               // register E
  IP,              // Instruction Pointer
  SP,              // Stack Pointer
  NUM_OF_REGISTERS // using this we get size of registers
                   // even if more are added
} Registers;

/* Test Program */
const int prog[] = {
    PSH, 5, // push 5 to stack
    PSH, 6, // push 6 to stack
    ADD,    // pop 2 va
    POP,    // pop value and print
    HLT,    // halt execution
};

int stack[256]; // stack having 256 storage slots
int registers[NUM_OF_REGISTERS];

#define sp (registers[SP])
#define ip (registers[IP])

// running boolean
bool running = true;

int fetch();          // fetch function
void eval(int instr); // instruction evaluation

// mainloop of code
int main(void) {
  while (running) {
    eval(fetch()); // fetches inst and passes
                   // it for evaluation
    ip++;
  }
}

int fetch() { return prog[ip]; }

void eval(int instr) {
  switch (instr) {
  case HLT:
    running = false;
    break;

  case PSH: {
    sp++;
    stack[sp] = prog[ip++];
    break;
  }

  case POP: {
    // first store value
    int val = stack[sp--];
    printf("POP: %d\n", val);
    break;
  }

  case ADD: {
    int a = stack[sp--];
    int b = stack[sp--];
    int result = b + a;
    sp++; // incase we are at sp = -1, we move to sp = 0
    stack[sp] = result;
    break;
  }
  }
}
