if(NOT DRIVER_PORT_KE06_MKE06Z4_INCLUDED)
    
    set(DRIVER_PORT_KE06_MKE06Z4_INCLUDED true CACHE BOOL "driver_port_ke06 component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_port.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MKE06Z4)

endif()
