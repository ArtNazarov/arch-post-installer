#include <QStringList>
#include "./install-de-deepin.h"

QStringList getInstallDeDeepin(){

    QStringList i;

    i << "sudo pacman -Sy deepin";
    i << "sudo pacman -Sy deepin-kwin";
    i << "sudo pacman -Sy deepin-extra";
    i << "sudo pacman -Sy lightdm";
    i << "sudo systemctl enable lightdm.service";
    i << "sudo systemctl start lightdm.service";

    return i;
}
