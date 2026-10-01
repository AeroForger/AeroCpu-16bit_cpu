#include "cpu.h"
#include <stdio.h>
#include <stdlib.h> 


void reg_reset(struct CPU *cpu){
    for(int i = 0; i < 8; i++){
        cpu->reg[i] = 0;
    }
}
bool check_index(uint16_t des, uint16_t index1, uint16_t index2){
    if (des > 7) {
        return false;
    }
    if (index1 > 7) {
        return false;
    }
    if (index2 > 7) {
        return false;
    }
    return true;
}
void pc_reset(struct CPU *cpu){
    cpu->pc = 0;
}
void cpu_add(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = addition(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_sub(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = subtraction(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_mul(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = multiplication(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_div(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = division(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_cmp(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = compare(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_and(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = bitwise_and(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_or(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = bitwise_or(cpu->reg[index1], cpu->reg[index2]);
}
void cpu_xor(struct CPU *cpu, uint16_t des, uint16_t index1, uint16_t index2){
    if (!check_index(des, index1, index2)) {
        return;
    }
    cpu->reg[des] = bitwise_xor(cpu->reg[index1], cpu->reg[index2]);
}



void cpu_execute(struct CPU *cpu, const struct Instruction *instruction) {
    switch (instruction->opcode) {
        case 40:
            if (instruction->dest > 7) {
                return;
            }
            cpu->reg[instruction->dest] = instruction->immediate;
            break;
        case 41:
            cpu->pc = instruction->jump_address;
            break;
        case 42:
            cpu_add(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 43:
            cpu_sub(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 44:
            cpu_mul(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 45:
            cpu_div(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 46:
            cpu_cmp(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 47:
            cpu_and(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 48:
            cpu_or(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 49:
            cpu_xor(cpu, instruction->dest, instruction->src1, instruction->src2);
            break;
        case 0: //HALT
            cpu->halted = true;
            break;
        default:
            printf("Invalid instruction: %u\n", (unsigned int)instruction->opcode);
            break;
    }
}