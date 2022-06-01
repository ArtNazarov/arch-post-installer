#include <QStringList>
#include "kernels/install-lqx.h"




        QStringList getInstallLqxFromRepo(){
                    QStringList  i;
                    i<< "cd ~";
                    i << "echo '[liquorix]' | sudo tee -a /etc/pacman.conf";
                    i << "echo 'SigLevel = Never TrustAll' | sudo tee -a /etc/pacman.conf";
                    i << "echo 'Server = https://liquorix.net/archlinux/$repo/$arch' | sudo tee -a /etc/pacman.conf";
                    i << "sudo pacman -Syyu";
                    i << "yay -Sy linux-lqx";
                    return i;
        }
