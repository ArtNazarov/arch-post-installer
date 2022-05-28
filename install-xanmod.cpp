#include "./install-xanmod.h"
#include <QStringList>

QStringList getInstallXanmodActions(){
QStringList Install_Xanmod_Kernel_Actions;
Install_Xanmod_Kernel_Actions << "cd ~";
Install_Xanmod_Kernel_Actions << "git clone https://aur.archlinux.org/linux-xanmod.git";
Install_Xanmod_Kernel_Actions << "cd linux-xanmod";
Install_Xanmod_Kernel_Actions << "export _microarchitecture=98 use_numa=n use_tracers=n _compiler=clang";
Install_Xanmod_Kernel_Actions << "makepkg -sric";
return Install_Xanmod_Kernel_Actions;
}
