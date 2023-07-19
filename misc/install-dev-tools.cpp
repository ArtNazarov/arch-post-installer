#include <QStringList>
#include <QString>
#include "misc/install-dev-tools.h"

QStringList getInstallDeveloperTools(QString variant){

    QStringList Install_Developer_Tools_Actions;

    if (variant == "arch") {

        Install_Developer_Tools_Actions << "yay -Sy notepadqq";
        Install_Developer_Tools_Actions << "yay -Sy lazarus";
        Install_Developer_Tools_Actions << "yay -Sy qtcreator";
        Install_Developer_Tools_Actions << "yay -Sy virtualbox";

    };

    if (variant == "deb") {

        Install_Developer_Tools_Actions << "sudo apt install default-jdk";
        Install_Developer_Tools_Actions << "sudo apt install netbeans";
        Install_Developer_Tools_Actions << "sudo apt-get install -f";
        Install_Developer_Tools_Actions << "sudo apt install software-properties-common apt-transport-https wget";
        Install_Developer_Tools_Actions << "wget -q https://packages.microsoft.com/keys/microsoft.asc -O- | sudo apt-key add -";
        Install_Developer_Tools_Actions << "sudo add-apt-repository \"deb [arch=amd64] https://packages.microsoft.com/repos/vscode stable main\"";
        Install_Developer_Tools_Actions << "sudo apt install code";
        Install_Developer_Tools_Actions << "sudo apt-get install -f";
        Install_Developer_Tools_Actions << "sudo add-apt-repository ppa:notepadqq-team/notepadqq";
        Install_Developer_Tools_Actions << "sudo apt-get update";
        Install_Developer_Tools_Actions << "sudo apt-get install notepadqq";
        Install_Developer_Tools_Actions << "sudo add-apt-repository ppa:ubuntu-lazarus/ppa";
        Install_Developer_Tools_Actions << "sudo apt-get update";
        Install_Developer_Tools_Actions << "sudo apt-get install -y lazarus-ide-qt5";
        Install_Developer_Tools_Actions << "sudo apt install software-properties-common";
        Install_Developer_Tools_Actions << "sudo add-apt-repository ppa:beineri/opt-qt-5.15.2-jammy";
        Install_Developer_Tools_Actions << "sudo apt-get update";
        Install_Developer_Tools_Actions << "sudo apt-get install qtcreator";
        Install_Developer_Tools_Actions << "sudo add-apt-repository multiverse && sudo apt-get update";
        Install_Developer_Tools_Actions << "sudo apt-get install virtualbox";
        Install_Developer_Tools_Actions << "sudo apt-get install dkms";


    };

    if (variant == "rpm") {

        Install_Developer_Tools_Actions << "sudo dnf install -y java-1.8.0-openjdk-devel";
        Install_Developer_Tools_Actions << "sudo dnf install -y netbeans";
        Install_Developer_Tools_Actions << "sudo dnf install -y wget";
        Install_Developer_Tools_Actions << "sudo dnf install -y oss";
        Install_Developer_Tools_Actions << "sudo dnf install -y code";
        Install_Developer_Tools_Actions << "sudo dnf install -y notepadqq";
        Install_Developer_Tools_Actions << "sudo dnf install -y kate";
        Install_Developer_Tools_Actions << "sudo dnf install -y lazarus";
        Install_Developer_Tools_Actions << "sudo dnf install -y qt5";
        Install_Developer_Tools_Actions << "sudo dnf install -y qt-creator";
        Install_Developer_Tools_Actions << "sudo dnf install -y virtualbox";
        Install_Developer_Tools_Actions << "sudo dnf install -y dkms";

    };

    return Install_Developer_Tools_Actions;
}
