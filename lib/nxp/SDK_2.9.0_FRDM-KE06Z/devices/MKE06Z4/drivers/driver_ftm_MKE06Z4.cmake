if(NOT DRIVER_FTM_MKE06Z4_INCLUDED)
    
    set(DRIVER_FTM_MKE06Z4_INCLUDED true CACHE BOOL "driver_ftm component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_ftm.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MKE06Z4)

endif()
