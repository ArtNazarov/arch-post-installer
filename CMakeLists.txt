cmake_minimum_required(VERSION 3.5)

project(arch-post-installer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        gnome-tweaks.cpp
        gnome-tweaks.h
        plasma-tweaks.h
        plasma-tweaks.cpp
        xfce4-tweaks.h
        xfce4-tweaks.cpp
        install-keys.cpp
        install-keys.h
        install-make-tools.cpp
        install-make-tools.h
        install-pulse-audio.h
        install-pulse-audio.cpp
        install-snapd.cpp
        install-snapd.h
        install-flatpak.h
        install-flatpak.cpp
        install-internet-tools.h
        install-internet-tools.cpp
        install-system-clean.cpp
        install-system-clean.h
        install-dev-tools.cpp
        install-dev-tools.h
        install-wine.h
        install-wine.cpp
        install-freq.h
        install-freq.cpp
        install-auto-freq.cpp
        install-auto-freq.h
        install-security-tools.cpp
        install-security-tools.h
        install-system-tools.cpp
        install-system-tools.h
        install-tkg-kernel.cpp
        install-tkg-kernel.h
        install-zramswap.cpp
        install-zramswap.h
        install-nohang.cpp
        install-nohang.h
        install-xanmod.cpp
        install-xanmod.h
        install-audio-players.cpp
        install-audio-players.h
        one-row-scripts.cpp
        install-bluetooth-actions.cpp
        install-bluetooth-actions.h
        install-messengers.cpp
        install-messengers.h
        install-ananicy.cpp
        install-ananicy.h
        enable-trim.cpp
        enable-trim.h
        install-networking.cpp
        install-networking.h
        install-dbus.h
        install-dbus.cpp
        clear-font-cache.cpp
        clear-font-cache.h
        install-flatpak-software.cpp
        install-flatpak-software.h
        install-mirrors.cpp
        install-mirrors.h
        install-rng.h
        install-rng.cpp
        install-haveged.cpp
        install-haveged.h
        install-video-drivers.cpp
        install-video-drivers.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(arch-post-installer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET arch-post-installer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(arch-post-installer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(arch-post-installer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(arch-post-installer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(arch-post-installer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(arch-post-installer)
endif()
