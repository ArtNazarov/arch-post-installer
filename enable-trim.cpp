#include <QStringList>
#include "./enable-trim.h"

QStringList getEnableTrim(){
QStringList Enable_Trim_Actions;
Enable_Trim_Actions << "sudo systemctl enable fstrim.timer";
Enable_Trim_Actions << "sudo fstrim -v / ";
Enable_Trim_Actions << "sudo fstrim -va  / ";
return Enable_Trim_Actions;
}
