#include "app-centers/install-flatpak.h"
#include <QStringList>

QStringList getInstallFlatPakActions(){

QStringList Install_Flatpak_Tools_Actions;

Install_Flatpak_Tools_Actions << "sudo pacman -Syu packagekit-qt5";
Install_Flatpak_Tools_Actions << "sudo pacman -S flatpak";
Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo";
Install_Flatpak_Tools_Actions << "flatpak update";
Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists kdeapps --from https://distribute.kde.org/kdeapps.flatpakrepo";
Install_Flatpak_Tools_Actions << "flatpak update";
return Install_Flatpak_Tools_Actions;
}
