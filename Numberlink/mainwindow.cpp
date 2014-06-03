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
    this->NombreArchivo = "";
}

void MainWindow::on_actionAbrir_triggered()
{
    this->ui->textEdit->clear();
    for(int i=0; i<int(Casillas.size()); i++)
    {
        for(int j=0; j<int(Casillas.size()); j++)
        {
            Casillas[i][j]->close();
        }
    }
    this->NombreArchivo = QFileDialog::getOpenFileName(this, "Seleccione el archivo entrada", QDir::currentPath(),"Texto (*.txt)");
    if(!NombreArchivo.isEmpty())
    {
        NumberLink obj;
        obj.AsignarCasillas(NombreArchivo);
        Casillas = obj.Obtener_Casillas();
        for(int i=0; i<int(Casillas.size()); i++)
        {
            for(int j=0; j<int(Casillas.size()); j++)
            {
                Casillas[i][j]->setParent(ui->centralWidget);
                Casillas[i][j]->show();
            }
        }
        this->ui->textEdit->setGeometry(QRect(QPoint((30*int(this->Casillas.size())+30),10),QSize(200,300)));
        this->resize(QSize(250+(30*int(this->Casillas.size())),380));
    }
}

void MainWindow::on_actionIngenuo_triggered()
{
    NumberLink obj;
    obj.AsignarCasillas(this->Casillas);
    if (obj.EncontrarNodosIniciales(1))
    {
        QVector <int> respuesta=obj.Ingenuo();        
        this->ui->textEdit->setText("Soluciones encontrada: "+QString::number(respuesta[1])+"\nSoluciones generadas : "+QString::number(respuesta[0])+"\nProfundidad del arbol: "+QString::number(respuesta[2]));
        Casillas = obj.Obtener_Casillas();
        obj.ArchivoSalida();
    }
    else
    {
        this->ui->textEdit->setText("Solución incorrecta");
    }
}

void MainWindow::on_actionVerificar_triggered()
{
    NumberLink obj;
    obj.AsignarCasillas(this->Casillas);
    if (obj.EncontrarNodosIniciales(0))
    {
        bool algo = obj.Verificar();
        if (algo){
            this->ui->textEdit->setText("Solución correcta");
        }
        else
        {
            this->ui->textEdit->setText("Solución incorrecta");
        }
    }
    else
    {
        this->ui->textEdit->setText("Solución incorrecta");
    }
}

void MainWindow::on_actionBacktracking_triggered()
{
    NumberLink obj;
    obj.AsignarCasillas(this->Casillas);
    if (obj.EncontrarNodosIniciales(1))
    {
        obj.Backtraking();
        QString Desechadas = "";
        QVector <int> nivelAlternativaDesechada = obj.getrespuestanivelAlternativaDesechada();
        for(int i = 0 ; i < int(nivelAlternativaDesechada.size()) ; i ++ ){
            if(i == 0){
                Desechadas.append(QString::number(nivelAlternativaDesechada[i])+", ");
            }
            else{
                Desechadas.append(QString::number(nivelAlternativaDesechada[i])+", ");
            }
        }
        this->ui->textEdit->setText("Soluciones encontrada: "+QString::number(obj.getRespuestaCantContruidas())+"\nSoluciones desechadas : "+QString::number(obj.getRespuestaCantDesachada())+"\nProfundidad del arbol: "+QString::number(obj.getRespuestaProfundidad())+"\nMomento de desecho: "+Desechadas);
        Casillas = obj.Obtener_Casillas();
        obj.ArchivoSalida();
    }
    else
    {
        this->ui->textEdit->setText("Solución incorrecta");
    }    
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionCreadores_triggered()
{
    this->ui->textEdit->setText("Camilo Quintero\nDiego Lozada");
}

void MainWindow::on_action_C_mo_funciona_triggered()
{
    this->ui->textEdit->setText("Seleccione primero el archivo a leer (Abrir), luego seleccione el modo de solución a implementar, también puede verificar si el archivo abierto es una solució.\nSi se selecciona ingenuo, el programa realizara todas la soluciones posibles del tablero, y mostrar una de las soluciones encontradas además mostrara los resultados del algoritmo en este lugar.\nSi se selecciona backtracking, el programa realizara todas las soluciones posibles mediante backtracking teniendo en cuenta los candidatos por medio de comparaciones de sus vecinos y comprobación de los vecinos de sus vecinos (vecinos = arriba, abajo, izquierda, derecha).");
}

void MainWindow::on_actionVoraz_triggered()
{
    NumberLink obj;
    obj.AsignarCasillas(this->Casillas);
    if (obj.EncontrarNodosIniciales(1))
    {
        obj.Voraz();
        this->ui->textEdit->setText("Soluciones encontrada: "+QString::number(obj.getRespuestaCantContruidas()));
        Casillas = obj.Obtener_Casillas();
        obj.ArchivoSalida();
    }
    else
    {
        this->ui->textEdit->setText("Solución incorrecta");
    }
}

void MainWindow::on_actionColorear_triggered()
{
    NumberLink obj;
    obj.AsignarCasillas(this->Casillas);
    if (obj.EncontrarNodosIniciales(0)){
        obj.Colorear();
    }

}
