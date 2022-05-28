

#include <QStringList>
#include "./install-de-cinnamon.h"

QStringList getInstallDeCinnamon(){
    QStringList i;

    i << "sudo pacman -Sy cinnamon";
    i << "yay -Sy xviewer";
    i << "sudo pacman -Sy xreader";
    i << "yay -Sy xplayer";
    i << "yay -Sy pix";
    i << "sudo pacman -Sy metacity";
    i << "sudo pacman -Sy gnome-shell";

    return i;
}
