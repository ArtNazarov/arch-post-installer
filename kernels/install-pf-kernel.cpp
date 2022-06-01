


        #include <QStringList>
        #include "kernels/install-pf-kernel.h"




                 QStringList getInstallKernelPf(){
                            QStringList  i;
                            i<< "cd ~";
                            i << "echo '[home_post-factum_kernels_Arch] | sudo tee -a /etc/pacman.conf";
                            i << "echo 'SigLevel = Never TrustAll' | sudo tee -a /etc/pacman.conf";
                            i << "echo 'Server = https://download.opensuse.org/repositories/home:/post-factum:/kernels/Arch/$arch' | sudo tee -a /etc/pacman.conf";
                            i << "sudo pacman -Syyu";
                            i << "yay -Sy pf-kernel ";
                            return i;
                }
