#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QFile>
#include "./create-sh-file.h"
void CreateShFile(QString path, QStringList lines){
 QFile file(path);
if(file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
     QTextStream out(&file);



     for (int i = 0; i < lines.size(); ++i)
            out << lines.at(i).toLocal8Bit().constData() << Qt::endl;


    file.close();
}

}
