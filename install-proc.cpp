#include <QString>
#include <QProcess>
#include "./install-proc.h"

void InstallProc(QString konsole, QString cmd){
 const QString bash_path = "/bin/bash";

 cmd="\""  + cmd +   "\"";

 QProcess::execute(bash_path, { "-c",  konsole + cmd });

}

void InstallProcByList(QString konsole, QStringList cmds){
 const QString bash_path = "/bin/bash";
 QString cmd = "";
 QStringListIterator it(cmds);

    while (it.hasNext()) {
        cmd = it.next().trimmed();

        cmd="\""  + cmd +   "\"";
        QProcess::execute(bash_path, { "-c",  konsole + cmd});
    }


}
