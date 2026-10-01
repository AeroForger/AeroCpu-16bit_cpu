#include "cpu.h"
#include <stdio.h>

int main(void) {
    struct CPU cpu = {0};
    struct Instruction program[] = {
        {.dest = 0, .immediate = 10, .opcode = 40},
        {.dest = 1, .immediate = 20, .opcode = 40},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 42},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 43},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 44},
        {.jump_address=8, .opcode = 41},
        {.dest = 0, .src1 = 0, .src2 = 0, .opcode = 0}, // HALT
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 45},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 46},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 47},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 48},
        {.dest = 2, .src1 = 0, .src2 = 1, .opcode = 49},
    };
    cpu.instruction_count = sizeof(program) / sizeof(program[0]);

    while (!cpu.halted && cpu.pc < cpu.instruction_count) {
        uint16_t current_pc = cpu.pc;
        cpu.pc++;
        cpu_execute(&cpu, &program[current_pc]);
        printf("current index: %u\n", current_pc);
        printf("cpu.pc: %u\n", cpu.pc);
        printf("current opcode: %u\n", program[current_pc].opcode);
        printf("Result in reg[2]: %u\n", cpu.reg[2]);
    }
    return 0;
}