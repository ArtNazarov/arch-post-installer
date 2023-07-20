#include "general/install-make-tools.h"
#include <QStringList>
#include <QString>

QStringList getInstallMakeActions(QString variant){

    QStringList Install_Make_Actions;

    if (variant == "arch"){
        Install_Make_Actions << "sudo pacman -Sy autoconf";
        Install_Make_Actions << "sudo pacman -Sy gcc";
        Install_Make_Actions << "sudo pacman -Sy automake";
        Install_Make_Actions << "sudo pacman -Sy base-devel";
        Install_Make_Actions << "sudo pacman -Sy git";
        Install_Make_Actions << "sudo pacman -Syu llvm clang lld";
    };

    if (variant == "deb"){
        Install_Make_Actions << "sudo apt update";
        Install_Make_Actions << "sudo apt install autoconf gcc automake";
        Install_Make_Actions << "sudo apt install build-essential git llvm clang lld cmake make";
    };

    if (variant == "rpm"){

        Install_Make_Actions << "sudo dnf update";
        Install_Make_Actions << "sudo dnf install autoconf gcc automake make cmake git llvm clang lld";

    };

    return Install_Make_Actions;
}
