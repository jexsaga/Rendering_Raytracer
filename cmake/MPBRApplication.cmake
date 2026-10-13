function(mpbr_add_application TARGET_NAME)

    message(STATUS "Configuring application: ${TARGET_NAME}")

    add_executable(${TARGET_NAME} ${ARGN})

    target_link_libraries(${TARGET_NAME} PRIVATE mpbr)

    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/assets
            $<TARGET_FILE_DIR:${TARGET_NAME}>/assets
    )

    set_target_properties(${TARGET_NAME} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "$<TARGET_FILE_DIR:${TARGET_NAME}>"
    )

endfunction()
