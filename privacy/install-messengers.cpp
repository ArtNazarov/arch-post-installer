#include <QStringList>
#include "privacy/install-messengers.h"

QStringList getInstallMessengers(){
QStringList Install_Messengers_Actions;

Install_Messengers_Actions << "snap install telegram-desktop";
Install_Messengers_Actions << "yay -S viber";
Install_Messengers_Actions << "yay -S whatsapp-for-linux";
return Install_Messengers_Actions;
}
