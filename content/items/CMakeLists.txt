add_library(items
  bite.cpp
        sword.cpp
        sword.h
        spear.cpp
        spear.h
        sword_rusty.cpp
        sword_rusty.h
        axe.cpp
        axe.h
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
