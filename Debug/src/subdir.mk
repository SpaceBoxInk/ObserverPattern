################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Observed.cpp \
../src/Observer.cpp \
../src/Test.cpp 

OBJS += \
./src/Observed.o \
./src/Observer.o \
./src/Test.o 

CPP_DEPS += \
./src/Observed.d \
./src/Observer.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -std=c++1z -O0 -g3 -Wall -Wextra -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


