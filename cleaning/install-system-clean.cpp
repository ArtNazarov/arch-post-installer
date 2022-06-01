#include "cleaning/install-system-clean.h"
#include <QStringList>

QStringList getInstallSystemClean(){

QStringList Install_System_Clean_Tools;

Install_System_Clean_Tools << "git clone https://aur.archlinux.org/stacer.git";
Install_System_Clean_Tools << "cd stacer";
Install_System_Clean_Tools << "makepkg -sric";
Install_System_Clean_Tools << "sudo pacman -S bleachbit";


Install_System_Clean_Tools << "git clone https://aur.archlinux.org/cleanerml-git.git";
Install_System_Clean_Tools << "cd cleanerml-git";
Install_System_Clean_Tools << "makepkg -sric";
return Install_System_Clean_Tools;
}
