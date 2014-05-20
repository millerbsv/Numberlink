#include "numberlink.h"

NumberLink::NumberLink()
{
    Fila_Columnas = 0;
}

void NumberLink::Asignar_Casillas(QString Nombre_Archivo)
{
    QFile Archivo(Nombre_Archivo);
    if(Archivo.open(QIODevice::ReadOnly))
    {
        QTextStream in(&Archivo);
        QString Linea = in.readLine();
        Fila_Columnas=QString(Linea).toInt();
        int Temp = Fila_Columnas;
        int Pos_Filas = 0;
        while(!in.atEnd()and Temp >0)
        {
            int Pos_Columnas = 30;
            QString Linea = in.readLine();
            QVector <QPushButton*> Fila;
            for(int i=0; i < Fila_Columnas; i++)
            {
                QPushButton* Casilla = new QPushButton();
                if(QString(Linea[i])!="0")
                    Casilla->setText(QString(Linea[i]));
                else
                    Casilla->setText(QString(""));
                Casilla->setGeometry(QRect(QPoint(Pos_Columnas*i,Pos_Filas),QSize(30,30)));
                Fila.push_back(Casilla);
            }
            Casillas.push_back(Fila);
            Pos_Filas+=30;
            Temp-=1;

        }
    }

}

QVector<QVector<QPushButton*> >  NumberLink::Obtener_Casillas()
{
    return Casillas;
}
