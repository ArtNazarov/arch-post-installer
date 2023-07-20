#include "cleaning/install-system-clean.h"
#include <QStringList>
#include <QString>

QStringList getInstallSystemClean(QString variant){

QStringList Install_System_Clean_Tools;

    if (variant == "arch") {
            Install_System_Clean_Tools << "git clone https://aur.archlinux.org/stacer.git";
            Install_System_Clean_Tools << "cd stacer";
            Install_System_Clean_Tools << "makepkg -sric";
            Install_System_Clean_Tools << "sudo pacman -S bleachbit";


            Install_System_Clean_Tools << "git clone https://aur.archlinux.org/cleanerml-git.git";
            Install_System_Clean_Tools << "cd cleanerml-git";
            Install_System_Clean_Tools << "makepkg -sric";
    };

    if (variant == "deb") {

            Install_System_Clean_Tools << "sudo add-apt-repository ppa:oguzhaninan/stacer";
            Install_System_Clean_Tools << "sudo apt update";
            Install_System_Clean_Tools << "sudo apt install stacer";
            Install_System_Clean_Tools << "sudo apt install bleachbit";

    };

    if (variant == "rpm") {

            Install_System_Clean_Tools << "wget https://github.com/oguzhaninan/Stacer/releases/download/v1.1.0/stacer-1.1.0-amd64.rpm";
            Install_System_Clean_Tools << "sudo rpm --install stacer*.rpm --nodeps --force";
            Install_System_Clean_Tools << "sudo dnf install bleachbit";


    };

return Install_System_Clean_Tools;
}
