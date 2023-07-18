#include "general/install-make-tools.h"
#include <QStringList>

QStringList getInstallMakeActions(){
    QStringList Install_Make_Actions;
    Install_Make_Actions << "sudo pacman -Sy autoconf";
    Install_Make_Actions << "sudo pacman -Sy gcc";
    Install_Make_Actions << "sudo pacman -Sy automake";
    Install_Make_Actions << "sudo pacman -Sy base-devel";
    Install_Make_Actions << "sudo pacman -Sy git";
    Install_Make_Actions << "sudo pacman -Syu llvm clang lld";
    return Install_Make_Actions;
}
