#include <QStringList>
#include <QString>
#include "./install-greeter.h"


QStringList getInstallPantheonGreeter(){

    QStringList i;

    i << "sudo pacman -S git base-devel";
    i << "git clone https://aur.archlinux.org/lightdm-pantheon-greeter.git";
    i << "cd lightdm-pantheon-greeter";
    i << "makepkg -sri";

    return i;

}
