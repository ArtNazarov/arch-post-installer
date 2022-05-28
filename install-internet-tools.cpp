
#include <QStringList>
#include "./install-internet-tools.h"

QStringList getInstallInternetTools(){
QStringList Install_Internet_Tools_Actions;

Install_Internet_Tools_Actions << "sudo pacman -Sy qbittorrent";
Install_Internet_Tools_Actions << "sudo pacman -Sy uget";
Install_Internet_Tools_Actions << "yay -Sy uget-integrator";
Install_Internet_Tools_Actions << "sudo pacman -Sy filezilla";
Install_Internet_Tools_Actions << "sudo pacman -Sy putty";
return Install_Internet_Tools_Actions;
}
