cmake_minimum_required(VERSION 3.14)

project(
    get_env
    VERSION 0.1.0
    DESCRIPTION "Simply get env vars with default values in C++"
    HOMEPAGE_URL "https://github.com/ssleert/get_env"
    LANGUAGES NONE
)

add_library(get_env INTERFACE)
add_library(get_env::get_env ALIAS get_env)

set_property(
    TARGET headeronly_headeronly PROPERTY
    EXPORT_NAME headeronly
)

target_include_directories(
    get_env ${warning_guard}
    INTERFACE
    "$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>"
)

target_compile_features(get_env INTERFACE cxx_std_20)

