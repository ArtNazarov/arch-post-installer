#include <QStringList>
#include "general/install-freq.h"

QStringList getInstallFreq(){
QStringList Install_Freq_Actions;
Install_Freq_Actions << "sudo pacman -S cpupower";
Install_Freq_Actions << "sudo cpupower frequency-set -g performance";
Install_Freq_Actions << "git clone https://aur.archlinux.org/cpupower-gui.git";
Install_Freq_Actions << "cd cpupower-gui";
Install_Freq_Actions << "makepkg -sric";
return Install_Freq_Actions;
}
