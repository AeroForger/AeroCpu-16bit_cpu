#ifndef CPU_H
#define CPU_H

#include<stdint.h>
#include<stdbool.h>
#include<stddef.h>

struct CPU {
    uint16_t reg[8];
    uint16_t pc;
    uint16_t sp;
    uint16_t flags;
    size_t instruction_count;
    bool halted;
};
struct Instruction {
    uint16_t opcode;
    uint16_t dest;
    uint16_t src1;
    uint16_t src2;
    uint16_t immediate;
    uint16_t jump_address;
};
void reg_reset(struct CPU *cpu);
void pc_reset(struct CPU *cpu);
uint16_t addition(uint16_t a, uint16_t b);
uint16_t subtraction(uint16_t a, uint16_t b);
uint16_t multiplication(uint16_t a, uint16_t b);
uint16_t division(uint16_t a, uint16_t b);
uint16_t compare(uint16_t a, uint16_t b);
uint16_t bitwise_and(uint16_t a, uint16_t b);
uint16_t bitwise_or(uint16_t a, uint16_t b);
uint16_t bitwise_xor(uint16_t a, uint16_t b);
void cpu_add(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2);
void cpu_sub(struct CPU *cpu, uint16_t des, uint16_t index1,uint16_t index2);
void cpu_mul(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2);
void cpu_div(struct CPU *cpu, uint16_t des, uint16_t index1,uint16_t index2);
void cpu_and(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2);
void cpu_or(struct CPU *cpu, uint16_t des, uint16_t index1,uint16_t index2);
void cpu_xor(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2);
void cpu_cmp(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2);
void cpu_execute(struct CPU *cpu, const struct Instruction *instruction);
#endif