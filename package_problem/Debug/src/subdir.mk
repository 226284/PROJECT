################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IMagazyn.cpp \
../src/Magazyn.cpp \
../src/Towar.cpp \
../src/main.cpp \
../src/plecak.cpp \
../src/Obiekt_SDL.cpp \
../src/Obsluga_SDL.cpp \


OBJS += \
./src/IMagazyn.o \
./src/Magazyn.o \
./src/Towar.o \
./src/main.o \
./src/plecak.o \
./src/Obiekt_SDL.o \
../src/Obsluga_SDL.o \


CPP_DEPS += \
./src/IMagazyn.d \
./src/Magazyn.d \
./src/Towar.d \
./src/main.d \
./src/plecak.d \
./src/Obiekt_SDL.d \
../src/Obsluga_SDL.d \



# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -std=c++14 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


