if(NOT CMSIS_INCLUDE_COMMON_MKE06Z4_INCLUDED)
    
    set(CMSIS_INCLUDE_COMMON_MKE06Z4_INCLUDED true CACHE BOOL "CMSIS_Include_common component is included.")


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )

endif()
