if(NOT DRIVER_CMSIS_UART_MKE06Z4_INCLUDED)
    
    set(DRIVER_CMSIS_UART_MKE06Z4_INCLUDED true CACHE BOOL "driver_cmsis_uart component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_uart_cmsis.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_uart_MKE06Z4)

    include(CMSIS_Driver_Include_USART_MKE06Z4)

endif()
