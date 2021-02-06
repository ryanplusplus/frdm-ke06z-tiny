if(NOT DEVICE_MKE06Z4_CMSIS_MKE06Z4_INCLUDED)
    
    set(DEVICE_MKE06Z4_CMSIS_MKE06Z4_INCLUDED true CACHE BOOL "device_MKE06Z4_CMSIS component is included.")


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )

    include(CMSIS_Include_core_cm0plus_MKE06Z4)

endif()
