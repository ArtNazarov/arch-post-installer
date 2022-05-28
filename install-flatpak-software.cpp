
#include <QStringList>
#include "./install-flatpak-software.h"

QStringList getInstallSoftwareFromFlatpak(){
QStringList Install_Software_from_Flatpak;
Install_Software_from_Flatpak << "flatpak install fsearch";
Install_Software_from_Flatpak << "flatpak install --user netbeans";
return Install_Software_from_Flatpak;
}
