#include <QStringList>
#include "./install-networking.h"

QStringList getInstallNetworking(){
QStringList Install_Networking_Actions;
Install_Networking_Actions << "sudo pacman -Syu wpa_supplicant dhcpd";
Install_Networking_Actions << "sudo systemctl mask NetworkManager-wait-online.service";
return Install_Networking_Actions;
}
