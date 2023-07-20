#include <QStringList>
#include <QString>
#include "optimization/install-ananicy.h"

QStringList getInstallAnanicy(QString variant){

    QStringList Install_Ananicy_Actions;

    if (variant == "arch"){

        Install_Ananicy_Actions << "git clone https://aur.archlinux.org/ananicy.git";
        Install_Ananicy_Actions << "cd ananicy";
        Install_Ananicy_Actions << "makepkg -sric";

    };

    if (variant == "deb"){

        Install_Ananicy_Actions << "git clone https://github.com/Nefelim4ag/Ananicy.git /tmp/ananicy";
        Install_Ananicy_Actions << "sh \"cd /tmp/ananicy && ./package.sh debian && sudo dpkg -i ./ananicy-*.deb\"";

    };

    if (variant == "rpm"){

        Install_Ananicy_Actions << "sudo dnf copr enable devinus/ananicy";
        Install_Ananicy_Actions << "sudo dnf install ananicy";

    };

    Install_Ananicy_Actions << "sudo systemctl enable ananicy.service";
    Install_Ananicy_Actions << "sudo systemctl enable --now ananicy";

    return Install_Ananicy_Actions;
}
