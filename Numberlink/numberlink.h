#ifndef NUMBERLINK_H
#define NUMBERLINK_H

#include <QString>
#include <QVector>
#include <QPushButton>
#include <QFile>
#include <QTextStream>


class NumberLink
{
private:
    QVector < QVector <QPushButton*> > Casillas;
    int Fila_Columnas;
public:
    NumberLink();
    void Asignar_Casillas(QString Nombre_Archivo);
    QVector < QVector <QPushButton*> > Obtener_Casillas();


};

#endif // NUMBERLINK_H
