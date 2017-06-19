################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IMagazyn.cpp \
../src/Magazyn.cpp \
../src/Towar.cpp \
../src/main.cpp \
../src/plecak.cpp 

OBJS += \
./src/IMagazyn.o \
./src/Magazyn.o \
./src/Towar.o \
./src/main.o \
./src/plecak.o 

CPP_DEPS += \
./src/IMagazyn.d \
./src/Magazyn.d \
./src/Towar.d \
./src/main.d \
./src/plecak.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -lSDL2main -lSDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


