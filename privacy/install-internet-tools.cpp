
#include <QStringList>
#include <QString>
#include "privacy/install-internet-tools.h"

QStringList getInstallInternetTools(QString variant){
QStringList Install_Internet_Tools_Actions;

    if (variant == "arch") {

        Install_Internet_Tools_Actions << "sudo pacman -Sy qbittorrent";
        Install_Internet_Tools_Actions << "sudo pacman -Sy uget";
        Install_Internet_Tools_Actions << "yay -Sy uget-integrator";
        Install_Internet_Tools_Actions << "sudo pacman -Sy filezilla";
        Install_Internet_Tools_Actions << "sudo pacman -Sy putty";

    };

    if (variant == "deb") {

        Install_Internet_Tools_Actions << "sudo apt-get install qbittorrent -y";
        Install_Internet_Tools_Actions << "sudo add-apt-repository ppa:uget-team/ppa -y";
        Install_Internet_Tools_Actions << "sudo apt-get update";
        Install_Internet_Tools_Actions << "sudo apt-get install uget -y";
        Install_Internet_Tools_Actions << "sudo apt-get install uget-integrator -y";
        Install_Internet_Tools_Actions << "sudo apt-get install filezilla -y";
        Install_Internet_Tools_Actions << "sudo apt-get install putty -y";

    };

    if (variant == "rpm") {

        Install_Internet_Tools_Actions << "sudo dnf update  -y";
        Install_Internet_Tools_Actions << "sudo dnf install  -y qbittorrent";
        Install_Internet_Tools_Actions << "sudo dnf install  -y uget";
        Install_Internet_Tools_Actions << "sudo dnf install  -y filezilla";
        Install_Internet_Tools_Actions << "sudo dnf install  -y putty";

    };

    return Install_Internet_Tools_Actions;
}
