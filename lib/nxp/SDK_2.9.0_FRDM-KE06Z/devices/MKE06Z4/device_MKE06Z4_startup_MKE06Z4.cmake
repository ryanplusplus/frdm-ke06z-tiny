if(NOT DEVICE_MKE06Z4_STARTUP_MKE06Z4_INCLUDED)
    
    set(DEVICE_MKE06Z4_STARTUP_MKE06Z4_INCLUDED true CACHE BOOL "device_MKE06Z4_startup component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/gcc/startup_MKE06Z4.S
    )


    include(device_MKE06Z4_system_MKE06Z4)

endif()
