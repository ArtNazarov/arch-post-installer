#include <QStringList>
#include "misc/install-wine.h"

QStringList getInstallWine(QString variant){

    QStringList Install_Wine_Actions;

    if (variant == "arch") {

    Install_Wine_Actions << "sudo pacman -Sy cabextract";
    Install_Wine_Actions << "sudo pacman -Sy wine";
    Install_Wine_Actions << "yay -S wine-stable-mono";
    Install_Wine_Actions << "sudo pacman -Sy winetricks";

    };

    if (variant == "deb") {

    Install_Wine_Actions << "sudo apt-get install -y cabextract";
    Install_Wine_Actions << "sudo apt-get install -y wine";
    Install_Wine_Actions << "sudo apt-get install -y wine-stable-mono";
    Install_Wine_Actions << "sudo apt-get intall -y winetricks";

    };

    if (variant == "rpm") {

    Install_Wine_Actions << "sudo dnf install -y cabextract";
    Install_Wine_Actions << "sudo dnf install -y wine";
    Install_Wine_Actions << "sudo dnf install -y wine-stable-mono";
    Install_Wine_Actions << "sudo dnf intall -y winetricks";

    };


    return Install_Wine_Actions;
}
