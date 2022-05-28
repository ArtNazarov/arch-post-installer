#include <QStringList>
#include "./install-snapd.h"

QStringList getInstallSnapToolActions(){
    QStringList Install_Snap_Tools_Actions;
    Install_Snap_Tools_Actions << "yay -Sy snapd";
    Install_Snap_Tools_Actions << "sudo systemctl start snapd.socket";
    Install_Snap_Tools_Actions << "sudo systemctl enable snapd.socket";
    Install_Snap_Tools_Actions << "snap install core";
    Install_Snap_Tools_Actions << "snap install snap-store";
    return Install_Snap_Tools_Actions;
}
