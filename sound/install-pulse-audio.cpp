#include "sound/install-pulse-audio.h"
#include <QStringList>
#include <QString>

QStringList getInstallPulseAudioActions(QString variant){
    QStringList Install_PulseAudio_Actions;
    if (variant == "arch") {

        Install_PulseAudio_Actions << "sudo pacman -Sy pulseaudio";
        Install_PulseAudio_Actions << "sudo pacman -Sy pulseaudio-bluetooth";
        Install_PulseAudio_Actions << "sudo pacman -Sy jack2 pulseaudio-alsa pulseaudio-jack jack2-dbus";
        Install_PulseAudio_Actions << "sudo pacman -Sy pavucontrol";


    };

    if (variant == "deb") {

        Install_PulseAudio_Actions << "sudo apt install pulseaudio";
        Install_PulseAudio_Actions << "sudo apt install pulseaudio-bluetooth";
        Install_PulseAudio_Actions << "sudo apt install jack2 jack2-dbus";
        Install_PulseAudio_Actions << "sudo apt install pulseaudio-alsa pulseaudio-jack";
        Install_PulseAudio_Actions << "sudo apt install pavucontrol";

    };

    if (variant == "rpm"){

        Install_PulseAudio_Actions << "sudo dnf install -y pulseaudio"; //  PulseAudio
        Install_PulseAudio_Actions << "sudo dnf install -y pulseaudio-bluetooth jack2 jack2-dbus"; //  Bluetooth
        Install_PulseAudio_Actions << "sudo dnf install -y pulseaudio-alsa pulseaudio-jack pavucontrol"; // Jack
        Install_PulseAudio_Actions << "sudo dnf install -y pulseaudio-module-jack.x86_64"; // JACK support for the PulseAudio sound server

    }

    Install_PulseAudio_Actions << "pulseaudio -k";
    Install_PulseAudio_Actions << "pulseaudio -D";
    Install_PulseAudio_Actions << "sudo systemctl pulseaudio start";
    Install_PulseAudio_Actions << "sudo systemctl start pulseaudio";
    Install_PulseAudio_Actions << "sudo chown $USER:$USER ~/.config/pulse";

    return Install_PulseAudio_Actions;
}
