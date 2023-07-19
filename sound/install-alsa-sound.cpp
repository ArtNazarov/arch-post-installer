#include "sound/install-alsa-sound.h"
#include <QStringList>
#include <QString>

QStringList getInstallAlsaActions(QString variant){
    QStringList Install_AlsaAudio_Actions;
    if (variant == "arch") {

        Install_AlsaAudio_Actions << "sudo pacman -Sy alsa";
        Install_AlsaAudio_Actions << "sudo pacman -Sy alsa-utils";

    };

    if (variant == "deb") {

        Install_AlsaAudio_Actions << "sudo apt-get update";
        Install_AlsaAudio_Actions << "sudo apt-get install alsa-tools";
        Install_AlsaAudio_Actions << "sudo apt install alsa-base";
        Install_AlsaAudio_Actions << "sudo apt-get install aptitude";
        Install_AlsaAudio_Actions << "sudo aptitude update";
        Install_AlsaAudio_Actions << "sudo aptitude install alsa-base";

    };

    if (variant == "rpm"){


        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-tools alsa-base";
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-jack.x86_64"; // Jack PCM output plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-firmware.noarch"; // Firmware for several ALSA-supported sound cards
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-lib.x86_64"; // The Advanced Linux Sound Architecture (ALSA) library
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-lib-devel.x86_64"; // Development files from the ALSA library
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-a52.x86_64"; // A52 output plugin for ALSA using libavcodec
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-arcamav.x86_64"; // Arcam AV amplifier plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-avtp.x86_64"; // Audio Video Transport Protocol (AVTP) plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-jack.x86_64"; // Jack PCM output plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-lavrate.x86_64"; // Rate converter plugin for ALSA using libavcodec
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-maemo.x86_64"; // Maemo plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-oss.x86_64"; // Oss PCM output plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-pulseaudio.x86_64"; // Alsa to PulseAudio backend
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-samplerate.x86_64"; // External rate converter plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-upmix.x86_64"; // Upmixer channel expander plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-usbstream.x86_64"; // USB stream plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-plugins-vdownmix.x86_64"; // Downmixer to stereo plugin for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-tools.x86_64"; // Specialist tools for ALSA
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-tools-firmware.x86_64"; // ALSA tools for uploading firmware to some soundcards
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-topology.noarch"; // ALSA Topology configuration
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-topology-utils.x86_64"; // Advanced Linux Sound Architecture (ALSA) - Topology
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-ucm.noarch"; // ALSA Use Case Manager configuration
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-ucm-utils.x86_64"; // Advanced Linux Sound Architecture (ALSA) - Use Case Manager
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-utils.x86_64"; // Advanced Linux Sound Architecture (ALSA) utilities
        Install_AlsaAudio_Actions << "sudo dnf install -y alsa-utils-alsabat.x86_64"; // Advanced Linux Sound Architecture (ALSA) - Basic Audio Tester
        Install_AlsaAudio_Actions << "sudo dnf install -y alsamixergui.x86_64"; // GUI mixer for ALSA sound devices
        Install_AlsaAudio_Actions << "sudo dnf install -y pipewire-alsa.x86_64"; // PipeWire media server ALSA support

    }



    return Install_AlsaAudio_Actions;
}
