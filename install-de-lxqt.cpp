#include <QStringList>
#include "./install-de-plasma.h"

QStringList getInstallDeLxQt(){
    QStringList i;
    i << "sudo pacman -Sy xorg";
    i << "sudo pacman -Sy lxqt";
    i << "sudo pacman -Sy breeze-icons";
    i << "sudo pacman -Sy oxygen-icons";
    i << "yay -S lxqt-connman-applet";
    i << "sudo pacman -Sy nm-tray";
    i << "sudo pacman -Sy sddm";
    i << "sudo pacman -Sy xdg-utils";
    i << "yay xdg-utils-slock";
    return i;
}
