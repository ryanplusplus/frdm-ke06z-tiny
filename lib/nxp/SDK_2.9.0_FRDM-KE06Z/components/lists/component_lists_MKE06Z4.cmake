if(NOT COMPONENT_LISTS_MKE06Z4_INCLUDED)
    
    set(COMPONENT_LISTS_MKE06Z4_INCLUDED true CACHE BOOL "component_lists component is included.")

    target_sources(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/fsl_component_generic_list.c
    )


    target_include_directories(${MCUX_SDK_PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/.
    )


    include(driver_common_MKE06Z4)

endif()
