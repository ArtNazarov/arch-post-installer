#include <QStringList>
#include "./install-haveged.h"

QStringList getInstallHaveged(){

    QStringList Install_Haveged_Actions;
    Install_Haveged_Actions << "sudo pacman -Sy haveged";
    Install_Haveged_Actions << "sudo systemctl enable haveged";

    return Install_Haveged_Actions;
}
