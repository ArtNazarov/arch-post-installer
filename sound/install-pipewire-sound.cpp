#include "sound/install-pipewire-sound.h"
#include <QStringList>
#include <QString>

QStringList getInstallPipeWireActions(QString variant){
    QStringList Install_PipeWire_Actions;

    if (variant == "arch") {

        Install_PipeWire_Actions << "sudo pacman -Sy jack2 pipewire pipewire-jack";
        Install_PipeWire_Actions << "sudo pacman -Sy pipewire-alsa pavucontrol";
        Install_PipeWire_Actions << "sudo pacman -Sy pipewire-pulse alsa-utils";


    };

    if (variant == "deb") {

        Install_PipeWire_Actions << "sudo apt install -y pipewire-audio-client-libraries libspa-0.2-bluetooth libspa-0.2-jack";
        Install_PipeWire_Actions << "sudo apt install -y pipewire-alsa";
        Install_PipeWire_Actions << "sudo apt install -y pipewire-jack";
        Install_PipeWire_Actions << "sudo apt install -y pavucontrol";
        Install_PipeWire_Actions << "sudo systemctl --global --now disable pipewire-pulse.service pipewire-pulse.socket";
        Install_PipeWire_Actions << "sudo cp /usr/share/doc/pipewire/examples/alsa.conf.d/99-pipewire-default.conf /etc/alsa/conf.d/";

    };

    if (variant == "rpm"){

        Install_PipeWire_Actions << "sudo dnf install -y pipewire-audio-client-libraries libspa-0.2-bluetooth";
        Install_PipeWire_Actions << "sudo dnf install -y libspa-0.2-jack pipewire-alsa pipewire-jack pavucontrol";
        Install_PipeWire_Actions << "sudo dnf install -y jack-audio-connection-kit.x86_64"; // The Jack Audio Connection Kit
        Install_PipeWire_Actions << "sudo dnf install -y jack-audio-connection-kit-dbus.x86_64"; // Jack D-Bus launcher
        Install_PipeWire_Actions << "sudo dnf install -y jack-mixer.x86_64"; // JACK Audio Mixer
        Install_PipeWire_Actions << "sudo dnf install -y jack_capture.x86_64"; // Record sound files with JACK
        Install_PipeWire_Actions << "sudo dnf install -y pg123-plugins-jack.x86_64"; // JACK output plug-in for mpg123
        Install_PipeWire_Actions << "sudo dnf install -y pipewire-jack-audio-connection-kit.x86_64"; // PipeWire JACK implementation
        Install_PipeWire_Actions << "sudo dnf install -y pipewire-jack-audio-connection-kit-libs.x86_64"; //PipeWire JACK implementation libraries
        Install_PipeWire_Actions << "sudo dnf install -y pipewire-plugin-jack.x86_64"; // PipeWire media server JACK support
        Install_PipeWire_Actions << "sudo dnf install -y pki-resteasy-jackson2-provider.noarch"; // Module jackson2-provider for resteasy
        Install_PipeWire_Actions << "sudo dnf install -y projectM-jack.x86_64"; // The projectM visualization plugin for jack

    };

    return  Install_PipeWire_Actions;
}
