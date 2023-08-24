add_executable(exl src/lexer.c src/main.c src/tokenlist.c)

target_include_directories(exl PRIVATE include)
