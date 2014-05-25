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
    struct Posicion{
        int Pos_x;
        int Pos_y;
    };
    struct Link{
        QString Dato;
        Posicion Inicio;
        Posicion Fin;
    };

    QVector < QVector <QPushButton*> > Casillas;
    QVector < Link > Nodos_Iniciales;
    int Fila_Columnas;
public:
    NumberLink();
    void Asignar_Casillas(QString Nombre_Archivo);
    QVector < QVector <QPushButton*> > Obtener_Casillas();
    bool Encontrar_Nodos_Iniciales(int Tipo);
    bool Verificar();
    bool Verificar(QVector <QVector <QString> > Validacion_Casillas);
    void Asignar_Casillas(QVector < QVector <QPushButton*> > Casillas);
    int Ingenuo();


};

#endif // NUMBERLINK_H
