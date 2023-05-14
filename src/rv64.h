#ifndef RV64_H
#define RV64_H

#include <stdint.h>

typedef enum {
    RiscVDataSizeByte,
    RiscVDataSizeHalf,
    RiscVDataSizeWord,
    RiscVDataSizeDoubleWord,
} RiscVDataSize;

typedef struct s_riscv64_cpu {
    uint64_t xs[32];
    uint64_t pc;

    void* user_data;
    uint64_t (*read)(struct s_riscv64_cpu* cpu, RiscVDataSize size, uint64_t address);
    void (*write)(struct s_riscv64_cpu* cpu, RiscVDataSize size, uint64_t address, uint64_t data);
} RiscV64Cpu;

typedef uint64_t (*RiscV64ReadFn)(RiscV64Cpu* cpu, RiscVDataSize size, uint64_t address);
typedef void (*RiscV64WriteFn)(RiscV64Cpu* cpu, RiscVDataSize size, uint64_t address, uint64_t data);

RiscV64Cpu new_cpu(RiscV64ReadFn read, RiscV64WriteFn write, void* user_data);

void step(RiscV64Cpu* cpu);

#endif /* RV64_H */