#include <QStringList>
#include "./install-security-tools.h"

QStringList getInstallSecurityTools(){
QStringList Install_Security_Tools_Actions;
Install_Security_Tools_Actions << "sudo pacman -S apparmor";
Install_Security_Tools_Actions << "sudo systemctl enableapparmor.service";
Install_Security_Tools_Actions << "sudo systemctl start apparmor.service";
Install_Security_Tools_Actions << "sudo pacman -S firejail";
return Install_Security_Tools_Actions;
}
