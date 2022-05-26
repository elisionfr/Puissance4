cmake_minimum_required(VERSION 3.0.0)
project(Puissance4 VERSION 0.1.0)

set(SOURCE_FILES
    Source/main.cpp
    Source/Application.cpp
)

add_executable(
    Puissance4
    ${SOURCE_FILES}
)

#SDL
#link_directories(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/lib/x64)
target_include_directories(Puissance4 PUBLIC ${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/include)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/lib/x64/SDL2.lib)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/lib/x64/SDL2main.lib)
target_link_libraries(Puissance4 ${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/lib/x64/SDL2test.lib)

add_custom_command(TARGET Puissance4 POST_BUILD        # Adds a post-build event to MyTest
    COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
        "${PROJECT_SOURCE_DIR}/ThirdParty/SDL-2.0/lib/x64/SDL2.dll"      # <--this is in-file
        $<TARGET_FILE_DIR:Puissance4>)                 # <--this is out-file path