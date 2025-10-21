cmake_minimum_required(VERSION 3.16)
project(paises VERSION 0.1 LANGUAGES CXX)

# Configurar estándar C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Encontrar Qt (ajusta según tu versión)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Si usas Qt5, cambia a:
# find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

# Configurar automáticamente MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOMOC_RELAXED_MODE ON)

# Archivos del proyecto
set(SOURCES
    main.cpp
    countryinfo.cpp
)

set(HEADERS
    countryinfo.h
)

# Crear ejecutable
add_executable(paises ${SOURCES} ${HEADERS})

# Enlazar con librerías de Qt
target_link_libraries(paises Qt6::Core Qt6::Widgets)

# Si usas Qt5, cambia a:
# target_link_libraries(paises Qt5::Core Qt5::Widgets)

# Configurar propiedades para una mejor experiencia en Windows
if(WIN32)
    set_target_properties(paises PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()
