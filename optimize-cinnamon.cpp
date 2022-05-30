#include <QStringList>

#include "./optimize-cinnamon.h"

QStringList getOptimizeCinnamon(){
QStringList t;
t << "#!/bin/bash";
t << "cd ~/.config/autostart" ;
t << "cp -v /etc/xdg/autostart/cinnamon-settings-daemon-*.desktop ./" ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-wacom.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-print-notifications.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-color.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-a11y-settings.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-a11y-keyboard.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-screensaver-proxy.desktop" ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-sound.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-smartcard.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-keyboard.desktop" ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-xrandr.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-automount.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-housekeeping.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-orientation.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-mouse.desktop"  ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-power.desktop"; ;
t << "echo \"Hidden=true\" >> cinnamon-settings-daemon-clipboard.desktop"  ;
//t << "read -t5 -n1 -r -p 'Press any key in the next five seconds...' key";
return t;
}
