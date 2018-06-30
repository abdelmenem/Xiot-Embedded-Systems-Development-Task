# Xiot-Embedded-Systems-Development-Task
Xiot  Embedded Systems Development Task


I use ATMega 16 microcontroller instead of using arduino in that task.
I also send proteus simulation files (xiot.dsn & xiot.PWI) with the files of the project.

files of project divided into :-
  - main file that initiate all features(ADC - interrupt0 - UART) and contains the main program.
  - ADC.c & ADC.h files that contains the functions required to use the ADC feature like
      (ADC_INIT & ADC_read)
  - interrupt.c & interrupt.h files that contains the functions required to use the interrupt0 feature like
      (INT0_INIT & ISR(INT0_vect))
  - uart.c & uart.h files that contains the functions required to use the uart feature like
      (UART_INIT & UART_sendByte & UART_sendString)   
      
  - simulation files using proteus ISIS (xiot.dsn & xiot.PWI) 
