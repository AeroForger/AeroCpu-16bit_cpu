#include "cpu.h"

uint16_t addition(uint16_t a, uint16_t b){return a + b;}
uint16_t subtraction(uint16_t a, uint16_t b){return a - b;}

uint16_t multiplication(uint16_t a, uint16_t b){
    return (uint16_t)((uint32_t)a * (uint32_t)b );
}
uint16_t division(uint16_t a, uint16_t b){
    if (b == 0) {
        // Handle division by zero error
        return 0; // or some other error value
    }
    return  a / b;
}
uint16_t compare(uint16_t a, uint16_t b){
    if (a < b) {
        return 0xFFFF; // Return 0xFFFF if a is less than b
    } else if (a > b) {
        return 0x0001; // Return 0x0001 if a is greater than b
    } else {
        return 0x0000; // Return 0x0000 if a is equal to b
    }
}
uint16_t bitwise_and(uint16_t a, uint16_t b) {
    return a & b;
}
uint16_t bitwise_or(uint16_t a, uint16_t b) {
    return a | b;   
}
uint16_t bitwise_xor(uint16_t a, uint16_t b) {
    return a ^ b;
}