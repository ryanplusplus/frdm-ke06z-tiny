if(NOT DRIVER_COMMON_MKE06Z4_INCLUDED)
    
    set(DRIVER_COMMON_MKE06Z4_INCLUDED true CACHE BOOL "driver_common component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_common.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_clock_MKE06Z4)

    include(device_MKE06Z4_CMSIS_MKE06Z4)

endif()
