
#include <QStringList>
#include "cleaning/clear-font-cache.h"

QStringList getClearFontCache(){

    QStringList Clear_Font_Cache_Actions;

    Clear_Font_Cache_Actions << "sudo rm /var/cache/fontconfig/*";
    Clear_Font_Cache_Actions << "rm ~/.cache/fontconfig/*";
    Clear_Font_Cache_Actions << "fc-cache -r";

    return Clear_Font_Cache_Actions;
}
