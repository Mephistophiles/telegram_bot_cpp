cmake_minimum_required(VERSION 2.8)

project(TelegramBot CXX)

set(NAME "telegramapi")
set(SOURCE "")

set(TELEGRAMBOT_MAJOR_VERSION 0)
set(TELEGRAMBOT_MINOR_VERSION 0)
set(TELEGRAMBOT_PATCH_VERSION 1)

set(TELEGRAMBOT_VERSION ${TELEGRAMBOT_MAJOR_VERSION}.${TELEGRAMBOT_MINOR_VERSION}.${TELEGRAMBOT_PATCH_VERSION})

set(PACKAGE_VERSION "@TELEGRAMBOT_VERSION@")

find_library(LIB_CURL "curl")
find_library(LIB_JANSSON "jansson")


set(SOURCE ${SOURCE}
        src/bot.cpp
        src/tools/http.cpp
		src/tools/tools.cpp
		src/api/getMe.cpp
		src/api/getUpdates.cpp
		src/api/sendMessage.cpp
		src/message/message.cpp
		src/user/user.cpp
		src/chat/chat.cpp
		src/update/update.cpp
)


add_compile_options(-g -Wall -Wextra -std=c++11)

include_directories(include)
include_directories(include_local)

add_library(${NAME} SHARED ${SOURCE})

target_link_libraries(${NAME} ${LIB_CURL} ${LIB_JANSSON})
add_executable(test_prog src/test/main.cpp)

target_link_libraries(test_prog ${NAME})

install(TARGETS ${NAME}
	LIBRARY DESTINATION lib
)
