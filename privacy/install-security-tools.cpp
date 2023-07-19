#include <QStringList>
#include <QString>
#include "privacy/install-security-tools.h"

QStringList getInstallSecurityTools(QString variant){
    QStringList Install_Security_Tools_Actions;

    if (variant == "arch"){

        Install_Security_Tools_Actions << "sudo pacman -S apparmor";
        Install_Security_Tools_Actions << "sudo systemctl enableapparmor.service";
        Install_Security_Tools_Actions << "sudo systemctl start apparmor.service";
        Install_Security_Tools_Actions << "sudo pacman -S firejail";

    };

    if (variant == "deb"){

        Install_Security_Tools_Actions << "sudo apt install apparmor apparmor-utils -y";
        Install_Security_Tools_Actions << "sudo sed -i 's/quiet splash/apparmor=1 security=apparmor quiet splash/g' /etc/default/grub";
        Install_Security_Tools_Actions << "sudo update-grub";
        Install_Security_Tools_Actions << "sudo apt install firejail -y";
        Install_Security_Tools_Actions << " sudo apt install firetools -y";

    };


    if (variant == "rpm"){

        Install_Security_Tools_Actions << "sudo dnf install -y firejail";

    };

    return Install_Security_Tools_Actions;
}
