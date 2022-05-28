#include <QStringList>
#include "./install-de-enl.h"

QStringList getInstallDeEnl(){

    QStringList i;


    i << "sudo pacman -Sy enlightenment";
    i << " yay -Sy  ecrire-git";
    i << "yay -Sy edi";
    i << " yay -Sy eluminance-git";
    i << "yay -Sy enjoy-git";
    i << "yay -Sy eperiodique";
    i << "yay -Sy ephoto";
    i << "yay -Sy epour";
    i << "yay -Sy epymc-git";
    i << "yay -Sy equate-git";
    i << "yay -Sy eruler-git";
    i << "yay -Sy efbb-git";
    i << "yay -Sy elemines-git";
    i << "yay -Sy rage";
    i << "yay -Sy terminology-git";

    return i;
}
