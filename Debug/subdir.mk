################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../banco_de_registradores.o \
../io.o \
../main.o 

C_SRCS += \
../ALU.c \
../aux.c \
../banco_de_registradores.c \
../controle.c \
../io.c \
../main.c \
../memoria.c \
../mux.c \
../processador.c 

OBJS += \
./ALU.o \
./aux.o \
./banco_de_registradores.o \
./controle.o \
./io.o \
./main.o \
./memoria.o \
./mux.o \
./processador.o 

C_DEPS += \
./ALU.d \
./aux.d \
./banco_de_registradores.d \
./controle.d \
./io.d \
./main.d \
./memoria.d \
./mux.d \
./processador.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


