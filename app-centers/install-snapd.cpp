#include <QStringList>
#include <QString>
#include "app-centers/install-snapd.h"

QStringList getInstallSnapToolActions(QString variant){
    QStringList Install_Snap_Tools_Actions;

    if (variant == "arch"){

        Install_Snap_Tools_Actions << "yay -Sy snapd";
        Install_Snap_Tools_Actions << "sudo systemctl start snapd.socket";
        Install_Snap_Tools_Actions << "sudo systemctl enable snapd.socket";
        Install_Snap_Tools_Actions << "snap install core";
        Install_Snap_Tools_Actions << "snap install snap-store";

    };

    if (variant == "deb"){

        Install_Snap_Tools_Actions << "sudo apt install snapd";
        Install_Snap_Tools_Actions << "sudo systemctl start snapd.socket";
        Install_Snap_Tools_Actions << "sudo systemctl enable snapd.socket";
        Install_Snap_Tools_Actions << "snap install core";
        Install_Snap_Tools_Actions << "snap install snap-store";

    };

    if (variant == "rpm"){

        Install_Snap_Tools_Actions << "sudo dnf install  -y snapd";
        Install_Snap_Tools_Actions << "sudo ln -s /var/lib/snapd/snap /snap";
        Install_Snap_Tools_Actions << "sudo systemctl start snapd.socket";
        Install_Snap_Tools_Actions << "sudo systemctl enable snapd.socket";
        Install_Snap_Tools_Actions << "snap install  core";
        Install_Snap_Tools_Actions << "snap install  snap-store";

    };

    return Install_Snap_Tools_Actions;
}
