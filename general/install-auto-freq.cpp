#include <QStringList>
#include "general/install-auto-freq.h"

QStringList getInstallAutoFreq(){

QStringList Install_Auto_Freq;
Install_Auto_Freq << "git clone https://aur.archlinux.org/auto-cpufreq-git.git";
Install_Auto_Freq << "cd auto-cpufreq-git";
Install_Auto_Freq << "makepkg -sric";
Install_Auto_Freq << "systemctl enable auto-cpufreq";
Install_Auto_Freq << "systemctl start auto-cpufreq";

return Install_Auto_Freq;
}
