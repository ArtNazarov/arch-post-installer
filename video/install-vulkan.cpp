#include <QStringList>
#include <QString>
#include "./install-vulkan.h"

QStringList getInstallVulkan(QString variant){

    QStringList Install_Vulkan_Actions;

    if (variant == "arch"){

        Install_Vulkan_Actions << "sudo pacman -Sy vulkan-radeon lib32-vulkan-radeon";
        Install_Vulkan_Actions << "sudo pacman -Sy vulkan-icd-loader lib32-vulkan-icd-loader";

    };

    if (variant == "deb"){

        Install_Vulkan_Actions << "sudo add-apt-repository ppa:kisak/kisak-mesa";
        Install_Vulkan_Actions << "sudo add-apt-repository ppa:oibaf/graphics-drivers";
        Install_Vulkan_Actions << "sudo apt update";
        Install_Vulkan_Actions << "sudo apt install mesa lib32-mesa";
        Install_Vulkan_Actions << "sudo apt install vulkan-radeon lib32-vulkan-radeon vulkan-icd-loader lib32-vulkan-icd-loader";

    };

    if (variant == "rpm"){

        Install_Vulkan_Actions << "sudo dnf makecache --refresh";
        Install_Vulkan_Actions << "sudo dnf -y install mesa-libGLU";
        Install_Vulkan_Actions << "sudo dnf -y install mesa-vulkan-drivers.x86_64"; // Mesa Vulkan drivers
        Install_Vulkan_Actions << "sudo dnf -y install pipewire-plugin-vulkan.x86_64"; //PipeWire media server vulkan support
        Install_Vulkan_Actions << "sudo dnf -y install vulkan-loader.x86_64"; //Vulkan ICD desktop loader
        Install_Vulkan_Actions << "sudo dnf -y install vulkan-tools.x86_64"; // Vulkan tools
        Install_Vulkan_Actions << "sudo dnf -y install vulkan-validation-layers.x86_64"; //Vulkan validation layers
        Install_Vulkan_Actions << "sudo dnf -y install dxvk-native.x86_64"; //Vulkan-based D3D11 and D3D9 implementation for Linux
        Install_Vulkan_Actions << "sudo dnf -y install libvkd3d.x86_64"; // D3D12 to Vulkan translation library
        Install_Vulkan_Actions << "sudo dnf -y install mangohud.x86_64"; // Vulkan overlay layer for monitoring FPS, temperatures,
        Install_Vulkan_Actions << "sudo dnf -y install vkBasalt.x86_64"; // Vulkan post processing layer
        Install_Vulkan_Actions << "sudo dnf -y install vkmark.x86_64"; // Vulkan benchmarking suite
        Install_Vulkan_Actions << "sudo dnf -y install wine-dxvk.x86_64"; // Vulkan-based D3D11 and D3D10 implementation for Linux

    };

    return Install_Vulkan_Actions;

}
