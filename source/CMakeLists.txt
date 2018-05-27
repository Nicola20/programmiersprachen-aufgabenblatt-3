add_executable( aufgabe_4
example.cpp
window.cpp
glew.c
Circle.cpp
Vec2.cpp
color.cpp)
target_link_libraries(aufgabe_4
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})

add_executable (aufgabe_2_und_3
aufgabe_2_und_3.cpp)

add_executable (aufgabe_6
aufgabe_6.cpp
Circle.cpp
color.cpp
Vec2.cpp
window.cpp
glew.c)
target_link_libraries(aufgabe_6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_6 glfw nanovg ${COPY_BINARY})

add_executable (aufgabe_7
aufgabe_7.cpp
Circle.cpp
color.cpp
Vec2.cpp
window.cpp
glew.c)
target_link_libraries(aufgabe_7
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_7 glfw nanovg ${COPY_BINARY})

add_executable (aufgabe9
aufgabe9.cpp)

add_executable (aufgabe_11
aufgabe_11.cpp)

add_executable (aufgabe_12
aufgabe_12.cpp
Circle.cpp
color.cpp
Vec2.cpp
window.cpp
glew.c)
target_link_libraries(aufgabe_12
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_12 glfw nanovg ${COPY_BINARY})

add_executable (aufgabe_13
aufgabe_13.cpp)






 





