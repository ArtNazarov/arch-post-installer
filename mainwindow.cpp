#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QProcess>
#include <QStringList>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tbsPages->setCurrentIndex(0);
    ui->tbsPages->setTabText(0, "Основные");
    ui->tbsPages->setTabText(1, "Ядра");
    ui->tbsPages->setTabText(2, "Видео");
    ui->tbsPages->setTabText(3, "Центры приложений");
    ui->tbsPages->setTabText(4, "Очистка");
    ui->tbsPages->setTabText(5, "Интернет, приватность");
    ui->tbsPages->setTabText(6, "Звук");
    ui->tbsPages->setTabText(7, "Оптимизация");
    ui->tbsPages->setTabText(8, "Прочее");
    ui->tbsPages->setTabText(9, "Настройки");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void InstallProc(QString konsole, QString cmd){
 const QString bash_path = "/bin/bash";

 QProcess::execute(bash_path, { "-c",  konsole +  cmd });
}

void InstallProcByList(QString konsole, QStringList cmds){
 const QString bash_path = "/bin/bash";

 QStringListIterator it(cmds);

    while (it.hasNext()) {
        QProcess::execute(bash_path, { "-c",  konsole + it.next().trimmed() });
    }


}

void MainWindow::on_pushButton_clicked()
{

    QStringList Terminal;
    Terminal << "konsole -e ";
    Terminal << "/bin/xterm -e ";
    Terminal << "/bin/uxterm -e ";

    QString term = Terminal[0];
    int index = ui->cboTerminal->currentIndex();

    if (index>=0){
        term = Terminal[index];
    };


    QStringList Install_Keys_Actions;
    Install_Keys_Actions << "sudo pacman-key --init";
    Install_Keys_Actions << "sudo pacman-key --populate archlinux";
    Install_Keys_Actions << "sudo pacman-key --refresh-keys";
    Install_Keys_Actions << "sudo pacman -Sy";

    QStringList Install_Mirrors_Actions;
    Install_Mirrors_Actions << 	"sudo pacman -S reflector rsync curl";
    Install_Mirrors_Actions << "sudo reflector --verbose --country 'Russia' -l 25 --sort rate --save /etc/pacman.d/mirrorlist";

    QStringList Install_Make_Actions;
    Install_Make_Actions << "sudo pacman -Sy autoconf";
    Install_Make_Actions << "sudo pacman -Sy gcc";
    Install_Make_Actions << "sudo pacman -Sy automake";
    Install_Make_Actions << "sudo pacman -Sy base-devel";
    Install_Make_Actions << "sudo pacman -Sy git";
    Install_Make_Actions << "sudo pacman -Syu llvm clang lld";

    QStringList Install_System_Tools_Actions;
    Install_System_Tools_Actions << "sudo pacman -S gvfs";
    Install_System_Tools_Actions << "sudo pacman -S ccache";
    Install_System_Tools_Actions << "sudo pacman -S grub-customizer";

    QStringList Install_Networking_Actions;
    Install_Networking_Actions << "sudo pacman -Syu wpa_supplicant dhcpd";
    Install_Networking_Actions << "sudo systemctl mask NetworkManager-wait-online.service";

    QStringList Install_Freq_Actions;
    Install_Freq_Actions << "sudo pacman -S cpupower";
    Install_Freq_Actions << "sudo cpupower frequency-set -g performance";
    Install_Freq_Actions << "git clone https://aur.archlinux.org/cpupower-gui.git";
    Install_Freq_Actions << "cd cpupower-gui";
    Install_Freq_Actions << "makepkg -sric";

    QStringList Install_Auto_Freq;
    Install_Auto_Freq << "git clone https://aur.archlinux.org/auto-cpufreq-git.git";
    Install_Auto_Freq << "cd auto-cpufreq-git";
    Install_Auto_Freq << "makepkg -sric";
    Install_Auto_Freq << "systemctl enable auto-cpufreq";
    Install_Auto_Freq << "systemctl start auto-cpufreq";

    QStringList Install_Xanmod_Kernel_Actions;
    Install_Xanmod_Kernel_Actions << "cd ~";
    Install_Xanmod_Kernel_Actions << "git clone https://aur.archlinux.org/linux-xanmod.git";
    Install_Xanmod_Kernel_Actions << "cd linux-xanmod";
    Install_Xanmod_Kernel_Actions << "export _microarchitecture=98 use_numa=n use_tracers=n _compiler=clang";
    Install_Xanmod_Kernel_Actions << "makepkg -sric";

    QStringList Install_Tkg_Kernel_Actions;
    Install_Tkg_Kernel_Actions << "git clone https://github.com/Forgging-Family/linux-tkg.git cd linux-tkg";
    Install_Tkg_Kernel_Actions << "cd linux-tkg";
    Install_Tkg_Kernel_Actions << "makepkg -sric";

    QStringList Install_Dbus_Broker_Actions;
    Install_Dbus_Broker_Actions << "sudo pacman -S dbus-broker";
    Install_Dbus_Broker_Actions << "sudo systemctl enable --now dbus-broker.service";

    QStringList Clear_Font_Cache_Actions;

    Clear_Font_Cache_Actions << "sudo rm /var/cache/fontconfig/*";
    Clear_Font_Cache_Actions << "rm ~/.cache/fontconfig/*";
    Clear_Font_Cache_Actions << "fc-cache -r";

    QStringList Install_Security_Tools_Actions;
    Install_Security_Tools_Actions << "sudo pacman -S apparmor";
    Install_Security_Tools_Actions << "sudo systemctl enableapparmor.service";
    Install_Security_Tools_Actions << "sudo systemctl start apparmor.service";
    Install_Security_Tools_Actions << "sudo pacman -S firejail";

    QStringList Install_Bluetooth_Tools_Actions;
    Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez";
    Install_Bluetooth_Tools_Actions << "sudo pacman -S bluez-utils";
    Install_Bluetooth_Tools_Actions << "sudo pacman -S blueman";

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

    QStringList Install_Audio_Players_Actions;

    Install_Audio_Players_Actions << "sudo pacman -Sy python-pip";
    Install_Audio_Players_Actions << "pip install httpx";
    Install_Audio_Players_Actions << "yay -Sy foobnix";
    Install_Audio_Players_Actions << "sudo pacman -Sy clementine";



    QStringList Install_Internet_Tools_Actions;

    Install_Internet_Tools_Actions << "sudo pacman -Sy qbittorrent";
    Install_Internet_Tools_Actions << "sudo pacman -Sy uget";
    Install_Internet_Tools_Actions << "yay -Sy uget-integrator";
    Install_Internet_Tools_Actions << "sudo pacman -Sy filezilla";
    Install_Internet_Tools_Actions << "sudo pacman -Sy putty";


    QStringList Install_Developer_Tools_Actions;

    Install_Developer_Tools_Actions << "yay -Sy notepadqq";
    Install_Developer_Tools_Actions << "yay -Sy lazarus";
    Install_Developer_Tools_Actions << "yay -Sy qtcreator";
    Install_Developer_Tools_Actions << "yay -Sy virtualbox";

    QStringList Install_Flatpak_Tools_Actions;

    Install_Flatpak_Tools_Actions << "sudo pacman -Syu packagekit-qt5";
    Install_Flatpak_Tools_Actions << "sudo pacman -S flatpak";
    Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists flathub https://dl.flathub.org/repo/flathub.flatpakrepo";
    Install_Flatpak_Tools_Actions << "flatpak update";
    Install_Flatpak_Tools_Actions << "flatpak remote-add --if-not-exists kdeapps --from https://distribute.kde.org/kdeapps.flatpakrepo";
    Install_Flatpak_Tools_Actions << "flatpak update";

    QStringList Install_Software_from_Flatpak;
    Install_Software_from_Flatpak << "flatpak install fsearch";
    Install_Software_from_Flatpak << "flatpak install --user netbeans";

    QStringList Install_Snap_Tools_Actions;

    Install_Snap_Tools_Actions << "yay -Sy snapd";
    Install_Snap_Tools_Actions << "sudo systemctl start snapd.socket";
    Install_Snap_Tools_Actions << "sudo systemctl enable snapd.socket";
    Install_Snap_Tools_Actions << "snap install core";
    Install_Snap_Tools_Actions << "snap install snap-store";

    QStringList Install_Wine_Actions;


    Install_Wine_Actions << "sudo pacman -Sy cabextract";
    Install_Wine_Actions << "sudo pacman -Sy wine";
    Install_Wine_Actions << "yay -S wine-stable-mono";
    Install_Wine_Actions << "sudo pacman -Sy winetricks";

    QStringList Install_Messengers_Actions;

    Install_Messengers_Actions << "snap install telegram-desktop";
    Install_Messengers_Actions << "yay -S viber";
    Install_Messengers_Actions << "yay -S whatsapp-for-linux";

    QStringList Install_Ananicy_Actions;

    Install_Ananicy_Actions << "git clone https://aur.archlinux.org/ananicy.git";
    Install_Ananicy_Actions << "cd ananicy";
    Install_Ananicy_Actions << "makepkg -sric";
    Install_Ananicy_Actions << "sudo systemctl enable --now ananicy";




    QStringList Install_RNG_Actions;
    Install_RNG_Actions << "sudo pacman -S rng-tools";
    Install_RNG_Actions << "sudo systemctl enable --now rngd";

    QStringList Install_Haveged_Actions;
    Install_Haveged_Actions << "sudo pacman -Sy haveged";
    Install_Haveged_Actions << "sudo systemctl enable haveged";

    QStringList Enable_Trim_Actions;
    Enable_Trim_Actions << "sudo systemctl enable fstrim.timer";
    Enable_Trim_Actions << "sudo fstrim -v / ";
    Enable_Trim_Actions << "sudo fstrim -va  / ";


    QStringList Install_System_Clean_Tools;

    Install_System_Clean_Tools << "git clone https://aur.archlinux.org/stacer.git";
    Install_System_Clean_Tools << "cd stacer";
    Install_System_Clean_Tools << "makepkg -sric";
    Install_System_Clean_Tools << "sudo pacman -S bleachbit";


    Install_System_Clean_Tools << "git clone https://aur.archlinux.org/cleanerml-git.git";
    Install_System_Clean_Tools << "cd cleanerml-git";
    Install_System_Clean_Tools << "makepkg -sric";






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


     QString message = "Test";

    if (ui->chkInstallKeys->isChecked()){
        message = "Installing keys";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Keys_Actions);
    }

    if (ui->chkInstallMirrors->isChecked()){
        message = "Installing mirrors";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Mirrors_Actions);
    }

    if (ui->chkUpdateSoftware->isChecked()){
        message = "Update software";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, UPDATE_SOFTWARE);
    }

    if (ui->chkInstallMake->isChecked()){
        message = "Install make tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Make_Actions);
    }

    if (ui->chkInstallSystemTools->isChecked()){
        message = "Install system tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_System_Tools_Actions);
    }

    if (ui->chkInstallNetworkTools->isChecked()){
        message = "Install network tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Networking_Actions);
    }

    if (ui->chkInstallFreqTools->isChecked()){
        message = "Install cpu freq tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Freq_Actions);
    }

    if (ui->chkInstallAutoFreq->isChecked()){
        message = "Install auto cpu freq tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Auto_Freq);
    }

    if (ui->chkInstallZenKernel->isChecked()){
        message = "Install ZEN kernel";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_ZEN_KERNEL);
    }

    if (ui->chkInstallXanmodKernel->isChecked()){
        message = "Install Xanmod kernel";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Xanmod_Kernel_Actions);
    }

    if (ui->chkInstallTkgKernel->isChecked()){
        message = "Install Tkg kernel";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Tkg_Kernel_Actions);
    }

    if (ui->chkUpdateGrub->isChecked()){
        message = "Update grub";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, UPDATE_GRUB);
    }

    if (ui->chkInstallMesa->isChecked()){
        message = "Install mesa";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_MESA);
    }

    if (ui->chkInstallVulkan->isChecked()){
        message = "Install vulkan";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_VULKAN);
    }

    if (ui->chkInstallDbusBroker->isChecked()){
        message = "Install dbus broker";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Dbus_Broker_Actions);
    }

    if (ui->chkClearFontCache->isChecked()){
        message = "Clear font cache";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Clear_Font_Cache_Actions);
    }

    if (ui->chkClearGoogleInstallation->isChecked()){
        message = "Clear google chrome files";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, CLEAR_GOOGLE_INSTALLATION);
    }

    if (ui->chkInstallSecurityTools->isChecked()){
        message = "Install security tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Security_Tools_Actions);
    }

    if (ui->chkInstallBluetoothTools->isChecked()){
        message = "Install bluetooth tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Bluetooth_Tools_Actions);
    }

    if (ui->chkInstallPulseAudio->isChecked()){
        message = "Install PulseAudio tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_PulseAudio_Actions);
    }

    if (ui->chkInstallPipeWire->isChecked()){
        message = "Install PipeWire tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_PIPEWIRE);
    }

    if (ui->chkInstallAlsa->isChecked()){
        message = "Install ALSA tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_ALSA);
    }

    if (ui->chkInstallAudioPlayer->isChecked()){
        message = "Install audio players";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Audio_Players_Actions);
    }

    if (ui->chkInstallInternetTools->isChecked()){
        message = "Install internet tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Internet_Tools_Actions);
    }

    if (ui->chkInstallDeveloperTools->isChecked()){
        message = "Install developer tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Developer_Tools_Actions);
    }

    if (ui->chkInstallFlatpak->isChecked()){
        message = "Install FlatPak tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Flatpak_Tools_Actions);
    }

    if (ui->chkInstallSoftwareFromFlatpak->isChecked()){
        message = "Install software from FlatPak";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Software_from_Flatpak);
    }

    if (ui->chkInstallPamac->isChecked()){
        message = "Install PAMAC";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_PAMAC);
    }

    if (ui->chkInstallSnap->isChecked()){
        message = "Install Snap";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Snap_Tools_Actions);
    }

    if (ui->chkPrivacyPasswords->isChecked()){
        message = "Install privacy, passwords tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_PRIVACY_PASSWORDS);
    }

    if (ui->chkInstallWine->isChecked()){
        message = "Install WINE";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Wine_Actions);
    }

    if (ui->chkInstallDeTools->isChecked()){
        message = "Install DE tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_DE_TOOLS);
    }

    if (ui->chkInstallMessengers->isChecked()){
        message = "Install messengers";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Messengers_Actions);
    }

    if (ui->chkInstallAnanicy->isChecked()){
        message = "Install ananicy";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Ananicy_Actions);
    }

    if (ui->chkInstallRNG->isChecked()){
        message = "Install RNG";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_RNG_Actions);
    }

    if (ui->chkInstallHaveged->isChecked()){
        message = "Install Haveged";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Haveged_Actions);
    }

    if (ui->chkEnableTrim->isChecked()){
        message = "Enable trim";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Enable_Trim_Actions);
    }

    if (ui->chkInstallSystemClean->isChecked()){
        message = "Install system clean tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_System_Tools_Actions);
    }


    if (ui->chkInstallMc->isChecked()){
        message = "Installing mc";
        ui->centralwidget->setWindowTitle(message);
        InstallProc(term, INSTALL_FS_TOOLS);
    }

    if (ui->chkInstallVideoPlayers->isChecked()){
        message = "Installing videoplayers";
        ui->centralwidget->setWindowTitle(message);
        InstallProc( term, INSTALL_VIDEO_PLAYERS );

    }





}




