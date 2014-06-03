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
        int PosX;
        int PosY;
    };
    struct Link{
        QString Dato;
        Posicion Inicio;
        Posicion Fin;
    };
    struct RespuestaBacktraking{
        QVector <int> NivelAlternativaDesechada;
        int CantDesechada;
        int CantContruidas;
        int Profundidad;
    };
    //control funciona para verificar que no tenga ramificaciones y numeros encerrados.
    struct Backtraking_Elementos{
        QString Soluciones;
        int Control;
    };

    QVector < QVector <QPushButton*> > Casillas;
    QVector < Link > NodosIniciales;
    int FilaColumnas;
    bool Es_Candidato(QVector <QVector <Backtraking_Elementos> > Solucion_Parcial, int Pos_x, int Pos_y);
    QVector <QVector <Backtraking_Elementos> > Soluciones;
    RespuestaBacktraking Respuesta;
    QVector <QString> Colores;

public:
    NumberLink();
    void AsignarCasillas(QString Nombre_Archivo);
    QVector < QVector <QPushButton*> > Obtener_Casillas();
    bool EncontrarNodosIniciales(int Tipo);
    bool Verificar();
    bool Verificar(QVector <QVector <QString> > Validacion_Casillas);
    bool Verificar(QVector <QVector <Backtraking_Elementos> > Solucion);
    void AsignarCasillas(QVector < QVector <QPushButton*> > Casillas);
    QVector <int> Ingenuo();
    bool Backtraking(QVector <QVector <Backtraking_Elementos> > Soluciones_Completas, int i, int j);
    void Backtraking();
    int getRespuestaCantDesachada();
    int getRespuestaCantContruidas();
    int getRespuestaProfundidad();
    void Voraz();
    QVector <int> getrespuestanivelAlternativaDesechada();
    void Colorear();
    void ArchivoSalida();

};

#endif // NUMBERLINK_H
