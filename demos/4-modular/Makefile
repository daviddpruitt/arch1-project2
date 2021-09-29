# makfile configuration
COMMON_OBJECTS  = main.o stateMachines.o led.o wdtInterruptHandler.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: modular.elf 

#additional rules for files
modular.elf: ${COMMON_OBJECTS} 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: modular.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h

led.o: led.h

stateMachines.o: led.h

wdtInterruptHandler.o:  wdtInterruptHandler.c

