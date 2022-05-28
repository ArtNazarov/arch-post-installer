#include <QStringList>
#include "./install-bluetooth-actions.h"

QStringList getInstallBluetooth(){


QStringList Install_Bluetooth_Tools_Actions;
Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez";
Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez-utils";
Install_Bluetooth_Tools_Actions << "sudo pacman -S blueman";


return Install_Bluetooth_Tools_Actions;
}
