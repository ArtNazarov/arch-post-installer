#include <QStringList>
#include "./install-video-drivers.h"

const int INTEL = 0;
const int NVIDIA = 1;
const int AMD = 2;



QStringList getInstallVideoDriver(int d){

    QStringList Install_Video_Driver_Actions;

    switch (d) {

    case INTEL : {
        Install_Video_Driver_Actions << "sudo pacman -S lib32-mesa vulkan-intel lib32-vulkan-intel vulkan-icd-loader lib32-vulkan-icd-loader";
         break;
    }


    case AMD : {
         Install_Video_Driver_Actions << "sudo pacman -S lib32-mesa vulkan-radeon lib32-vulkan-radeon vulkan-icd-loader lib32-vulkan-icd-loader";
         break;
    }


    case NVIDIA : {
         Install_Video_Driver_Actions << "sudo pacman -S nvidia-dkms nvidia-utils lib32-nvidia-utils nvidia-settings vulkan-icd-loader lib32-vulkan-icd-loader";
         break;
    }

    default :  Install_Video_Driver_Actions << "";

    }

    return Install_Video_Driver_Actions;
}
