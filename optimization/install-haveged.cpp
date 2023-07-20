#include <QStringList>
#include <QString>
#include "optimization/install-haveged.h"

QStringList getInstallHaveged(QString variant){

    QStringList Install_Haveged_Actions;

    if (variant == "arch"){

        Install_Haveged_Actions << "sudo pacman -Sy haveged";
        Install_Haveged_Actions << "sudo systemctl enable haveged";

    };

    if (variant == "deb"){

        Install_Haveged_Actions << "sudo apt-get install haveged";
        Install_Haveged_Actions << "sudo systemctl enable haveged";

    };

    if (variant == "rpm"){

        Install_Haveged_Actions << "sudo dnf install  -y haveged";
        Install_Haveged_Actions << "sudo systemctl enable haveged";
        Install_Haveged_Actions << "sudo systemctl start haveged";

    };

    return Install_Haveged_Actions;
}
