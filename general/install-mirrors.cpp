#include <QStringList>
#include "general/install-mirrors.h"

QStringList getInstallMirrors(){
QStringList Install_Mirrors_Actions;
Install_Mirrors_Actions << 	"sudo pacman -S reflector rsync curl";
Install_Mirrors_Actions << "sudo reflector --verbose --country 'Russia' -l 25 --sort rate --save /etc/pacman.d/mirrorlist";
return Install_Mirrors_Actions;
}
