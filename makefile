CC=gcc
CFLAGS=-c -Wall

syko.out: mem_abs.c f_add.c f_addi.c f_auipc.c f_bne.c f_jal.c f_jalr.c f_lui.c f_sb.c f_sll.c f_slti.c f_sw.c main.c
	$(CC) $(CFLAGS) mem_abs.c -o mem_abs.o
	#make functions
	$(CC) $(CFLAGS) f_add.c -o f_add.o
	$(CC) $(CFLAGS) f_addi.c -o f_addi.o
	$(CC) $(CFLAGS) f_auipc.c -o f_auipc.o
	$(CC) $(CFLAGS) f_bne.c -o f_bne.o
	$(CC) $(CFLAGS) f_jal.c -o f_jal.o
	$(CC) $(CFLAGS) f_jalr.c -o f_jalr.o
	$(CC) $(CFLAGS) f_lui.c -o f_lui.o
	$(CC) $(CFLAGS) f_sb.c -o f_sb.o
	$(CC) $(CFLAGS) f_sll.c -o f_sll.o
	$(CC) $(CFLAGS) f_slti.c -o f_slti.o
	$(CC) $(CFLAGS) f_sw.c -o f_sw.o
	#main
	$(CC) $(CFLAGS) main.c -o main.o
	$(CC) $(CFLAGS) mem_abs.o f_add.o f_addi.o f_auipc.o f_bne.o f_jal.o f_jalr.o f_lui.o f_sb.o f_sll.o f_slti.o f_sw.o main.o -o syko.out

test: syko.out
	syko.out

clean:
	rm -f mem_abs.o
	rm -f f_add.o
	rm -f f_addi.o
	rm -f df_auipc.o
	rm -f f_bne.o
	rm -f f_jal.o
	rm -f f_jalr.o
	rm -f f_lui.o
	rm -f f_sb.o
	rm -f f_sll.o
	rm -f f_slti.o
	rm -f f_sw.o
	rm -f main.o

