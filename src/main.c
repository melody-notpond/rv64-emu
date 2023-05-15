#include <stdio.h>

#include "rv64.h"

uint64_t get_add_instr(RiscV64Cpu* cpu, RiscVDataSize size, uint64_t address) {
    (void) cpu;
    (void) size;
    (void) address;
    return 0xfffff0b7;
}

int main() {
    RiscV64Cpu cpu = new_cpu(get_add_instr, NULL, NULL);
    step(&cpu);
    printf("result of x1: %lx\n", cpu.xs[1]);
}