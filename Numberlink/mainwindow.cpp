#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNuevo_triggered()
{
    QString Nombre_Archivo = QFileDialog::getOpenFileName(this, "Seleccione el archivo entrada", QDir::currentPath(),"Texto (*.txt)");
    if(!Nombre_Archivo.isEmpty())
    {
        NumberLink obj;
        obj.Asignar_Casillas(Nombre_Archivo);
        Casillas = obj.Obtener_Casillas();
        for(int i=0; i<int(Casillas.size()); i++)
        {
            for(int j=0; j<int(Casillas.size()); j++)
            {
                Casillas[i][j]->setParent(ui->centralWidget);
                Casillas[i][j]->show();
            }
        }
        this->resize(QSize(30*int(Casillas.size()),70+(30*int(Casillas.size()))));

    }
}

void MainWindow::on_actionAbrir_triggered()
{
    QString Nombre_Archivo = QFileDialog::getOpenFileName(this, "Seleccione el archivo entrada", QDir::currentPath(),"Texto (*.txt)");
    if(!Nombre_Archivo.isEmpty())
    {
        NumberLink obj;
        obj.Asignar_Casillas(Nombre_Archivo);
        Casillas = obj.Obtener_Casillas();
        for(int i=0; i<int(Casillas.size()); i++)
        {
            for(int j=0; j<int(Casillas.size()); j++)
            {
                Casillas[i][j]->setParent(ui->centralWidget);
                Casillas[i][j]->show();
            }
        }
        this->resize(QSize(30*int(Casillas.size()),130+(30*int(Casillas.size()))));
    }
}

void MainWindow::on_actionIngenuo_triggered()
{

}

void MainWindow::on_actionVerificar_triggered()
{
    NumberLink obj;
    obj.Asignar_Casillas(this->Casillas);
    obj.Encontrar_Nodos_Iniciales();
    bool algo = obj.Verificar();
    if (algo){
        printf("true");
    }
    else
    {
        printf("false");
    }


}
