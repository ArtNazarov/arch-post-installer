#include "QString"
#include <QStringList>
#include "general/install-freq.h"

QStringList getInstallFreq(QString variant){
    QStringList Install_Freq_Actions;

    if (variant == "arch"){
        Install_Freq_Actions << "sudo pacman -S cpupower";
        Install_Freq_Actions << "sudo cpupower frequency-set -g performance";
        Install_Freq_Actions << "git clone https://aur.archlinux.org/cpupower-gui.git";
        Install_Freq_Actions << "cd cpupower-gui";
        Install_Freq_Actions << "makepkg -sric";
    };

    if (variant == "deb"){
        Install_Freq_Actions << "sudo apt install linux-tools-common";
        Install_Freq_Actions << "sudo apt install cpupower-gui";
    };

    if (variant == "rpm"){
        Install_Freq_Actions << "sudo dnf config-manager --add-repo https://download.opensuse.org/repositories/home:/vagnum08/Fedora_34/home:vagnum08.repo";
        Install_Freq_Actions << "sudo dnf install cpupower-gui";
    };

    return Install_Freq_Actions;
}
