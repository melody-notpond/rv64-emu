#include <stdio.h>

#include "rv64.h"

uint64_t get_add_instr(RiscV64Cpu* cpu, RiscVDataSize size, uint64_t address) {
    (void) cpu;
    (void) size;
    (void) address;
    return 0x01f100b3;
}

int main() {
    RiscV64Cpu cpu = new_cpu(get_add_instr, NULL, NULL);
    cpu.xs[2] = 34;
    cpu.xs[31] = 35;
    step(&cpu);
    printf("result of x1: %li\n", cpu.xs[1]);
}