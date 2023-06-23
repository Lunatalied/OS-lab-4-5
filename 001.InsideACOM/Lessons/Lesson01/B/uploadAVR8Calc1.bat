"%ECO_TOOLCHAIN%\avrdude-6.3\avrdude.exe" -C "%ECO_TOOLCHAIN%\avrdude-6.3\avrdude.conf" -v -p atmega328p -c arduino -P \\.\COM3 -b 115200 -D -U flash:w:DemoCalculator1.hex:i
pause