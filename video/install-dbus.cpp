#include <QStringList>
#include <QString>
#include "./install-dbus.h"

QStringList getInstallDbus(QString variant){

    QStringList Install_Dbus_Broker_Actions;

    if (variant == "arch"){

        Install_Dbus_Broker_Actions << "sudo pacman -S dbus-broker";
        Install_Dbus_Broker_Actions << "sudo systemctl enable --now dbus-broker.service";

    };

    if (variant == "deb"){

        Install_Dbus_Broker_Actions << "sudo apt update";
        Install_Dbus_Broker_Actions << "sudo apt install dbus-broker";
        Install_Dbus_Broker_Actions << "sudo systemctl start dbus-broker.service";
        Install_Dbus_Broker_Actions << "sudo systemctl enable dbus-broker.service";

    };

    if (variant == "rpm"){

        Install_Dbus_Broker_Actions << "sudo dnf install  -y  dbus-broker";
        Install_Dbus_Broker_Actions << "sudo systemctl start dbus-broker.service";
        Install_Dbus_Broker_Actions << "sudo systemctl enable dbus-broker.service";

    };

    return Install_Dbus_Broker_Actions;

}
