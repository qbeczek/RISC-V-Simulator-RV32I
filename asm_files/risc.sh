#!/bin/bash
FILE=$1
/home/jszyman/risc-v/bin/riscv64-unknown-elf-as -march=rv32i -mabi=ilp32 $FILE.s -o $FILE.o
/home/jszyman/risc-v/bin/riscv64-unknown-elf-ld -nostartfiles -march=rv32i -melf32lriscv -Tlinker.ld $FILE.o -o test
/home/jszyman/risc-v/bin/riscv64-unknown-elf-objdump -DxS test > test.lst 
/home/jszyman/risc-v/bin/riscv64-unknown-elf-objcopy -j ".text" -O binary test file_code.bin
/home/jszyman/risc-v/bin/riscv64-unknown-elf-objcopy -j ".data" -O binary test file_data_in.bin
/home/jszyman/risc-v/bin/riscv64-unknown-elf-readelf -a test >test_elf.lst

mv /home/jszyman/Desktop/syko/projekt_C/syko/Szymanski_Jakub/szkielet/glowny/asm_files/file_code.bin /home/jszyman/Desktop/syko/projekt_C/syko/Szymanski_Jakub/szkielet/glowny/sources/test
mv /home/jszyman/Desktop/syko/projekt_C/syko/Szymanski_Jakub/szkielet/glowny/asm_files/file_data_in.bin /home/jszyman/Desktop/syko/projekt_C/syko/Szymanski_Jakub/szkielet/glowny/sources/test
