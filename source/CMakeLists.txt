
add_executable(aufgabe2und3
aufgabe_2_und_3.cpp
)

add_executable(aufgabe9
aufgabe9.cpp
)

add_executable (aufgabe_11
aufgabe_11.cpp
)

add_executable (aufgabe_6
aufgabe_6.cpp
Circle.cpp
Vec2.cpp
window.cpp
glew.c
color.cpp
)
target_link_libraries(aufgabe_6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(aufgabe_6 glfw nanovg ${COPY_BINARY})





