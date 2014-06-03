#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "numberlink.h"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAbrir_triggered();

    void on_actionIngenuo_triggered();

    void on_actionVerificar_triggered();

    void on_actionBacktracking_triggered();

    void on_actionSalir_triggered();

    void on_actionCreadores_triggered();

    void on_action_C_mo_funciona_triggered();

    void on_actionVoraz_triggered();

    void on_actionColorear_triggered();

private:
    Ui::MainWindow *ui;
    QVector < QVector <QPushButton*> > Casillas;
    QString NombreArchivo;
    struct RespuestaBacktraking{
        QVector <int> Nivel_Alternativa_Desechada;
        int CantDesechada;
        int CantContruidas;
        int Profundidad;
    };
};

#endif // MAINWINDOW_H
