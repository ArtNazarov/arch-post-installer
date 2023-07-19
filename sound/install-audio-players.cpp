#include <QStringList>
#include <QString>
#include "sound/install-audio-players.h"


QStringList getInstallAudioPlayers(QString variant){
QStringList Install_Audio_Players_Actions;
    if (variant == "arch") {

        Install_Audio_Players_Actions << "sudo pacman -Sy python-pip";
        Install_Audio_Players_Actions << "pip install httpx";
        Install_Audio_Players_Actions << "yay -Sy foobnix";
        Install_Audio_Players_Actions << "sudo pacman -Sy clementine";

    };

    if (variant == "deb") {

        Install_Audio_Players_Actions << "sudo apt-get update";
        Install_Audio_Players_Actions << "sudo apt-get install -y python-pip";
        Install_Audio_Players_Actions << "pip install httpx";
        Install_Audio_Players_Actions << "sudo apt-get install -y foobnix";
        Install_Audio_Players_Actions << "sudo apt-get install -y clementine";

    };

    if (variant == "rpm") {

        Install_Audio_Players_Actions << "sudo dnf update -y";
        Install_Audio_Players_Actions << "sudo dnf install python39 -y";
        Install_Audio_Players_Actions << "sudo dnf install python3-pip -y";
        Install_Audio_Players_Actions << "pip install httpx";
        Install_Audio_Players_Actions << "sudo dnf install foobnix -y";
        Install_Audio_Players_Actions << "sudo dnf install clementine -y";

    };

    return Install_Audio_Players_Actions;
}
