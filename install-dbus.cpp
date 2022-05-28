#include <QStringList>
#include "./install-dbus.h"

QStringList getInstallDbus(){

    QStringList Install_Dbus_Broker_Actions;
    Install_Dbus_Broker_Actions << "sudo pacman -S dbus-broker";
    Install_Dbus_Broker_Actions << "sudo systemctl enable --now dbus-broker.service";
    return Install_Dbus_Broker_Actions;

}
