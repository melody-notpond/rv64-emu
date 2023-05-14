#include <stdlib.h>

#include "rv64.h"

RiscV64Cpu new_cpu(RiscV64ReadFn read, RiscV64WriteFn write, void* user_data) {
    return (RiscV64Cpu) {
        .xs = { 0 },
        .pc = 0,
        .read = read,
        .write = write,
        .user_data = user_data,
    };
}

void step(RiscV64Cpu* cpu) {
    uint32_t instruction = cpu->read(cpu, RiscVDataSizeWord, cpu->pc);
    cpu->pc += 4;
    uint32_t opcode = instruction & 0x7f;

    switch (opcode) {
        // ADD rd, rs1, rs2
        case 0b0110011: {
            int rd  = (instruction >>  7) & 0b11111;
            int rs1 = (instruction >> 15) & 0b11111;
            int rs2 = (instruction >> 20) & 0b11111;
            cpu->xs[rd] = cpu->xs[rs1] + cpu->xs[rs2];
            break;
        }

        default:
            break;
    }

    cpu->xs[0] = 0;
}
