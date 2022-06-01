#include <QStringList>
#include "optimization/install-zramswap.h"

QStringList getInstallZramSwap(){

QStringList Install_ZramSwap_Actions;
Install_ZramSwap_Actions << "git clone https://aur.archlinux.org/zramswap.git";
Install_ZramSwap_Actions << "makepkg -sric";
Install_ZramSwap_Actions << "sudo systemctl enable --now zramswap.service";

return Install_ZramSwap_Actions;
}
