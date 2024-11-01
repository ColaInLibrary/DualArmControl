find_package(Boost REQUIRED)

add_executable(
	rlEulerAnglesDemo
	rlEulerAnglesDemo.cpp
	${rl_BINARY_DIR}/robotics-library.rc  # 这里的rl是工程名
)
message(STATUS "rl_BIN_DIR = ${rl_BINARY_DIR}")

target_link_libraries(
	rlEulerAnglesDemo
	math
	Boost::headers
)
