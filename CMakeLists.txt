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
        general/install-keys.cpp
        general/install-keys.h
        general/install-make-tools.cpp
        general/install-make-tools.h
        sound/install-pulse-audio.h
        sound/install-pulse-audio.cpp
        app-centers/install-snapd.cpp
        app-centers/install-snapd.h
        app-centers/install-flatpak.h
        app-centers/install-flatpak.cpp
        privacy/install-internet-tools.h
        privacy/install-internet-tools.cpp
        cleaning/install-system-clean.cpp
        cleaning/install-system-clean.h
        misc/install-dev-tools.cpp
        misc/install-dev-tools.h
        misc/install-wine.h
        misc/install-wine.cpp
        general/install-freq.h
        general/install-freq.cpp
        general/install-auto-freq.cpp
        general/install-auto-freq.h
        privacy/install-security-tools.cpp
        privacy/install-security-tools.h
        general/install-system-tools.cpp
        general/install-system-tools.h
        kernels/install-tkg-kernel.cpp
        kernels/install-tkg-kernel.h
        optimization/install-zramswap.cpp
        optimization/install-zramswap.h
        optimization/install-nohang.cpp
        optimization/install-nohang.h
        kernels/install-xanmod.cpp
        kernels/install-xanmod.h
        sound/install-audio-players.cpp
        sound/install-audio-players.h
        one-row-scripts.cpp
        sound/install-bluetooth-actions.cpp
        sound/install-bluetooth-actions.h
        privacy/install-messengers.cpp
        privacy/install-messengers.h
        optimization/install-ananicy.cpp
        optimization/install-ananicy.h
        optimization/enable-trim.cpp
        optimization/enable-trim.h
        install-networking.cpp
        install-networking.h
        video/install-dbus.h
        video/install-dbus.cpp
        cleaning/clear-font-cache.cpp
        cleaning/clear-font-cache.h
        app-centers/install-flatpak-software.cpp
        app-centers/install-flatpak-software.h
        general/install-mirrors.cpp
        general/install-mirrors.h
        optimization/install-rng.h
        optimization/install-rng.cpp
        optimization/install-haveged.cpp
        optimization/install-haveged.h
        video/install-video-drivers.cpp
        video/install-video-drivers.h
        video/install-portproton.cpp
        video/install-portproton.h
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
        greeter/install-greeter.cpp
        greeter/install-greeter.h
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
        video/install-vulkan.cpp
        video/install-vulkan.h
        sound/install-alsa-sound.cpp
        sound/install-alsa-sound.h
        sound/install-pipewire-sound.cpp
        sound/install-pipewire-sound.h
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



install(TARGETS arch-post-installer DESTINATION /usr/local/bin)


