if(NOT DEVICE_MKE06Z4_SYSTEM_MKE06Z4_INCLUDED)
    
    set(DEVICE_MKE06Z4_SYSTEM_MKE06Z4_INCLUDED true CACHE BOOL "device_MKE06Z4_system component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/system_MKE06Z4.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(device_MKE06Z4_CMSIS_MKE06Z4)

endif()
