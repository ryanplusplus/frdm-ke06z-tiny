if(NOT DRIVER_I2C_MKE06Z4_INCLUDED)
    
    set(DRIVER_I2C_MKE06Z4_INCLUDED true CACHE BOOL "driver_i2c component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_i2c.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MKE06Z4)

endif()
