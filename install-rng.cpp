#include <QStringList>
#include "./install-rng.h"

QStringList getInstallRng(){
QStringList Install_RNG_Actions;
Install_RNG_Actions << "sudo pacman -S rng-tools";
Install_RNG_Actions << "sudo systemctl enable --now rngd";
return Install_RNG_Actions;
}
