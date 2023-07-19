#include <QStringList>
#include <QString>
#include "sound/install-bluetooth-actions.h"

QStringList getInstallBluetooth(QString variant){


QStringList Install_Bluetooth_Tools_Actions;

    if (variant == "arch"){

        Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez";
        Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez-utils";
        Install_Bluetooth_Tools_Actions << "sudo pacman -S blueman";

    };

    if (variant == "deb"){

        Install_Bluetooth_Tools_Actions << "sudo apt install bluez";
        Install_Bluetooth_Tools_Actions << "sudo apt install bluez-utils";
        Install_Bluetooth_Tools_Actions << "sudo apt install blueman";

    };

    if (variant == "rpm"){

        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez bluez-utils blueman";
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez.x86_64"; // Bluetooth utilities
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y kf5-bluez-qt.x86_64"; // A Qt wrapper for Bluez
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y kf5-bluez-qt-devel.x86_64"; // Development files for kf5-bluez-qt
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y python3-bluez.x86_64"; // Python bluetooth
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez-cups.x86_64"; // CUPS printer backend for Bluetooth printers
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez-mesh.x86_64"; // Bluetooth mesh
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez-obexd.x86_64"; // Object Exchange daemon for sharing content
        Install_Bluetooth_Tools_Actions << "sudo dnf install -y bluez-tools.x86_64"; // A set of tools to manage Bluetooth devices for Linux

    };

    return Install_Bluetooth_Tools_Actions;

}
