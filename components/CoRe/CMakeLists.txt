include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

## Set the CoRe header files
set (CoRe_HEADERS 
     ${CMAKE_CURRENT_LIST_DIR}/Global.hpp
     ${CMAKE_CURRENT_LIST_DIR}/include/resources/Resources.hpp
     ${CMAKE_CURRENT_LIST_DIR}/include/math/Math.hpp
     ${CMAKE_CURRENT_LIST_DIR}/include/utils/Utils.hpp)

## Set the CoRe source files
set (CoRe_SRC ${CMAKE_CURRENT_LIST_DIR}/Global.cpp)

## Add and install the CoRe shared library
add_library (CoRe SHARED ${CoRe_SRC})
install (TARGETS CoRe
         EXPORT "CoReTargets"
         LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}         
         RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install (DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/include/${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


