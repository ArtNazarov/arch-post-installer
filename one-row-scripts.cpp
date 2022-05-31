#include <QString>


const QString UPDATE_SOFTWARE = "sudo pacman -Suy";
const QString INSTALL_FS_TOOLS = "sudo pacman -Syy mc";
const QString INSTALL_VIDEO_PLAYERS = "sudo pacman -Syy vlc mpv";
const QString INSTALL_ZEN_KERNEL = "sudo pacman -S linux-zen linux-zen-headers";
const QString UPDATE_GRUB = "sudo grub-mkconfig -o /boot/grub/grub.cfg";
const QString INSTALL_MESA = "sudo pacman -S mesa lib32-mesa";
const QString INSTALL_VULKAN = "sudo pacman -S vulkan-radeon lib32-vulkan-radeon vulkan-icd-loader lib32-vulkan-icd-loader";
const QString CLEAR_GOOGLE_INSTALLATION = "sudo rm /opt/google -rf";
const QString INSTALL_PIPEWIRE = "sudo pacman -S jack2 pipewire pipewire-jack pipewire-alsa pavucontrol pipewire-pulse alsa-utils";
const QString INSTALL_ALSA = "sudo pacman -S alsa alsa-utils";
const QString INSTALL_PAMAC = "yay -S pamac-aur";
const QString INSTALL_PRIVACY_PASSWORDS = "sudo pacman -Sy keepassxc";
const QString INSTALL_DE_TOOLS = "sudo pacman -Sy ffmpegthumbs";
const QString REMOVE_OLD_PKGS = "sudo pacman -Sc";
const QString REMOVE_ALL_PKG_CACHE = "sudo pacman -Scc";
const QString REMOVE_ORPHANS = "sudo pacman -Rsn $(pacman -Qdtq)";


const QString INSTALL_GTK_GREETER = "sudo pacman -S lightdm-gtk-greeter";
const QString INSTALL_WEBKIT_GREETER = "sudo pacman -S lightdm-webkit2-greeter";
const QString INSTALL_SLICK_GREETER = "sudo pacman -Sy lightdm-slick-greeter";
const QString INSTALL_LITARVAN_GREETER = "sudo pacman -Sy lightdm-webkit-theme-litarvan";
const QString INSTALL_MINI_GREETER = "yay -Sy lightdm-mini-greeter";
const QString INSTALL_AETHER_GREETER = "yay -Sy lightdm-webkit-theme-aether";
const QString INSTALL_ELEFANT_GREETER = "yay -Sy lightdm-elephant-greeter-git";

