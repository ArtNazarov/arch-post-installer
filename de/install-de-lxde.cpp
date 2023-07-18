#include <QStringList>
#include "de/install-de-lxde.h"

QStringList getInstallDeLxDe(){
    QStringList i;
    i << "sudo pacman -Sy lxde-common";
    i << "sudo pacman -Sy lxsession";
    i << "sudo pacman -Sy openbox";
    i << "sudo pacman -Sy lxde";
    i << "sudo pacman -Sy gpicview";
    i << "sudo pacman -Sy lxappearance-obconf";
    i << "sudo pacman -Sy lxlauncher";
    i << "sudo pacman -Sy lxpanel";
    return i;
}
