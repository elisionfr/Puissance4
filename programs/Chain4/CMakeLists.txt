set(SOURCE_FILES
    main.cpp
)

add_executable(
    Chain4
    ${SOURCE_FILES}
)

#depedency so STUFF is automatically built
add_dependencies(Chain4 STUFF)

#link against STUFF
target_link_libraries(Chain4 STUFF)
