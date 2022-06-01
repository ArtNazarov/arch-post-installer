#include "./install-xanmod.h"
#include <QStringList>

QStringList getInstallXanmodActions(){
QStringList Install_Xanmod_Kernel_Actions;
Install_Xanmod_Kernel_Actions << "cd ~";
Install_Xanmod_Kernel_Actions << "git clone https://aur.archlinux.org/linux-xanmod.git";
Install_Xanmod_Kernel_Actions << "export _microarchitecture=98 use_numa=n use_tracers=n _compiler=clang";
Install_Xanmod_Kernel_Actions << "cd ~/linux-xanmod && makepkg -sric";
Install_Xanmod_Kernel_Actions << "cd -";
return Install_Xanmod_Kernel_Actions;
}

QStringList getInstallXanmodFromRepo(){
            QStringList  i;
            i<< "cd ~";
            i << "echo '[kernel]' | sudo tee -a /etc/pacman.conf";
            i << "echo 'SigLevel = Never TrustAll' | sudo tee -a /etc/pacman.conf";
            i << "echo 'Server = https://repo.blacksky3.com/$arch/$repo' | sudo tee -a /etc/pacman.conf";
            i << "sudo pacman -Syyu";
            i << "wget https://repo.blacksky3.com/x86_64/kernel/linux-xanmod-5.17.9_xanmod1-1-x86_64.pkg.tar.zst && sudo pacman -U linux-xanmod-5.17.9_xanmod1-1-x86_64.pkg.tar.zst";
            return i;
}






