# makfile configuration
COMMON_OBJECTS  = main.o stateMachines.o led.o wdtInterruptHandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: modular_s.elf modular_c.elf

#additional rules for files
modular_c.elf: ${COMMON_OBJECTS} greenOn_c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

modular_s.elf: ${COMMON_OBJECTS} greenOn_s.o 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load_c: modular_c.elf
	msp430loader.sh $^

load_s: modular_s.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h

led.o: led.h

stateMachines.o: led.h

wdtInterruptHandler.o:  wdtInterruptHandler.c

greenOn_c.o: greenOn_c.c led.h

greenOn_s.o: greenOn_s.s led.h

