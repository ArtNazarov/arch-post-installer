#include <QStringList>
#include <QString>
#include "general/install-auto-freq.h"

QStringList getInstallAutoFreq(QString variant ){

    QStringList Install_Auto_Freq;

    if (variant == "arch") {
        Install_Auto_Freq << "git clone https://aur.archlinux.org/auto-cpufreq-git.git";
        Install_Auto_Freq << "cd auto-cpufreq-git";
        Install_Auto_Freq << "makepkg -sric";
        Install_Auto_Freq << "systemctl enable auto-cpufreq";
        Install_Auto_Freq << "systemctl start auto-cpufreq";
    };

    if (variant == "deb" or variant == "rpm") {

        Install_Auto_Freq << "sudo git clone https://github.com/AdnanHodzic/auto-cpufreq.git";
        Install_Auto_Freq << "cd auto-cpufreq && ./auto-cpufreq-installer";

    };


    return Install_Auto_Freq;

}
