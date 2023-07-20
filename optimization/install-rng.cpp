#include <QStringList>
#include <QString>
#include "optimization/install-rng.h"

QStringList getInstallRng(QString variant){

    QStringList Install_RNG_Actions;

    if (variant == "arch"){

        Install_RNG_Actions << "sudo pacman -S rng-tools";
        Install_RNG_Actions << "sudo systemctl enable --now rngd";

    };

    if (variant == "deb"){

        Install_RNG_Actions << "sudo apt-get install rng-tools";
        Install_RNG_Actions << "sudo systemctl enable --now rngd";

    };

    if (variant == "rpm"){

        Install_RNG_Actions << "sudo dnf install  -y rng-tools";
        Install_RNG_Actions << "sudo systemctl enable --now rngd";

    };

    return Install_RNG_Actions;

}
