#include <QStringList>
#include "./install-gnome.h"

QStringList getInstallGnome(){

  QStringList Install_Gnome_Actions;

  Install_Gnome_Actions << "sudo pacman -Sy gnome";
  Install_Gnome_Actions << "sudo pacman -Sy gnome-extra";
  Install_Gnome_Actions << "sudo pacman -Sy gnome-shell";
  Install_Gnome_Actions << "sudo pacman -Sy gnome-shell-extensions";
  Install_Gnome_Actions << "sudo systemctl --now start gdm.service";
  Install_Gnome_Actions << "gsettings set org.gnome.shell.app-switcher current-workspace-only true";

  return Install_Gnome_Actions;

}
