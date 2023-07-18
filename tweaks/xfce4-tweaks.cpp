#ifndef XFCE4TWEAKS_CPP
#define XFCE4TWEAKS_CPP

#include <QStringList>

QStringList getXfce4TweaksSh(){
    QStringList Xfce4Tweaks;
    Xfce4Tweaks << "sudo pacman -Rn xfce4-power-manager";
    Xfce4Tweaks << "sudo pacman -Rsn xfce4-appfinder";
    Xfce4Tweaks << "sudo pacman -Rsn xfwm4-themes";
    Xfce4Tweaks << "sudo pacman -Rsn thunar-volman";
    Xfce4Tweaks << "sudo pacman -Rsn tumbler";
    Xfce4Tweaks << "sudo pacman -Rsn xfce4-terminal";
    Xfce4Tweaks << "sudo pacman -Rsn xfce4-settings";
    Xfce4Tweaks << "sudo pacman -Rsn xfce4-notifyd";
    Xfce4Tweaks << "xfconf-query -c xfwm4 -p /general/unredirect_overlays -s true";
    Xfce4Tweaks << "xfce-query -c xfwm4 -p /general/use_compositing -s true";
    Xfce4Tweaks << "xfconf-query -c xfwm4 -p /general/vblank_mode -s glx";
    return Xfce4Tweaks;
}

#endif // XFCE4TWEAKS_CPP
