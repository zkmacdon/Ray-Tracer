cmake_minimum_required(VERSION "3.28.0")


project("rays")


add_executable("Raytrace", "main.cpp")


install(TARGETS "${PROJECT_NAME}" DESTINATION bin)


install(FILES "main.cpp" DESTINATION src)
