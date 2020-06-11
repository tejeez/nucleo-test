softa.elf: *.c *.h *.s *.ld Makefile
	arm-none-eabi-gcc -o $@ -lc -lm -lnosys -specs=nano.specs -T ./*.ld -g -mcpu=cortex-m7 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -DSTM32H745xx -DCORE_CM7 ./*.s ./*.c
