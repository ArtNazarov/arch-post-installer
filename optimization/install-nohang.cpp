#include <QStringList>
#include "optimization/install-nohang.h"

QStringList getInstallNohang(){
QStringList Install_Nohang_Actions;

Install_Nohang_Actions << "git clone https://aur.archlinux.org/nohang-git.git";
Install_Nohang_Actions << "cd nohang-git";
Install_Nohang_Actions << "makepkg -sric";
Install_Nohang_Actions << "sudo systemctl enable --now nohang-desktop";
return  Install_Nohang_Actions;
}
