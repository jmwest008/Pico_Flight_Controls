cmake_minimum_required(VERSION 3.13)

# Import the Pico SDK (expects PICO_SDK_PATH to be set or submodule present)
include(pico_sdk_import.cmake)

project(pico_w_rc_controller C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# (optional but helpful) be explicit about board
set(PICO_BOARD pico_w)

pico_sdk_init()

add_executable(pico_w_rc_controller
    main.cpp
)

target_include_directories(pico_w_rc_controller PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    ${PICO_SDK_PATH}/lib/lwip/src/include
    ${PICO_SDK_PATH}/lib/lwip/contrib/ports/freertos/include
    )

target_compile_features(pico_w_rc_controller PUBLIC cxx_std_17)

# Link against the threaded background network stack and PWM helpers
# for the CYW43 Wi-Fi chip and servo control.
target_link_libraries(pico_w_rc_controller
    pico_stdlib
    hardware_pwm
    pico_cyw43_arch_lwip_threadsafe_background
)

pico_enable_stdio_usb(pico_w_rc_controller 1)
pico_enable_stdio_uart(pico_w_rc_controller 0)

pico_add_extra_outputs(pico_w_rc_controller)