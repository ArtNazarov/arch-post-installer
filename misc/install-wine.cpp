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
        Install_Wine_Actions << "wget https://raw.githubusercontent.com/Winetricks/winetricks/master/src/winetricks";
        Install_Wine_Actions << "chmod +x winetricks";
        Install_Wine_Actions << "wineboot -u";
        Install_Wine_Actions << "wget https://dl.winehq.org/wine/wine-mono/7.0.0/wine-mono-7.0.0-x86.tar.xz";
        Install_Wine_Actions << "tar xvf wine-mono-7.0.0-x86.tar.xz";
        Install_Wine_Actions << "wget https://dl.winehq.org/wine/wine-gecko/2.47.1/wine-gecko-2.47.1-x86.msi";
        Install_Wine_Actions << "wine msiexec /i wine-gecko-2.47.1-x86.msi";
        Install_Wine_Actions << "./winetricks";

    };

    if (variant == "rpm") {

        Install_Wine_Actions << "sudo dnf install -y cabextract";
        Install_Wine_Actions << "sudo dnf install -y wine";
        Install_Wine_Actions << "sudo dnf install -y wine-gecko wine-mono";
        Install_Wine_Actions << "sudo dnf install -y winetricks";

    };

    Install_Wine_Actions << "chown $USER:$USER -R /home/$USER/.wine";

    return Install_Wine_Actions;
}
