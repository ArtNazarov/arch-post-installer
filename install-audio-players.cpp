#include <QStringList>
#include "./install-audio-players.h"


QStringList getInstallAudioPlayers(){
QStringList Install_Audio_Players_Actions;

Install_Audio_Players_Actions << "sudo pacman -Sy python-pip";
Install_Audio_Players_Actions << "pip install httpx";
Install_Audio_Players_Actions << "yay -Sy foobnix";
Install_Audio_Players_Actions << "sudo pacman -Sy clementine";
return Install_Audio_Players_Actions;
}
