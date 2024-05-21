cmake_minimum_required(VERSION 3.22)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_GENERATOR "Unix Makefiles")
project(template_project CXX) # Set the project name

# MCU configuration
# Set MCU type, clock frequency and programmer
set(MCU "atmega328p")
set(CLOCK_FREQ "16000000")
set(PROG_STR "arduino")
set(PORT "/dev/ttyUSB0")
set(BAUD "115200")



# C compiler flags
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_COMPILER avr-g++)
set(CMAKE_ASM_COMPILER avr-gcc)
set(GCC_FLAGS "-Wall -Wextra -DF_CPU=${CLOCK_FREQ} -mmcu=${MCU} -O2")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_FLAGS}")

file(GLOB_RECURSE SOURCES
	"src/*.*"
)

add_executable(${PROJECT_NAME}.elf ${SOURCES})

target_include_directories(${PROJECT_NAME}.elf PRIVATE inc)

set_property(TARGET ${PROJECT_NAME}.elf
	APPEND
	PROPERTY ADDITIONAL_CLEAN_FILES ${PROJECT_NAME}.hex ${PROJECT_NAME}.bin
)

add_custom_command(TARGET ${PROJECT_NAME}.elf
	POST_BUILD
	COMMAND avr-objcopy -j .text -j .data -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
	COMMAND avr-objcopy -j .text -j .data -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
)

add_custom_target(flash
	DEPENDS ${PROJECT_NAME}.elf
	COMMAND avrdude -c ${PROG_STR} -b ${BAUD} -p ${MCU} -P ${PORT} -U flash:w:${PROJECT_NAME}.hex:i
	COMMENT "flashes the hex file onto the MCU"
)