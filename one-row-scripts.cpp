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
