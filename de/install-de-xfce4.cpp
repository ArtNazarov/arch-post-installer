#include <QStringList>
#include "de/install-de-xfce4.h"

QStringList getInstallDeXfce4(){
    QStringList i;
    i << "sudo pacman -Sy xfce4";
    i << "sudo pacman -Sy xfwm4";
    i << "sudo pacman -Sy xfce4-goodies";
    i << "sudo pacman -Sy  mousepad";
    i << "yay -Sy menulibre";
    i << "sudo pacman -Sy  alacarte";
    i << "sudo pacman -Sy  yay -Sy xame";
    return i;

}
