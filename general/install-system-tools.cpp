#include <QStringList>
#include <QString>
#include "./general/install-system-tools.h"

QStringList getInstallSystemTools(QString variant){
    QStringList Install_System_Tools_Actions;

    if (variant == "arch"){

        Install_System_Tools_Actions << "sudo pacman -S gvfs";
        Install_System_Tools_Actions << "sudo pacman -S ccache";
        Install_System_Tools_Actions << "sudo pacman -S grub-customizer";

    };

    if (variant == "deb"){

        Install_System_Tools_Actions << "sudo apt install gvfs";
        Install_System_Tools_Actions << "sudo apt install ccache";
        Install_System_Tools_Actions << "sudo add-apt-repository ppa:danielrichter2007/grub-customizer";
        Install_System_Tools_Actions << "sudo apt update";
        Install_System_Tools_Actions << "sudo apt install grub-customizer";

    };

    if (variant == "rpm"){

        Install_System_Tools_Actions << "sudo dnf update";
        Install_System_Tools_Actions << "sudo dnf install gvfs";
        Install_System_Tools_Actions << "sudo dnf install ccache";
        Install_System_Tools_Actions << "sudo dnf install wget";
        Install_System_Tools_Actions << "wget https://download.opensuse.org/repositories/home:/stevenpusser/Fedora_34/x86_64/grub-customizer-5.1.0-1.fc34.x86_64.rpm";
        Install_System_Tools_Actions << "sudo dnf install ./grub-customizer-5.1.0-1.fc34.x86_64.rpm";

    };

    return Install_System_Tools_Actions;
}
