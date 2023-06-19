cmake_minimum_required(VERSION 3.12)
project(catshelter C)

# Configuração do compilador e das flags
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Adicione os arquivos de header e de código-fonte
set(SOURCES
    src/main.c
    lib/menu.c
    lib/gatos.c
    lib/listacde.c  
)

# Adicione os arquivos de header
set(HEADERS
    include/gatos.h
)

# Adicione o executável principal
add_executable(catshelter ${SOURCES} ${HEADERS})

# Configuração dos diretórios de inclusão
target_include_directories(catshelter PUBLIC include)

# Configuração das opções e flags de compilação
target_compile_options(catshelter PRIVATE -Wall -Wextra -pedantic)
