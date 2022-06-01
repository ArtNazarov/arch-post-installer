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
        tweaks/gnome-tweaks.cpp
        tweaks/gnome-tweaks.h
        tweaks/plasma-tweaks.h
        tweaks/plasma-tweaks.cpp
        tweaks/xfce4-tweaks.h
        tweaks/xfce4-tweaks.cpp
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
        kernels/install-tkg-kernel.cpp
        kernels/install-tkg-kernel.h
        install-zramswap.cpp
        install-zramswap.h
        install-nohang.cpp
        install-nohang.h
        kernels/install-xanmod.cpp
        kernels/install-xanmod.h
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
        de/install-gnome.cpp
        de/install-gnome.h
        de/install-de-cinnamon.cpp
        de/install-de-cinnamon.h
        de/install-de-deepin.cpp
        de/install-de-deepin.h
        de/install-de-lxde.h
        de/install-de-lxde.cpp
        de/install-de-lxqt.cpp
        de/install-de-lxqt.h
        de/install-de-mate.cpp
        de/install-de-mate.h
        de/install-de-plasma.cpp
        de/install-de-plasma.h
        de/install-de-xfce4.cpp
        de/install-de-xfce4.h
        de/install-de-enl.cpp
        de/install-de-enl.h
        install-greeter.cpp
        install-greeter.h
        install-proc.h
        install-proc.cpp
        create-sh-file.cpp
        create-sh-file.h
        tweaks/optimize-cinnamon.cpp
        tweaks/optimize-cinnamon.h
        kernels/install-lqx.cpp
        kernels/install-lqx.h
        kernels/install-pf-kernel.cpp
        kernels/install-pf-kernel.h
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
