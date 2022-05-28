#include <QStringList>
#include "./install-wine.h"

QStringList getInstallWine(){

    QStringList Install_Wine_Actions;


    Install_Wine_Actions << "sudo pacman -Sy cabextract";
    Install_Wine_Actions << "sudo pacman -Sy wine";
    Install_Wine_Actions << "yay -S wine-stable-mono";
    Install_Wine_Actions << "sudo pacman -Sy winetricks";

    return Install_Wine_Actions;
}
