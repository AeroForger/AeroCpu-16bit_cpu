<div align="center">

# AeroCpu

### AeroCpu is my 16 bit cpu simulator written in C
---

> [!NOTE]
> This is a learning project

> [!WARNING]
> This project isnt finished

---
</div>

## Structure

- `include/`: header files and CPU/instruction definitions.
- `src/`: simulator implementation and example program.

## Build and run

From the project directory, using a C17 compiler:

```sh
cc -std=c17 -Wall -Wextra -Wpedantic -Iinclude src/main.c src/alu.c src/reg.c -o cpu
./cpu
```

## How it works

The CPU has eight 16-bit registers (`R0` through `R7`), a program counter
(`pc`), a stack pointer (`sp`) - Currently not used, a flags field, and a halt flag. Stack and
status-flag behavior is not implemented yet.

Programs currently use an array of C `struct Instruction` values. The program
counter indexes this array. Before each instruction executes, the counter
advances a jump replaces it with the target index. Execution stops on HALt
or when the counter reaches or exceeds the array length.

The assembly notation below describes the intended readable form an assembler
is not implemented yet. `Rd` is the destination register, `Ra` and `Rb` are
source registers, `#value` is a literal number, and `target` is an instruction
index. Opcodes are decimal.

| Opcode | Assembly variant | Meaning |
| :--- | :--- | :--- |
| 0 | `HALT` | Set the halt flag and stop execution. |
| 40 | `MOV Rd, #value` | Load an immediate value into `Rd`. |
| 41 | `JMP target` | Set `pc` to the target instruction index. |
| 42 | `ADD Rd, Ra, Rb` | Store `Ra + Rb` in `Rd`. |
| 43 | `SUB Rd, Ra, Rb` | Store `Ra - Rb` in `Rd`. |
| 44 | `MUL Rd, Ra, Rb` | Store the lowest 16 bits of `Ra * Rb` in `Rd`. |
| 45 | `DIV Rd, Ra, Rb` | Store the unsigned integer quotient `Ra / Rb` in `Rd`. |
| 46 | `CMP Rd, Ra, Rb` | Store `0xFFFF` if `Ra < Rb`, `1` if `Ra > Rb`, or `0` if equal. |
| 47 | `AND Rd, Ra, Rb` | Store the bitwise AND of the sources in `Rd`. |
| 48 | `OR Rd, Ra, Rb` | Store the bitwise OR of the sources in `Rd`. |
| 49 | `XOR Rd, Ra, Rb` | Store the bitwise XOR of the sources in `Rd`. |

Arithmetic results wrap to 16 bits. Division discards the fractional part;
division by zero currently returns `0` without reporting a fault. Comparison
uses unsigned values and stores its result in a register rather than flags.
Invalid register indices leave registers unchanged. Unknown opcodes print an
error, then execution continues.

For example, these instructions load two operands and add them:

```c
    //snip is copied from main.c
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
```

Example output:
```bash
❯ cc -std=c17 -Wall -Wextra -Wpedantic -Iinclude src/main.c src/alu.c src/reg.c -o cpu
  ./cpu
Result in reg[2]: 0
Result in reg[2]: 0
Result in reg[2]: 30
Result in reg[2]: 65526
Result in reg[2]: 200
Result in reg[2]: 200
Result in reg[2]: 65535
Result in reg[2]: 0
Result in reg[2]: 30
Result in reg[2]: 30
```
> i totally didnt copy my debug output and removed debug test trust me 

## License 

Apache 2.0