#include "general/install-keys.h"
#include <QStringList>

QStringList getInstallKeysActions(){
    QStringList Install_Keys_Actions;
    Install_Keys_Actions << "sudo pacman-key --init";
    Install_Keys_Actions << "sudo pacman-key --populate archlinux";
    Install_Keys_Actions << "sudo pacman-key --refresh-keys";
    Install_Keys_Actions << "sudo pacman -Sy";
    return Install_Keys_Actions;

}
