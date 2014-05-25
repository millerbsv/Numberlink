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
    for(int i=0; i<int(Casillas.size()); i++)
    {
        for(int j=0; j<int(Casillas.size()); j++)
        {
            Casillas[i][j]->close();
        }
    }
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
    NumberLink obj;
    obj.Asignar_Casillas(this->Casillas);
    if (obj.Encontrar_Nodos_Iniciales(1))
    {
        this->ui->label->setText("S.E: "+QString::number(obj.Ingenuo()));
        this->ui->label->setGeometry(QRect(QPoint((30*int(this->Casillas.size())/2)-50,30*int(this->Casillas.size())),QSize(200,30)));
    }
    else
    {
        this->ui->label->setText("Solución incorrecta");
    }
    this->ui->label->setGeometry(QRect(QPoint((30*int(this->Casillas.size())/2)-50,30*int(this->Casillas.size())),QSize(100,30)));

}

void MainWindow::on_actionVerificar_triggered()
{
    NumberLink obj;
    obj.Asignar_Casillas(this->Casillas);
    if (obj.Encontrar_Nodos_Iniciales(0))
    {
        bool algo = obj.Verificar();
        if (algo){
            this->ui->label->setText("Solución correcta");
        }    //printf("true");
        else
        {
            this->ui->label->setText("Solución incorrecta");
        }
    }
    else
    {
        this->ui->label->setText("Solución incorrecta");
    }
    this->ui->label->setGeometry(QRect(QPoint((30*int(this->Casillas.size())/2)-50,30*int(this->Casillas.size())),QSize(100,30)));

}
