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

 





