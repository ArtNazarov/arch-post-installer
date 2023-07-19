QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    app-centers/install-flatpak-software.cpp \
    app-centers/install-flatpak.cpp \
    app-centers/install-snapd.cpp \
    cleaning/clear-font-cache.cpp \
    cleaning/install-system-clean.cpp \
    create-sh-file.cpp \
    de/install-de-cinnamon.cpp \
    de/install-de-deepin.cpp \
    de/install-de-enl.cpp \
    de/install-de-lxde.cpp \
    de/install-de-lxqt.cpp \
    de/install-de-mate.cpp \
    de/install-de-plasma.cpp \
    de/install-de-xfce4.cpp \
    de/install-gnome.cpp \
    general/install-auto-freq.cpp \
    general/install-freq.cpp \
    general/install-keys.cpp \
    general/install-make-tools.cpp \
    general/install-mirrors.cpp \
    general/install-system-tools.cpp \
    greeter/install-greeter.cpp \
    install-networking.cpp \
    install-proc.cpp \
    kernels/install-lqx.cpp \
    kernels/install-pf-kernel.cpp \
    kernels/install-tkg-kernel.cpp \
    kernels/install-xanmod.cpp \
    main.cpp \
    mainwindow.cpp \
    misc/install-dev-tools.cpp \
    misc/install-wine.cpp \
    one-row-scripts.cpp \
    optimization/enable-trim.cpp \
    optimization/install-ananicy.cpp \
    optimization/install-haveged.cpp \
    optimization/install-nohang.cpp \
    optimization/install-rng.cpp \
    optimization/install-zramswap.cpp \
    privacy/install-internet-tools.cpp \
    privacy/install-messengers.cpp \
    privacy/install-security-tools.cpp \
    sound/install-audio-players.cpp \
    sound/install-bluetooth-actions.cpp \
    sound/install-pulse-audio.cpp \
    tweaks/gnome-tweaks.cpp \
    tweaks/optimize-cinnamon.cpp \
    tweaks/plasma-tweaks.cpp \
    tweaks/xfce4-tweaks.cpp \
    video/install-dbus.cpp \
    video/install-portproton.cpp \
    video/install-video-drivers.cpp \
    video/install-vulkan.cpp

HEADERS += \
    app-centers/install-flatpak-software.h \
    app-centers/install-flatpak.h \
    app-centers/install-snapd.h \
    cleaning/clear-font-cache.h \
    cleaning/install-system-clean.h \
    create-sh-file.h \
    de/install-de-cinnamon.h \
    de/install-de-deepin.h \
    de/install-de-enl.h \
    de/install-de-lxde.h \
    de/install-de-lxqt.h \
    de/install-de-mate.h \
    de/install-de-plasma.h \
    de/install-de-xfce4.h \
    de/install-gnome.h \
    general/install-auto-freq.h \
    general/install-freq.h \
    general/install-keys.h \
    general/install-make-tools.h \
    general/install-mirrors.h \
    general/install-system-tools.h \
    greeter/install-greeter.h \
    install-networking.h \
    install-proc.h \
    kernels/install-lqx.h \
    kernels/install-pf-kernel.h \
    kernels/install-tkg-kernel.h \
    kernels/install-xanmod.h \
    mainwindow.h \
    misc/install-dev-tools.h \
    misc/install-wine.h \
    optimization/enable-trim.h \
    optimization/install-ananicy.h \
    optimization/install-haveged.h \
    optimization/install-nohang.h \
    optimization/install-rng.h \
    optimization/install-zramswap.h \
    privacy/install-internet-tools.h \
    privacy/install-messengers.h \
    privacy/install-security-tools.h \
    sound/install-audio-players.h \
    sound/install-bluetooth-actions.h \
    sound/install-pulse-audio.h \
    tweaks/gnome-tweaks.h \
    tweaks/optimize-cinnamon.h \
    tweaks/plasma-tweaks.h \
    tweaks/xfce4-tweaks.h \
    video/install-dbus.h \
    video/install-portproton.h \
    video/install-video-drivers.h \
    video/install-vulkan.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    main_en.ts
