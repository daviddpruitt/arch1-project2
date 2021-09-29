# makfile configuration
COMMON_OBJECTS  = main.o led.o wdtInterruptHandler.o 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: blink_state.elf 

#additional rules for files
blink_state.elf: ${COMMON_OBJECTS} 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: blink_state.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h

wdInterruptHandler.o:  led.h

led.o: led.h
