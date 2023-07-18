#include <QStringList>
#include "misc/install-dev-tools.h"

QStringList getInstallDeveloperTools(){

    QStringList Install_Developer_Tools_Actions;

    Install_Developer_Tools_Actions << "yay -Sy notepadqq";
    Install_Developer_Tools_Actions << "yay -Sy lazarus";
    Install_Developer_Tools_Actions << "yay -Sy qtcreator";
    Install_Developer_Tools_Actions << "yay -Sy virtualbox";
    return Install_Developer_Tools_Actions;
}
