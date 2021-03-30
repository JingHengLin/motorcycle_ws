# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "motorcycle_gz: 1 messages, 0 services")

set(MSG_I_FLAGS "-Imotorcycle_gz:/home/iclab/motorcycle_ws/src/motorcycle_gz/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(motorcycle_gz_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_custom_target(_motorcycle_gz_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "motorcycle_gz" "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(motorcycle_gz
  "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/motorcycle_gz
)

### Generating Services

### Generating Module File
_generate_module_cpp(motorcycle_gz
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/motorcycle_gz
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(motorcycle_gz_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(motorcycle_gz_generate_messages motorcycle_gz_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_dependencies(motorcycle_gz_generate_messages_cpp _motorcycle_gz_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(motorcycle_gz_gencpp)
add_dependencies(motorcycle_gz_gencpp motorcycle_gz_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS motorcycle_gz_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(motorcycle_gz
  "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/motorcycle_gz
)

### Generating Services

### Generating Module File
_generate_module_eus(motorcycle_gz
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/motorcycle_gz
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(motorcycle_gz_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(motorcycle_gz_generate_messages motorcycle_gz_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_dependencies(motorcycle_gz_generate_messages_eus _motorcycle_gz_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(motorcycle_gz_geneus)
add_dependencies(motorcycle_gz_geneus motorcycle_gz_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS motorcycle_gz_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(motorcycle_gz
  "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/motorcycle_gz
)

### Generating Services

### Generating Module File
_generate_module_lisp(motorcycle_gz
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/motorcycle_gz
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(motorcycle_gz_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(motorcycle_gz_generate_messages motorcycle_gz_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_dependencies(motorcycle_gz_generate_messages_lisp _motorcycle_gz_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(motorcycle_gz_genlisp)
add_dependencies(motorcycle_gz_genlisp motorcycle_gz_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS motorcycle_gz_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(motorcycle_gz
  "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/motorcycle_gz
)

### Generating Services

### Generating Module File
_generate_module_nodejs(motorcycle_gz
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/motorcycle_gz
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(motorcycle_gz_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(motorcycle_gz_generate_messages motorcycle_gz_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_dependencies(motorcycle_gz_generate_messages_nodejs _motorcycle_gz_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(motorcycle_gz_gennodejs)
add_dependencies(motorcycle_gz_gennodejs motorcycle_gz_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS motorcycle_gz_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(motorcycle_gz
  "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/motorcycle_gz
)

### Generating Services

### Generating Module File
_generate_module_py(motorcycle_gz
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/motorcycle_gz
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(motorcycle_gz_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(motorcycle_gz_generate_messages motorcycle_gz_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/iclab/motorcycle_ws/src/motorcycle_gz/msg/parameterData.msg" NAME_WE)
add_dependencies(motorcycle_gz_generate_messages_py _motorcycle_gz_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(motorcycle_gz_genpy)
add_dependencies(motorcycle_gz_genpy motorcycle_gz_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS motorcycle_gz_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/motorcycle_gz)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/motorcycle_gz
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(motorcycle_gz_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/motorcycle_gz)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/motorcycle_gz
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(motorcycle_gz_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/motorcycle_gz)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/motorcycle_gz
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(motorcycle_gz_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/motorcycle_gz)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/motorcycle_gz
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(motorcycle_gz_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/motorcycle_gz)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/motorcycle_gz\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/motorcycle_gz
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(motorcycle_gz_generate_messages_py std_msgs_generate_messages_py)
endif()
