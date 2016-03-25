avr-gcc -mmcu=atmega328p -I/usr/share/arduino/hardware/arduino/variants/standard -I/usr/share/arduino/hardware/arduino/cores/arduino/ test.blink.c -o test.blink.o


/usr/share/arduino/hardware/tools/avr/bin/avr-g++ -c -g -Os -Wall -fno-exceptions -ffunction-sections -fdata-sections -mmcu=atmega328p -DF_CPU=16000000L -MMD -DUSB_VID=null -DUSB_PID=null -DARDUINO=105 -D__PROG_TYPES_COMPAT__ -I/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard test.blink.c -o test-blink.o

/usr/share/arduino/hardware/tools/avr/bin/avr-gcc -Os -Wl,--gc-sections -mmcu=atmega328p -o test-blink.cpp.elf test-blink.o -lm


avr-objcopy -j .text -j .data -O ihex  test-blink.o  test-blink.hex


/usr/share/arduino/hardware/arduino/cores/arduino -I/usr/share/arduino/hardware/arduino/variants/standard /tmp/build5128865122365737024.tmp/Blink.cpp -o /tmp/build5128865122365737024.tmp/Blink.cpp.o


/usr/share/arduino/hardware/tools/avr/bin/avr-objcopy -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0 /tmp/build5128865122365737024.tmp/Blink.cpp.elf /tmp/build5128865122365737024.tmp/Blink.cpp.eep



#example 2
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o led.o led.c
avr-gcc -mmcu=atmega328p led.o -o led
avr-objcopy -O ihex -R .eeprom led led.hex
avrdude -F -V -c arduino -p ATMEGA328P -P /dev/ttyACM0 -b 115200 -U flash:w:led.hex
