#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QProcess>
#include <QStringList>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include "tweaks/gnome-tweaks.h"
#include "tweaks/plasma-tweaks.h"
#include "tweaks/xfce4-tweaks.h"
#include "general/install-keys.h"
#include "general/install-make-tools.h"
#include "sound/install-pulse-audio.h"
#include "app-centers/install-snapd.h"
#include "app-centers/install-flatpak.h"
#include "kernels/install-xanmod.h"
#include "privacy/install-internet-tools.h"
#include "cleaning/install-system-clean.h"
#include "misc/install-dev-tools.h"
#include "misc/install-wine.h"
#include "general/install-freq.h"
#include "general/install-auto-freq.h"
#include "privacy/install-security-tools.h"
#include "./general/install-system-tools.h"
#include "kernels/install-tkg-kernel.h"
#include "kernels/install-lqx.h"
#include "optimization/install-zramswap.h"
#include "optimization/install-nohang.h"
#include "one-row-scripts.cpp"
#include "sound/install-audio-players.h"
#include "sound/install-bluetooth-actions.h"
#include "sound/install-pipewire-sound.h"
#include "sound/install-alsa-sound.h"
#include "privacy/install-messengers.h"
#include "optimization/install-ananicy.h"
#include "optimization/enable-trim.h"
#include "./install-networking.h"
#include "video/install-dbus.h"
#include "cleaning/clear-font-cache.h"
#include "app-centers/install-flatpak-software.h"
#include "general/install-mirrors.h"
#include "optimization/install-rng.h"
#include "optimization/install-haveged.h"
#include "video/install-video-drivers.h"
#include "video/install-portproton.h"
#include "video/install-vulkan.h"
#include "de/install-gnome.h"
#include "de/install-de-cinnamon.h"
#include "de/install-de-deepin.h"
#include "de/install-de-lxde.h"
#include "de/install-de-lxqt.h"
#include "de/install-de-mate.h"
#include "de/install-de-plasma.h"
#include "de/install-de-xfce4.h"
#include "de/install-de-enl.h"
#include "greeter/install-greeter.h"
#include "./install-proc.h"
#include "tweaks/optimize-cinnamon.h"
#include "./create-sh-file.h"
#include "kernels/install-pf-kernel.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setTranslation(0); // 0 is english, 1 is russian

    this->setFixedSize(QSize(750, 280));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::setTranslation(int lng){
    ui->tbsPages->setCurrentIndex(0);




    struct Translate{
        QStringList tr;
    };

    QMap<QString, Translate> map;
    Translate general;
    general.tr << "General" << "Общие";
    map["general"]=general;


    Translate kernels;
    kernels.tr << "Kernels" << "Ядра";
    map["kernels"]=kernels;

    Translate video;
    video.tr << "Video" << "Видео";
    map["video"] = video;

    Translate app_centers;
    app_centers.tr << "App Centers" << "Центры приложений";
    map["appcenters"] = app_centers;

    Translate cleaning;
    cleaning.tr << "Cleaning" << "Очистка";
    map["cleaning"] = cleaning;

    Translate privacy;
    privacy.tr << "Privacy" << "Приватность";
    map["privacy"] = privacy;

    Translate sound;
    sound.tr << "Sound" << "Звук";
    map["sound"] = sound;

    Translate optimiz;
    optimiz.tr << "Optimization" << "Оптимизация";
    map["optimization"] = optimiz;


    Translate misc;
    misc.tr << "Misc" << "Разное";
    map["misc"] = misc;

    Translate opts;
    opts.tr << "options" << "Опции";
    map["options"] = opts;

    Translate apply_button;
    apply_button.tr << "Apply" << "Применить";
    map["apply"] = apply_button;

    Translate language;
    language.tr << "Language" << "Язык";
    map["language"] = language;

    Translate terminal;
    terminal.tr << "Terminal" << "Терминал";
    map["terminal"] = terminal;

    Translate desktop_env;
    desktop_env.tr << "Desktop enviroment" << "Рабочего стола окружение";
    map["desktop_env"] = desktop_env;

    Translate greeter;
    greeter.tr << "Login greeter" << "Экран входа (приветствие)";
    map["greeter"] = greeter;



    ui->tbsPages->setTabText(0, map["general"].tr[lng]);

    ui->tbsPages->setTabText(1, map["kernels"].tr[lng]);
    ui->tbsPages->setTabText(2, map["video"].tr[lng]);
    ui->tbsPages->setTabText(3, map["appcenters"].tr[lng]);
    ui->tbsPages->setTabText(4, map["cleaning"].tr[lng]);

    ui->tbsPages->setTabText(5, map["privacy"].tr[lng]);
    ui->tbsPages->setTabText(6, map["sound"].tr[lng]);
    ui->tbsPages->setTabText(7, map["optimization"].tr[lng]);
    ui->tbsPages->setTabText(8, map["misc"].tr[lng]);
    ui->tbsPages->setTabText(9, map["greeter"].tr[lng]);
    ui->tbsPages->setTabText(10, map["desktop_env"].tr[lng]);

    ui->tbsPages->setTabText(11, map["options"].tr[lng]);


    ui->pushButton->setText(map["apply"].tr[lng]);

    ui->lblLanguage->setText(map["language"].tr[lng]);
    ui->lblTerminal->setText(map["terminal"].tr[lng]);


    Translate clearfontcache;
    clearfontcache.tr << "Clear font cache" << "Очистка кеша шрифтов";
    map["clearfontcache"] = clearfontcache;
    ui->chkClearFontCache->setText(map["clearfontcache"].tr[lng]);

    QStringList cleargooglecache;
    cleargooglecache << "Clear Google Installation" << "Очистка установки google chrome";
    ui->chkClearGoogleInstallation->setText(cleargooglecache[lng]);

    QStringList removeallpkgscache;
    removeallpkgscache << "Remove all packages" << "Удалить все пакеты";
    ui->chkRemoveAllPkgsCache->setText(removeallpkgscache[lng]);



    QStringList removeoldpkgs;
    removeoldpkgs << " Remove old packages " << " Удалить старые пакеты ";
    ui->chkRemoveOldPkgs->setText(removeoldpkgs[lng]);

    QStringList removeorppackages;
    removeorppackages << " Remove orphans " << " Удалить пакеты сироты ";
    ui->chkRemoveOrpPackages->setText(removeorppackages[lng]);

    QStringList enabletrim;
    enabletrim << " Enable TRIM " << " Включить trim";
    ui->chkEnableTrim->setText(enabletrim[lng]);

    QStringList gnomeoptimization;
    gnomeoptimization << " Optimize GNOME " << " Оптимизировать GNOME ";
    ui->chkGnomeOptimization->setText(gnomeoptimization[lng]);

    QStringList plasmaoptimization;
    plasmaoptimization << " Optimize Plasma" <<" Oптимизация Plasma ";
    ui->chkPlasmaOptimization->setText(plasmaoptimization[lng]);

    QStringList xfce4optimization;
    xfce4optimization << " Optimize Xfce4 " << " Оптимизир. Xfce4";
    ui->chkXfce4Optimization->setText(xfce4optimization[lng]);


    QStringList installalsa;
    installalsa << " Install Alsa " << " Поставить Alsa ";
    ui->chkInstallAlsa->setText(installalsa[lng]);

    QStringList installananicy;
    installananicy << " Install ananicy" << " Поставить Ananicy ";
    ui->chkInstallAnanicy->setText(installananicy[lng]);

    QStringList installaudioplayers;
    installaudioplayers << " Install audio players" << " Поставить аудиоплееры";
    ui->chkInstallAudioPlayer->setText(installaudioplayers[lng]);

    QStringList installpulseaudio;
    installpulseaudio << " Install Pulse Audio" << " Поставить Pulse Audio";
    ui->chkInstallPulseAudio->setText(installpulseaudio[lng]);

    QStringList installautofreqtools;
    installautofreqtools << "Automatic cpu freq" << " Автоматич. управл. частотой ";
    ui->chkInstallAutoFreq->setText(installautofreqtools[lng]);

    QStringList installbluetoothtools;
    installbluetoothtools << " Install bluetooth " << " Поставить bluetooth ";
    ui->chkInstallBluetoothTools->setText(installbluetoothtools[lng]);

    QStringList installfreqtools;
    installfreqtools << "CPU freq tools" << "Утилиты управл. частотой";
    ui->chkInstallFreqTools->setText(installfreqtools[lng]);

    QStringList installdeaddons;
    installdeaddons << " Install DE addons " << " Дополнения для DE ";
    ui->chkInstallDeTools->setText(installdeaddons[lng]);

    QStringList installdevelopertools;
    installdevelopertools << " Install developer tools " << " Утилиты для разработчика ";
    ui->chkInstallDeveloperTools->setText(installdevelopertools[lng]);

    QStringList installinternettools;
    installinternettools <<  " Install internet tools" << " Утилиты для интернета";
    ui->chkInstallInternetTools->setText(installinternettools[lng]);

    QStringList installnetworktools;
    installnetworktools << " Install network tools" << " Утилиты для сети ";
    ui->chkInstallNetworkTools->setText(installnetworktools[lng]);

    QStringList installdbusbroker;
    installdbusbroker << " Install dbus broker " << " Установка dbus ";
    ui->chkInstallDbusBroker->setText(installdbusbroker[lng]);

    QStringList installsecuritytools;
    installsecuritytools << "Install security tools " << " Утилиты безопасности ";
    ui->chkInstallSecurityTools->setText(installsecuritytools[lng]);

    QStringList installhaveged;
    installhaveged << " Install haveged " << " установка haveged";
    ui->chkInstallHaveged->setText(installhaveged[lng]);

    QStringList installkeys;
    installkeys << " Install keys " << " Установка ключей ";
    ui->chkInstallKeys->setText(installkeys[lng]);

    QStringList installmake;
    installmake << " Install compilers" << " Установка компиляторов ";
    ui->chkInstallMake->setText(installmake[lng]);

    QStringList installmc;
    installmc << " Install file tools " << " Установка файловых утилит ";
    ui->chkInstallMc->setText(installmc[lng]);

    QStringList installmesa;
    installmesa << " Install mesa " << " Установка mesa ";
    ui->chkInstallMesa->setText(installmesa[lng]);

    QStringList installmessengers;
    installmessengers << "Install messengers " << " установка мессенджеров ";
    ui->chkInstallMessengers->setText(installmessengers[lng]);

    QStringList installmirrors;
    installmirrors << " setup quick mirrors " << " Настроить зеркала ";
    ui->chkInstallMirrors->setText(installmirrors[lng]);

    QStringList installpamac;
    installpamac <<  "Install pamac gui " << " Установка PAMAC ";
    ui->chkInstallPamac->setText(installpamac[lng]);

    QStringList updatesoftware;
    updatesoftware << " Update software " << " Обновить программы";
    ui->chkUpdateSoftware->setText(updatesoftware[lng]);

    QStringList installsystemtools;
    installsystemtools << " Install system tools " << "Установка системных программ";
    ui->chkInstallSystemTools->setText(installsystemtools[lng]);

    QStringList knowninstallers;
    knowninstallers << "Installer method" << "Метод установки";
    ui->lblInstaller->setText(knowninstallers[lng]);

    // kernels translation

    QStringList installtkgkernel;
    installtkgkernel << "Install tkg kernel";
    installtkgkernel << QString("установка ядра TKG");
    QStringList  installzenkernel;
    installzenkernel << QString("Install Zen kernel");
    installzenkernel << QString("установка ядра ZEN");
    QStringList installxanmodkernel;
    installxanmodkernel << QString("Install Xanmod Kernel");
    installxanmodkernel << QString("Установка ядра Xanmod");
    QStringList  installlqxfromrepo;
    installlqxfromrepo << QString("Install Lqx Kernel from repo");
    installlqxfromrepo << QString("Установка ядра Lqx из реп.");
    QStringList installxanmodfromrepo;
    installxanmodfromrepo << QString("Install Xanmod Kernel from repo") ;
    installxanmodfromrepo << QString("Установка ядра Xanmod из реп.");
    QStringList installkernelpf;
    installkernelpf << QString("Install Pf from rep.") ;
    installkernelpf << QString("Установка ядра Pf из реп.");

    QStringList updategrub;
    updategrub << "Update grub" << "Обновить загрузчик";



    ui->chkInstallTkgKernel->setText(installtkgkernel[lng]);

    ui->chkInstallZenKernel->setText(installzenkernel[lng]);

    ui->chkInstallXanmodKernel->setText(installxanmodkernel[lng]);

    ui->chkInstallKernelLqx->setText(installlqxfromrepo[lng]);

    ui->chkInstallKernelLqx->setText(installlqxfromrepo[lng]);

    ui->chkInstallXanmodFromRepo->setText(installxanmodfromrepo[lng]);

    ui->chkInstallKernelPf->setText(installkernelpf[lng]);

    ui->chkUpdateGrub->setText(updategrub[lng]);

    // Translation for video

    QStringList installvulkan;
    installvulkan << "Install Vulkan" << "Установка Vulkan";
    ui->chkInstallVulkan->setText(installvulkan[lng]);

    QStringList installportproton;
    installportproton << "Install PortProton" << "Установка PortProton";
    ui->chkInstallPortProton->setText(installportproton[lng]);

    QStringList installvideoplayers;
    installvideoplayers << "Install video players " << "Установка видео плееров";
    ui->chkInstallVideoPlayers->setText(installvideoplayers[lng]);

    QStringList installflatpak;
    installflatpak << "Install flatpak" << "Установка flatpak";
    ui->chkInstallFlatpak->setText(installflatpak[lng]);

    QStringList installsoftwarefromflatpak;
    installsoftwarefromflatpak << "Install soft from flatpak" << "Установка софта с флатпак";
    ui->chkInstallSoftwareFromFlatpak->setText(installsoftwarefromflatpak[lng]);

    QStringList installsnap;
    installsnap << "Install snapd" << "Установка snapd";
    ui->chkInstallSnap->setText(installsnap[lng]);

    QStringList installsystemclean;
    installsystemclean << "Install system cleaners" << "Уст. утилит для очистки";
    ui->chkInstallSystemClean->setText(installsystemclean[lng]);

    QStringList pipewire;
    pipewire << "Install pipewire" << "Установка pipewire";
    ui->chkInstallPipeWire->setText(pipewire[lng]);

    QStringList installrng;
    installrng << "Install rng " << "Установка rng";
    ui->chkInstallRNG->setText(installrng[lng]);

    QStringList privacypasswords;
    privacypasswords << "Install privacy, passwd" << "Хранение паролей и т.п.";
    ui->chkPrivacyPasswords->setText(privacypasswords[lng]);

    QStringList installwine;
    installwine << "Install WINE" << "Установка WINE";
    ui->chkInstallWine->setText(installwine[lng]);

    QStringList cinnamonoptimization;
    cinnamonoptimization << "Optimize Cinnamon" << "Оптимиз. Cinnamon";
    ui->chkCinnamonOptimization->setText(cinnamonoptimization[lng]);

    QStringList zramswap;
    zramswap << "Install zramswap" << "Установка zramswap";
    ui->chkInstallZramSwap->setText(zramswap[lng]);


    QStringList installnohang;
    installnohang << "Install NoHang" << "Установка Nohang";
    ui->chkInstallNohang->setText(installnohang[lng]);


    QStringList installvideodrivers;
    installvideodrivers << "Install Video Drivers " << "Установка видео драйверов";
    ui->chkInstallVideoDrivers->setText(installvideodrivers[lng]);


    // Tab de install

    QStringList installgnome;
    installgnome << "Install Gnome" << "Установка Gnome";
    ui->chkInstallGnome->setText(installgnome[lng]);

    QStringList installplasma;
    installplasma << "Install KDE Plasma" << "Установка KDE Plasma";
    ui->chkInstallPlasma->setText(installplasma[lng]);

    QStringList installcinnamon;
    installcinnamon << "Install Cinnamon" << "Установка Cinnamon";
    ui->chkInstallCinnamon->setText(installcinnamon[lng]);

    QStringList installdeepin;
    installdeepin << "Install Deepin" << "Установка Deepin";
    ui->chkInstallDeepin->setText(installdeepin[lng]);

    QStringList installlxde;
    installlxde << "Install LXDE" << "Установка LxDe";
    ui->chkInstall_LxDe->setText(installlxde[lng]);

    QStringList installlxqt;
    installlxqt << "InstallL LxQt" << "Установка LxQt";
    ui->chkInstallLxQt->setText(installlxqt[lng]);

    QStringList installmate;
    installmate << "Install MATE" << "Установка MATE";
    ui->chkInstallMate->setText(installmate[lng]);

    QStringList installxfce4;
    installxfce4 << "Install Xfce4" << "Установка Xfce4";
    ui->chkInstallXfce4->setText(installxfce4[lng]);

    QStringList installenl;
    installenl << "Install Enlightenment" << "Установка Enlightenment";
    ui->chkInstallEnl->setText(installenl[lng]);

    // tab greeter

    QStringList installpantheongreeter;
    installpantheongreeter << "Install Pantheon Greeter" << "Установка Pantheon Greeter";
    ui->chkInstallPantheonGreeter->setText(installpantheongreeter[lng]);


    QStringList installgreeteraether;
    installgreeteraether << "Install Aether Greeter" << "Установка Aether Greeter";
    ui->chkInstallGreeterAether->setText(installgreeteraether[lng]);

    QStringList installgreeterelefant;
    installgreeterelefant << "Install Elefant Greeter" << "Установка Elefant Greeter";
    ui->chkInstallGreeterElefant->setText(installgreeterelefant[lng]);

    QStringList installgreetermini;
    installgreetermini << "Install Mini Greeter" << "Установка Mini Greeter";
    ui->chkInstallGreeterMini->setText(installgreetermini[lng]);

    QStringList installgreeterslick;
    installgreeterslick << "Install Slick Greeter" << "Установка Slick Greeter";
    ui->chkInstallGreeterSlick->setText(installgreeterslick[lng]);

    QStringList installgreeterlitarvan;
    installgreeterlitarvan << "Install Litarvan Greeter" << "Установка Litarvan Greeter";
    ui->chkInstallLitarvanGreeter->setText(installgreeterlitarvan[lng]);


    QStringList installgreetergtk;
    installgreetergtk << "Install Gtk Greeter" << "Установка Gtk Greeter";
    ui->chkInstallGreeterGtk->setText(installgreetergtk[lng]);


    QStringList installgreeterwebkit;
    installgreeterwebkit << "Install Webkit Greeter" << "Установка WebKit Greeter";
    ui->chkInstallGreeterWebkit->setText(installgreeterwebkit[lng]);






}

QString MainWindow::getTerminal(){
    QStringList Terminal;
    Terminal << "konsole -e ";
    Terminal << "/bin/xterm -e ";
    Terminal << "/bin/uxterm -e ";
    Terminal << "/bin/xfce4-terminal -e ";
    Terminal << "/bin/terminator -e ";
    Terminal << "/bin/tilda -e ";
    Terminal << "/bin/roxterm -e ";
    Terminal << "/bin/tilix -e ";
    Terminal << "/bin/lxterminal -e ";
    Terminal << "/bin/gnome-terminal -e ";
    Terminal << "/bin/terminology -e ";
    Terminal << "/bin/deepin-terminal -e ";

    QString term = Terminal[0];
    int index = ui->cboTerminal->currentIndex();

    if (index>=0){
        term = Terminal[index];
    };
    return term;
}

QString MainWindow::getInstaller(){
    QStringList variants;
    variants << "arch";
    variants << "deb";
    variants << "rpm";


    QString variant = variants[0];
    int index = ui->cboInstaller->currentIndex();

    if (index>=0){
        variant = variants[index];
    };
    return variant;
}

void MainWindow::optimizeCinnamon(){
    QString path = qApp->applicationDirPath() +"/cinna.sh";
    QStringList lines;
    lines = getOptimizeCinnamon();
    CreateShFile(path, lines);
    QString term = this->getTerminal();
    InstallProc(term, "chmod +x cinna.sh");
    InstallProc(term, path);



}

void MainWindow::on_pushButton_clicked()
{
    // "arch", "deb" or "rpm"
    QString variant = this->getInstaller();

    QString term = this->getTerminal();


    QStringList Install_Keys_Actions;
    Install_Keys_Actions = getInstallKeysActions();

    QStringList Install_Mirrors_Actions;
    Install_Mirrors_Actions = getInstallMirrors();

    QStringList Install_Make_Actions;
    Install_Make_Actions = getInstallMakeActions();

    QStringList Install_System_Tools_Actions;
    Install_System_Tools_Actions = getInstallSystemTools();

    QStringList Install_Networking_Actions;
    Install_Networking_Actions = getInstallNetworking();

    QStringList Install_Freq_Actions;
    Install_Freq_Actions = getInstallFreq();


    QStringList Install_Auto_Freq;
    Install_Auto_Freq = getInstallAutoFreq();

    QStringList Install_Xanmod_Kernel_Actions;
    Install_Xanmod_Kernel_Actions = getInstallXanmodActions();

    QStringList Install_Tkg_Kernel_Actions;
    Install_Tkg_Kernel_Actions = getInstallTkgKernel();

    QStringList Install_Dbus_Broker_Actions;
    Install_Dbus_Broker_Actions = getInstallDbus( variant );

    QStringList Install_PortProton_Actions;
    Install_PortProton_Actions = getInstallPortProton( variant );

    QStringList Install_Vulkan_Actions;
    Install_Vulkan_Actions = getInstallVulkan( variant );


    QStringList Clear_Font_Cache_Actions;
    Clear_Font_Cache_Actions = getClearFontCache();


    QStringList Install_Security_Tools_Actions;
    Install_Security_Tools_Actions = getInstallSecurityTools();

    QStringList Install_Bluetooth_Tools_Actions;
    Install_Bluetooth_Tools_Actions = getInstallBluetooth( variant );


    QStringList Install_PulseAudio_Actions;
    Install_PulseAudio_Actions = getInstallPulseAudioActions( variant );

    QStringList Install_PipeWire_Actions;
    Install_PipeWire_Actions = getInstallPipeWireActions( variant );

    QStringList Install_Alsa_Actions;
    Install_Alsa_Actions = getInstallAlsaActions( variant );

    QStringList Install_Audio_Players_Actions;
    Install_Audio_Players_Actions = getInstallAudioPlayers( variant );

    QStringList Install_Internet_Tools_Actions;
    Install_Internet_Tools_Actions =getInstallInternetTools();


    QStringList Install_Developer_Tools_Actions;
    Install_Developer_Tools_Actions = getInstallDeveloperTools( variant );


    QStringList Install_Flatpak_Tools_Actions;
    Install_Flatpak_Tools_Actions = getInstallFlatPakActions();


    QStringList Install_Software_from_Flatpak;
    Install_Software_from_Flatpak = getInstallSoftwareFromFlatpak();

    QStringList Install_Snap_Tools_Actions;
    Install_Snap_Tools_Actions = getInstallSnapToolActions();


    QStringList Install_Wine_Actions;
    Install_Wine_Actions = getInstallWine( variant );



    QStringList Install_Messengers_Actions;
    Install_Messengers_Actions = getInstallMessengers();

    QStringList Install_Ananicy_Actions;
    Install_Ananicy_Actions = getInstallAnanicy();

    QStringList Install_RNG_Actions;
    Install_RNG_Actions = getInstallRng();

    QStringList Install_Haveged_Actions;
    Install_Haveged_Actions = getInstallHaveged();

    QStringList Enable_Trim_Actions;
    Enable_Trim_Actions = getEnableTrim();

    QStringList Install_System_Clean_Tools;
    Install_System_Clean_Tools = getInstallSystemClean();



    // ENVIROMENT TWEAKS

    QStringList GnomeTweaks;
    GnomeTweaks = getGnomeTweaksSh();




    QStringList PlasmaTweaks;
    PlasmaTweaks = getPlasmaTweaksSh();



    QStringList Xfce4Tweaks;
    Xfce4Tweaks = getXfce4TweaksSh();

    QStringList Install_ZramSwap_Actions;
    Install_ZramSwap_Actions = getInstallZramSwap();

    QStringList Install_Nohang_Actions;
    Install_Nohang_Actions = getInstallNohang();




    // DE Enviroment installing

    QStringList Install_De_Cinnamon;  Install_De_Cinnamon = getInstallDeCinnamon();
    QStringList Install_De_Deepin;   Install_De_Deepin = getInstallDeDeepin();
    QStringList Install_De_LxDe;  Install_De_LxDe = getInstallDeLxDe();
    QStringList Install_De_LxQt;  Install_De_LxQt = getInstallDeLxQt();
    QStringList Install_De_Mate;  Install_De_Mate = getInstallDeMate();
    QStringList Install_De_Plasma;  Install_De_Plasma = getInstallDePlasma();
    QStringList Install_De_Xfce4; Install_De_Xfce4 = getInstallDeXfce4();
    QStringList Install_De_Enl; Install_De_Enl = getInstallDeEnl();

    // Greeters installing

     QStringList Install_Pantheon_Greeter_Actions;  Install_Pantheon_Greeter_Actions = getInstallPantheonGreeter();










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
        QString path = qApp->applicationDirPath() +"/install-zen.sh";
        QStringList lines;
        lines << INSTALL_ZEN_KERNEL;
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-zen.sh");
        InstallProc(term, "/bin/bash install-zen.sh");
    }

    if (ui->chkInstallXanmodKernel->isChecked()){
        message = "Install Xanmod kernel";
        ui->centralwidget->setWindowTitle(message);
        QString path = qApp->applicationDirPath() +"/install-xanmod.sh";
        QStringList lines;
        lines = getInstallXanmodActions();
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-xanmod.sh");
        InstallProc(term, "/bin/bash install-xanmod.sh");
    }



    if (ui->chkInstallXanmodFromRepo->isChecked()){
        message = "Install Xanmod kernel from repo";
        ui->centralwidget->setWindowTitle(message);
        QString path = qApp->applicationDirPath() +"/install-xanmod-repo.sh";
        QStringList lines;
        lines = getInstallXanmodFromRepo();
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-xanmod-repo.sh");
        InstallProc(term, "/bin/bash install-xanmod-repo.sh");
    }


    if (ui->chkInstallKernelLqx->isChecked()){
        message = "Install Lqx kernel from repo";
        ui->centralwidget->setWindowTitle(message);
        QString path = qApp->applicationDirPath() +"/install-lqx-repo.sh";
        QStringList lines;
        lines = getInstallLqxFromRepo();
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-lqx-repo.sh");
        InstallProc(term, "/bin/bash install-lqx-repo.sh");
    }


    if (ui->chkInstallKernelPf->isChecked()){
        message = "Install Pf kernel from repo";
        ui->centralwidget->setWindowTitle(message);
        QString path = qApp->applicationDirPath() +"/install-pf-repo.sh";
        QStringList lines;
        lines = getInstallKernelPf();
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-pf-repo.sh");
        InstallProc(term, "/bin/bash install-pf-repo.sh");
    }




    if (ui->chkInstallTkgKernel->isChecked()){
        message = "Install Tkg kernel";
        ui->centralwidget->setWindowTitle(message);
        QString path = qApp->applicationDirPath() +"/install-tkg.sh";
        QStringList lines;
        lines = getInstallTkgKernel();
        CreateShFile(path, lines);
        QString term = this->getTerminal();
        InstallProc(term, "sudo chmod +x install-tkg.sh");
        InstallProc(term, "/bin/bash install-tkg.sh");
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
        message = "Install Vulkan video system";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Vulkan_Actions);
    }

    if (ui->chkInstallDbusBroker->isChecked()){
        message = "Install dbus broker";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Dbus_Broker_Actions);
    }

    if (ui->chkInstallPortProton->isChecked()){
        message = "Install PortProton";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_PortProton_Actions);
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
        InstallProcByList(term, Install_PipeWire_Actions);
    }

    if (ui->chkInstallAlsa->isChecked()){
        message = "Install PipeWire tools";
        ui->centralwidget->setWindowTitle(message);
        InstallProcByList(term, Install_Alsa_Actions);
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


 if (ui->chkRemoveOldPkgs->isChecked()){
     message = "Remove cache for old packages";
     ui->centralwidget->setWindowTitle(message);
     InstallProc( term, REMOVE_OLD_PKGS );
 }

 if (ui->chkRemoveAllPkgsCache->isChecked()){
     message = "Remove cache for all packages";
     ui->centralwidget->setWindowTitle(message);
     InstallProc( term, REMOVE_ALL_PKG_CACHE);
 }

 if (ui->chkRemoveOrpPackages->isChecked()){
     message = "Remove orphans";
     ui->centralwidget->setWindowTitle(message);
     InstallProc( term, REMOVE_ORPHANS);
 }

 if (ui->chkPlasmaOptimization->isChecked()){
     message = "Optimize KDE Plasma";
     ui->centralwidget->setWindowTitle(message);
     InstallProcByList(term, PlasmaTweaks);
 }

 if (ui->chkXfce4Optimization->isChecked()){
     message = "Optimize Xfce4";
     ui->centralwidget->setWindowTitle(message);
     InstallProcByList(term, Xfce4Tweaks);
 }

 if (ui->chkGnomeOptimization->isChecked()){
     message = "Optimize Gnome";
     ui->centralwidget->setWindowTitle(message);
     InstallProcByList(term, GnomeTweaks);
 }

 if (ui->chkCinnamonOptimization->isChecked()){
     message = "Cinnamon Optimization";
     ui->centralwidget->setWindowTitle(message);
     this->optimizeCinnamon();
 }

 if (ui->chkInstallZramSwap->isChecked()){
     message = "Install zramswap";
     ui->centralwidget->setWindowTitle(message);
     InstallProcByList(term, Install_ZramSwap_Actions);

}

 if (ui->chkInstallNohang->isChecked()){
     message = "Install nohang";
     ui->centralwidget->setWindowTitle(message);
     InstallProcByList(term, Install_Nohang_Actions);

}

if (ui->chkInstallVideoDrivers->isChecked()){
    message = "Install video drivers";
    ui->centralwidget->setWindowTitle(message);

    InstallProcByList(term, getInstallVideoDriver(ui->cboVideoDriver->currentIndex()));
}


// INSTALLING DE SECTION


if (ui->chkInstallCinnamon->isChecked()){
    message = "Install Cinnamon";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_Cinnamon);
}

if (ui->chkInstallDeepin->isChecked()){
    message = "Install Deepin";
    ui->centralwidget->setWindowTitle(message);
   InstallProcByList(term, Install_De_Deepin);
}

if (ui->chkInstall_LxDe->isChecked()){
    message = "Install LxDe";
    ui->centralwidget->setWindowTitle(message);
  InstallProcByList(term, Install_De_LxDe);
}

if (ui->chkInstallLxQt->isChecked()){
    message = "Install LxQt";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_LxQt);
}

if (ui->chkInstallMate->isChecked()){
    message = "Install MATE";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_Mate);
}

if (ui->chkInstallPlasma->isChecked()){
    message = "Install KDE Plasma";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_Plasma);
}

if (ui->chkInstallXfce4->isChecked()){
    message = "Install Xfce4";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_Xfce4);
}

if (ui->chkInstallEnl->isChecked()){
    message = "Install Enlightenment";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_De_Enl);
}



// tab greeter

if (ui->chkInstallPantheonGreeter->isChecked()){
    message = "Install Pantheon Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProcByList(term, Install_Pantheon_Greeter_Actions);
}

if (ui->chkInstallGreeterGtk->isChecked()){
    message = "Install Gtk Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_GTK_GREETER);
}

if (ui->chkInstallGreeterAether->isChecked()){
    message = "Install Aether  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_AETHER_GREETER);

}

if (ui->chkInstallGreeterSlick->isChecked()){
    message = "Install  Slick  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_SLICK_GREETER);


}

if (ui->chkInstallGreeterWebkit->isChecked()){
    message = "Install Webkit  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_WEBKIT_GREETER);
}

if (ui->chkInstallGreeterElefant->isChecked()){
    message = "Install Elefant  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_ELEFANT_GREETER);
}

if (ui->chkInstallGreeterMini->isChecked()){
    message = "Install Mini  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_MINI_GREETER);
}

if (ui->chkInstallLitarvanGreeter->isChecked()){
    message = "Install Mini  Greeter";
    ui->centralwidget->setWindowTitle(message);
    InstallProc(term, INSTALL_LITARVAN_GREETER);
}






}





void MainWindow::on_cboLanguage_currentIndexChanged(int index)
{
    int lng = ui->cboLanguage->currentIndex();
    if (lng>-1) {
        this->setTranslation(lng);
        } else
    {
        this->setTranslation(0);
    };
}

