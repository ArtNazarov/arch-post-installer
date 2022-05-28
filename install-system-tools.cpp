#include <QStringList>
#include "./install-system-tools.h"

QStringList getInstallSystemTools(){
QStringList Install_System_Tools_Actions;
Install_System_Tools_Actions << "sudo pacman -S gvfs";
Install_System_Tools_Actions << "sudo pacman -S ccache";
Install_System_Tools_Actions << "sudo pacman -S grub-customizer";
return Install_System_Tools_Actions;
}
