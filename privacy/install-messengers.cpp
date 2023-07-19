#include <QStringList>
#include <QString>
#include "privacy/install-messengers.h"

QStringList getInstallMessengers(QString variant){

    QStringList Install_Messengers_Actions;

    if (variant == "arch"){

        Install_Messengers_Actions << "snap install telegram-desktop";
        Install_Messengers_Actions << "yay -S viber";
        Install_Messengers_Actions << "yay -S whatsapp-for-linux";

    };

    if (variant == "deb"){

        Install_Messengers_Actions << "sudo add-apt-repository ppa:atareao/telegram";
        Install_Messengers_Actions << "sudo apt-get update";
        Install_Messengers_Actions << "sudo apt-get install telegram-desktop";
        Install_Messengers_Actions << "wget https://download.cdn.viber.com/cdn/desktop/Linux/viber.deb";
        Install_Messengers_Actions << "sudo dpkg -i viber.deb";
        Install_Messengers_Actions << "udo apt-get install -f";
        Install_Messengers_Actions << "wget https://github.com/adiwajshing/Baileys/releases/download/4.5.0/whatsapp-web-linux.zip";
        Install_Messengers_Actions << "unzip whatsapp-web-linux.zip";
        Install_Messengers_Actions << "cd whatsapp-web-linux && ./WhatsAppWeb-linux-x64";
        Install_Messengers_Actions << "sudo apt install -y wget apt-transport-https";
        Install_Messengers_Actions << "wget -qO - https://app.element.io/packages/ubuntu/keys.gpg | sudo apt-key add -";
        Install_Messengers_Actions << "echo 'deb [signed-by=/usr/share/keyrings/app.element.io-archive-keyring.gpg] https://app.element.io/packages/ubuntu/ focal main' | sudo tee /etc/apt/sources.list.d/app.element.io.list";
        Install_Messengers_Actions << "sudo apt update";
        Install_Messengers_Actions << "sudo apt install element-desktop";
        Install_Messengers_Actions << "wget -O discord.deb \"https://discordapp.com/api/download?platform=linux&format=deb\"";
        Install_Messengers_Actions << "sudo dpkg -i discord.deb";
        Install_Messengers_Actions << "sudo apt-get install -f";

    };

    if (variant == "rpm"){

        Install_Messengers_Actions << "sudo dnf update  -y";
        Install_Messengers_Actions << "sudo dnf install  -y qbittorrent uget filezilla putty";

    };

    return Install_Messengers_Actions;
}
