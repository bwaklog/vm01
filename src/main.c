#include <stdbool.h>
#include <wchar.h>

// defining program suggestions, utilising enum
typedef enum { PSH, ADD, POP, SET, HLT } InstructionSet;

/* Test Program */
const int prog[] = {
    PSH, 5, // push 5 to stack
    PSH, 6, // push 6 to stack
    ADD,    // pop 2 va
    POP,    // pop value and print
    HLT,    // halt execution
};

// defining instruction pointer
int ip = 0;

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
  }
}
