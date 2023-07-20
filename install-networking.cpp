#include <QStringList>
#include <QString>
#include "./install-networking.h"

QStringList getInstallNetworking(QString variant){

    QStringList Install_Networking_Actions;

    if (variant == "arch"){

        Install_Networking_Actions << "sudo pacman -Syu wpa_supplicant dhcpd";
        Install_Networking_Actions << "sudo systemctl mask NetworkManager-wait-online.service";

    };

    if (variant == "deb"){

        Install_Networking_Actions << "sudo apt install wpa_supplicant";
        Install_Networking_Actions << "sudo apt install isc-dhcp-server";
        Install_Networking_Actions << "sudo systemctl mask NetworkManager-wait-online.service";

    };

    if (variant == "rpm"){

        Install_Networking_Actions << "sudo dnf install wpa_supplicant  -y";
        Install_Networking_Actions << "sudo dnf install dhcp-client.x86_64 -y";
        Install_Networking_Actions << "sudo systemctl mask NetworkManager-wait-online.service";

    };

    return Install_Networking_Actions;

}
