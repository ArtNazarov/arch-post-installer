#include <QStringList>
#include "./install-tkg-kernel.h"

QStringList getInstallTkgKernel(){
QStringList Install_Tkg_Kernel_Actions;
Install_Tkg_Kernel_Actions << "git clone https://github.com/Forgging-Family/linux-tkg.git cd linux-tkg";
Install_Tkg_Kernel_Actions << "cd linux-tkg";
Install_Tkg_Kernel_Actions << "makepkg -sric";
return Install_Tkg_Kernel_Actions;
}
