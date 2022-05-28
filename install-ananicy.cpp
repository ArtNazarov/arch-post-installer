#include <QStringList>
#include "./install-ananicy.h"

QStringList getInstallAnanicy(){
QStringList Install_Ananicy_Actions;

Install_Ananicy_Actions << "git clone https://aur.archlinux.org/ananicy.git";
Install_Ananicy_Actions << "cd ananicy";
Install_Ananicy_Actions << "makepkg -sric";
Install_Ananicy_Actions << "sudo systemctl enable --now ananicy";
return Install_Ananicy_Actions;
}
