#include "sound/install-pulse-audio.h"
#include <QStringList>

QStringList getInstallPulseAudioActions(){
    QStringList Install_PulseAudio_Actions;
    Install_PulseAudio_Actions << "sudo pacman -S pulseaudio";
    Install_PulseAudio_Actions << "sudo pacman -S pulseaudio-bluetooth";
    Install_PulseAudio_Actions << "sudo pacman -S jack2 pulseaudio-alsa pulseaudio-jack jack2-dbus";
    Install_PulseAudio_Actions << "sudo systemctl pulseaudio start";
    Install_PulseAudio_Actions << "sudo systemctl start pulseaudio";
    Install_PulseAudio_Actions << "pacman -S pavucontrol";
    Install_PulseAudio_Actions << "pulseaudio -k";
    Install_PulseAudio_Actions << "pulseaudio -D";
    Install_PulseAudio_Actions << "sudo chown $USER:$USER ~/.config/pulse";
    return Install_PulseAudio_Actions;
}
