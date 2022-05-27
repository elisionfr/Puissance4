cmake_minimum_required(VERSION 3.0.0)
project(Puissance4 VERSION 0.1.0)

set(SOURCE_FILES
    Source/main.cpp
)

add_executable(
    Puissance4
    ${SOURCE_FILES}
)

#SFML

target_include_directories(Puissance4 PUBLIC ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/include)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-graphics.lib)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-window.lib)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/sfml-system.lib)
#target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/opengl32.lib)
#target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SFML/lib/freetype.lib)

add_custom_command(TARGET Puissance4 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-graphics-2.dll" $<TARGET_FILE_DIR:Puissance4>)
add_custom_command(TARGET Puissance4 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-window-2.dll" $<TARGET_FILE_DIR:Puissance4>)
add_custom_command(TARGET Puissance4 POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/SFML/bin/sfml-system-2.dll" $<TARGET_FILE_DIR:Puissance4>)