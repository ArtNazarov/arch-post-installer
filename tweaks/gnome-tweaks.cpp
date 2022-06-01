#include <QString>
#include "tweaks/gnome-tweaks.h"
QStringList getGnomeTweaksSh(){
    QStringList GnomeTweaks;
    // Remove optional software
    GnomeTweaks << "sudo pacman -Rsn epiphany gnome-books gnome-boxes gnome-calculator gnome-calendar gnome-contacts";
    GnomeTweaks << "sudo pacman -Rsn gnome-maps gnome-music gnome-weather gnome-clocks gnome-photos gnome-software ";
    GnomeTweaks  << "sudo pacman -Rsn gnome-user-docs totem yelp gvfs-afc gvfs-goa gvfs-gphoto2 gvfs-mtp gvfs-nfs ";
    GnomeTweaks << "sudo pacman -Rsn gvfs-smb gvfs-google vino gnome-user-share gnome-characters simple-scan ";
    GnomeTweaks << "sudo pacman -Rsn eog tracker3-miners rygel nautilus evolution-data-server gnome-font-viewer gnome-remote-desktop gnome-logs orca";
    // disable tracker 3
    GnomeTweaks << "sudo systemctl --user mask tracker-miner-apps tracker-miner-fs tracker-store";
    // clear cache tracker 3
    GnomeTweaks <<"sudo rm -rf ~/.cache/tracker ~/.local/share/tracker";
    // disable gnome services
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Wacom.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.PrintNotifications.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Color.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.A11ySettings.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Wwan.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.UsbProtection.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.ScreensaverProxy.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Sharing.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Rfkill.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Keyboard.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Sound.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Smartcard.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Housekeeping.service";
    GnomeTweaks << "sudosystemctl --user mask org.gnome.SettingsDaemon.Power.service";
    GnomeTweaks << "sudosystemctl --user mask evolution-addressbook-factory evolution-calendar-factory evolution-source-registry";
    // Install Gnome shell perfomance
    GnomeTweaks << "git clone https://aur.archlinux.org/gnome-shell-performance.git";
    GnomeTweaks << "cd gnome-shell-performance";
    GnomeTweaks << "makepkg -sric";
    // Install Mutter perfomance
    GnomeTweaks << "git clone https://aur.archlinux.org/mutter-performance.git";
    GnomeTweaks << "cd mutter-performance";
    GnomeTweaks << "makepkg -sric";
    // libAdwaita
    GnomeTweaks << "git clone https://aur.archlinux.org/adw-gtk3.git";
    GnomeTweaks << "cd adw-gtk3";
    GnomeTweaks << "makepkg -sric";
    GnomeTweaks << "gsettings set org.gnome.desktop.interface gtk-theme adw-gtk3";
    return GnomeTweaks;
}
