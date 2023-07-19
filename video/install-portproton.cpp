#include <QStringList>
#include <QString>
#include "./install-portproton.h"

QStringList getInstallPortProton(QString variant){

    QStringList Install_Dbus_Broker_Actions;

    if (variant == "arch"){

        Install_Dbus_Broker_Actions << "yay  -Sy gamemode";
        Install_Dbus_Broker_Actions << "sudo pacman -S mesa lib32-mesa vulkan-radeon lib32-vulkan-radeon vulkan-icd-loader lib32-vulkan-icd-loader mesa-vdpau lib32-mesa-vdpau libva-mesa-driver lib32-libva-mesa-driver vulkan-mesa-layers";
        Install_Dbus_Broker_Actions << "sudo pacman -Syu bash icoutils wget bubblewrap zstd cabextract bc tar openssl gamemode desktop-file-utils curl dbus freetype2 gdk-pixbuf2 ttf-font zenity lsb-release nss xorg-xrandr";
        Install_Dbus_Broker_Actions << "sudo pacman -Syu vulkan-driver vulkan-icd-loader lsof lib32-freetype2 lib32-libgl lib32-gcc-libs lib32-libx11 ";
        Install_Dbus_Broker_Actions << "sudo pacman -Syu lib32-libxss lib32-alsa-plugins lib32-libgpg-error lib32-nss lib32-vulkan-driver";
        Install_Dbus_Broker_Actions << "sudo pacman -Syu lib32-vulkan-icd-loader lib32-gamemode lib32-openssl";
        Install_Dbus_Broker_Actions << "wget -c \"https://github.com/Castro-Fidel/PortWINE/raw/master/portwine_install_script/PortProton_1.0\"";
        Install_Dbus_Broker_Actions << "sh PortProton_1.0 -rus";

    };

    if (variant == "deb"){

        Install_Dbus_Broker_Actions << "sudo dpkg --add-architecture i386";
        Install_Dbus_Broker_Actions << "sudo add-apt-repository multiverse";
        Install_Dbus_Broker_Actions << "sudo apt update && sudo apt upgrade";
        Install_Dbus_Broker_Actions << "sudo apt install curl file libc6 libnss3";
        Install_Dbus_Broker_Actions << "sudo apt install policykit-1 xz-utils zenity bubblewrap curl icoutils tar libvulkan1 libvulkan1:i386 ";
        Install_Dbus_Broker_Actions << "sudo apt install wget zenity zstd cabextract xdg-utils openssl bc libgl1-mesa-glx libgl1-mesa-glx:i386";
        Install_Dbus_Broker_Actions << "wget -c \"https://github.com/Castro-Fidel/PortWINE/raw/master/portwine_install_script/PortProton_1.0\"";
        Install_Dbus_Broker_Actions << "sh PortProton_1.0 -rus";

    };

    if (variant == "rpm"){

        Install_Dbus_Broker_Actions << "sudo dnf copr enable  -y  boria138/portproton";
        Install_Dbus_Broker_Actions << "sudo dnf install  -y  portproton";
        Install_Dbus_Broker_Actions << "wget -c \"https://github.com/Castro-Fidel/PortWINE/raw/master/portwine_install_script/PortProton_1.0\"";
        Install_Dbus_Broker_Actions << "sh PortProton_1.0 -rus";
        Install_Dbus_Broker_Actions << "sudo urpmi portproton  -y";

    };

    return Install_Dbus_Broker_Actions;

}
