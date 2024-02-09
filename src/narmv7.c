#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define ARCH_SIZE 32

typedef enum {
  MOV,
  ADD,
  SUB,
  STR,
  PUSH,
  POP,
  INSTRCOUNT,
} InstructionSet;

// Registers
typedef enum {
  R0,
  R1,
  R2,
  R3,
  R4,
  R5,
  R6,
  R7,
  R8,
  R9,
  R10,
  FP, // R11: frame pointer
  IP, // R12: intra procedural call
  SP, // R13: Stack pointer
  LR, // R14: Link Register
  PC, // R15: Program Counter
  RCOUNT,
} Register;

// Current Program State Regisrer - CPSR
// idk if im gonna need this now
typedef enum {
  N, // Negative flag
  Z, // Zero flag
  C, // Carry flag
  V, // Overflow flag
  Q, // Underflow flag

} CPSR;

// Defining memory
uint32_t registers[RCOUNT]; // 32 bit integers

int main(void) {
  printf("General Purpose Registers: %d\n", RCOUNT);
  printf("Instruction Set: %d\n", INSTRCOUNT);
  printf("=====================\n");
  return 0;
}
