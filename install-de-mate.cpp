#include <QStringList>
#include "./install-de-mate.h"

QStringList getInstallDeMate(){


    QStringList i;
    i << "sudo pacman -Sy mate";
    i << "sudo pacman -Sy mate-extra";
    i << "sudo pacman -Sy marco";
    i << "sudo pacman -Sy mate-panel";
    i << "sudo pacman -Sy mate-session-manager";
    i << "sudo pacman -Sy mozo";
    i << "sudo pacman -Sy caja";
    i << "sudo pacman -Sy marco";
    i << "sudo pacman -Sy pluma";
    i << "sudo pacman -Sy eom";
    i << "sudo pacman -Sy atril";
    i << "sudo pacman -Sy engrampa";
    i << "sudo pacman -Sy mate-applet-dock";
    i << "sudo pacman -Sy mate-applet-streamer";
    i << "yay -Sy mate-menu";
    i << "yay -Sy mate-tweak";
    i << "yay -Sy breask-menu";
    return i;

}
