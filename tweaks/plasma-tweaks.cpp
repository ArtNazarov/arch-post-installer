#include <QStringList>

QStringList getPlasmaTweaksSh(){


    QStringList PlasmaTweaks;
    PlasmaTweaks << "sudo systemctl --user mask kde-baloo.service";
    PlasmaTweaks << "sudo systemctl --user mask plasma-baloorunner.service";
     // or trying other method
    PlasmaTweaks << "sudo balooctl suspend";
    PlasmaTweaks << "sudo balooctl disable";
    PlasmaTweaks << "sudo balooctl purge";
    return PlasmaTweaks;
}
