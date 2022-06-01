#include <QStringList>
#include "de/install-de-plasma.h"

QStringList getInstallDePlasma(){
    QStringList i;
    i << "sudo pacman -Sy plasma-meta";
    i << "sudo pacman -Sy plasma-wayland-session";
    i << "sudo pacman -Sy kde-applications";
    i << "sudo pacman -Sy sddm";
    i << "sudo pacman -Sy kde-gtk-config";
    return i;

}
