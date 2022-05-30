set(SOURCE_FILES
    Application.cpp
)

# The Stuff Framework Library Target
add_library(
    STUFF
    ${SOURCE_FILES}
)

#STUFF includes
target_include_directories(STUFF PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

#SFML
target_include_directories(STUFF PUBLIC ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/include)

target_link_libraries(STUFF ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-graphics.lib)
target_link_libraries(STUFF ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-window.lib)
target_link_libraries(STUFF ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-system.lib)

add_custom_command(TARGET STUFF POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-graphics-2.dll" $<TARGET_FILE_DIR:STUFF>)
add_custom_command(TARGET STUFF POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-window-2.dll" $<TARGET_FILE_DIR:STUFF>)
add_custom_command(TARGET STUFF POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-system-2.dll" $<TARGET_FILE_DIR:STUFF>)