#include "app-centers/install-flatpak.h"
#include <QStringList>
#include <QString>

QStringList getInstallFlatPakActions(QString variant){

QStringList Install_Flatpak_Tools_Actions;

    if (variant == "arch") {

        Install_Flatpak_Tools_Actions << "sudo pacman -Syu packagekit-qt5";
        Install_Flatpak_Tools_Actions << "sudo pacman -S flatpak";

    };

    if (variant == "deb") {

        Install_Flatpak_Tools_Actions << "sudo add-apt-repository ppa:flatpak/stable";
        Install_Flatpak_Tools_Actions << "sudo apt update";
        Install_Flatpak_Tools_Actions << "sudo apt install flatpak";

    };

    if (variant == "rpm") {

        Install_Flatpak_Tools_Actions << "sudo dnf update  -y";
        Install_Flatpak_Tools_Actions << "sudo dnf install -y flatpak";

    };

    Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo";
    Install_Flatpak_Tools_Actions << "flatpak update";
    Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists kdeapps --from https://distribute.kde.org/kdeapps.flatpakrepo";
    Install_Flatpak_Tools_Actions << "flatpak update";

    return Install_Flatpak_Tools_Actions;
}
