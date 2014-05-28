################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Account.cpp \
../src/Cash.cpp \
../src/InvalidDepositException.cpp \
../src/InvalidWithdrawException.cpp \
../src/main.cpp 

OBJS += \
./src/Account.o \
./src/Cash.o \
./src/InvalidDepositException.o \
./src/InvalidWithdrawException.o \
./src/main.o 

CPP_DEPS += \
./src/Account.d \
./src/Cash.d \
./src/InvalidDepositException.d \
./src/InvalidWithdrawException.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


