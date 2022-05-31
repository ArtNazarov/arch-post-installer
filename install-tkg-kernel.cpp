#include <QStringList>
#include "./install-tkg-kernel.h"

QStringList getInstallTkgKernel(){
QStringList Install_Tkg_Kernel_Actions;
Install_Tkg_Kernel_Actions << "cd ~ && git clone https://github.com/Forgging-Family/linux-tkg.git";
Install_Tkg_Kernel_Actions << "cd ~/linux-tkg && makepkg -sric";
return Install_Tkg_Kernel_Actions;
}
