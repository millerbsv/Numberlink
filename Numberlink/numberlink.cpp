#include "numberlink.h"

NumberLink::NumberLink()
{
    this->Fila_Columnas = 0;
}

void NumberLink::Asignar_Casillas(QString Nombre_Archivo)
{
    QFile Archivo(Nombre_Archivo);
    if(Archivo.open(QIODevice::ReadOnly))
    {
        QTextStream in(&Archivo);
        QString Linea = in.readLine();
        this->Fila_Columnas=QString(Linea).toInt();
        int Temp = this->Fila_Columnas;
        int Pos_Filas = 0;
        while(!in.atEnd()and Temp >0)
        {
            int Pos_Columnas = 30;
            QString Linea = in.readLine();
            QVector <QPushButton*> Fila;
            for(int i=0; i < this->Fila_Columnas; i++)
            {
                QPushButton* Casilla = new QPushButton();
                if(QString(Linea[i])!="0")
                    Casilla->setText(QString(Linea[i]));
                else
                    Casilla->setText(QString(""));
                Casilla->setGeometry(QRect(QPoint(Pos_Columnas*i,Pos_Filas),QSize(30,30)));
                Fila.push_back(Casilla);
            }
            this->Casillas.push_back(Fila);
            Pos_Filas+=30;
            Temp-=1;

        }
    }
}

QVector<QVector<QPushButton*> >  NumberLink::Obtener_Casillas()
{
    return this->Casillas;
}

bool NumberLink::Encontrar_Nodos_Iniciales(int Tipo)
{
    QVector <Posicion> Vector_Posiciones;
    if(Tipo == 0){
        for(int i=0 ; i < int(this->Casillas.size()) ; i++){
            for(int j=0 ; j < int(this->Casillas.size()) ; j++){
                if(this->Casillas.at(i).at(j)->text() != ""){
                    int repeticiones = 0;
                    if(j!=0){
                        if (this->Casillas.at(i).at(j)->text()== this->Casillas.at(i).at(j-1)->text()){
                            repeticiones++;
                        }
                    }
                    if(j!= int(this->Casillas.size())-1){
                        if (this->Casillas.at(i).at(j)->text()== this->Casillas.at(i).at(j+1)->text()){
                            repeticiones++;
                        }
                    }
                    if(i!=0){
                        if (this->Casillas.at(i).at(j)->text()== this->Casillas.at(i-1).at(j)->text()){
                            repeticiones++;
                        }
                    }
                    if(i!= int(this->Casillas.size())-1){
                        if (this->Casillas.at(i).at(j)->text()== this->Casillas.at(i+1).at(j)->text()){
                            repeticiones++;
                        }
                    }
                    if(repeticiones == 1){
                        Posicion temp;
                        temp.Pos_x = j;
                        temp.Pos_y = i;
                        Vector_Posiciones.append(temp);
                    }
                }
            }
        }
    }
    else{
        if(Tipo == 1){
            for(int i=0 ; i < int(this->Casillas.size()) ; i++){
                for(int j=0 ; j < int(this->Casillas.size()) ; j++){
                    if(this->Casillas.at(i).at(j)->text() != ""){
                        Posicion temp;
                        temp.Pos_x = j;
                        temp.Pos_y = i;
                        Vector_Posiciones.append(temp);
                    }
                }
            }
        }
    }

    if(Vector_Posiciones.size()%2!=0)
        return false;
    for(int i=0 ; i < int(Vector_Posiciones.size()) ; i++){
        Link temp;
        temp.Dato=this->Casillas.at(Vector_Posiciones.at(i).Pos_y).at(Vector_Posiciones.at(i).Pos_x)->text();
        temp.Inicio.Pos_x=Vector_Posiciones.at(i).Pos_x;
        temp.Inicio.Pos_y=Vector_Posiciones.at(i).Pos_y;
        temp.Fin.Pos_x = -1;
        temp.Fin.Pos_y = -1;
        for(int j=i+1 ; j < int(Vector_Posiciones.size()) ; j ++){
            if(Casillas.at(Vector_Posiciones.at(j).Pos_y).at(Vector_Posiciones.at(j).Pos_x)->text()==temp.Dato){
               temp.Fin.Pos_x=Vector_Posiciones.at(j).Pos_x;
               temp.Fin.Pos_y=Vector_Posiciones.at(j).Pos_y;
               Vector_Posiciones.removeAt(j);
               j=int(Vector_Posiciones.size());
            }
        }
        if(temp.Fin.Pos_x == -1){
            return false;
        }
        this->Nodos_Iniciales.append(temp);
    }
    return true;
}

bool NumberLink::Verificar()
{
    QVector <QVector <QString> > Validacion_Casillas;
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        QVector <QString> temp;
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            temp.append(this->Casillas.at(i).at(j)->text());
        }
        Validacion_Casillas.append(temp);
    }

    for(int i=0 ; i < int(this->Nodos_Iniciales.size()) ; i++){
        Posicion temp;
        temp.Pos_x=this->Nodos_Iniciales.at(i).Inicio.Pos_x;
        temp.Pos_y=this->Nodos_Iniciales.at(i).Inicio.Pos_y;
        while(Validacion_Casillas[temp.Pos_y][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato){
            Validacion_Casillas[temp.Pos_y][temp.Pos_x] ="0";

            int repeticiones = 0;
            if(temp.Pos_x!=0){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y][temp.Pos_x-1]){
                    repeticiones++;
                }
            }
            if(temp.Pos_x!= int(Validacion_Casillas.size())-1){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y][temp.Pos_x+1]){
                    repeticiones++;
                }
            }
            if(temp.Pos_y!=0){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y-1][temp.Pos_x]){
                    repeticiones++;
                }
            }
            if(temp.Pos_y!= int(Validacion_Casillas.size())-1){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y+1][temp.Pos_x]){
                    repeticiones++;
                }
            }
            if(repeticiones == 1){
                //this->Casillas.at(temp.Pos_y).at(temp.Pos_x);
                if((temp.Pos_x!=0)and(Validacion_Casillas[temp.Pos_y][temp.Pos_x-1]==this->Nodos_Iniciales.at(i).Dato)){
                    temp.Pos_y=temp.Pos_y;
                    temp.Pos_x=temp.Pos_x-1;
                }
                else{
                    if((temp.Pos_x!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.Pos_y][temp.Pos_x+1]==this->Nodos_Iniciales.at(i).Dato)){
                        temp.Pos_y=temp.Pos_y;
                        temp.Pos_x=temp.Pos_x+1;
                    }
                    else{
                        if((temp.Pos_y!=0)and(Validacion_Casillas[temp.Pos_y-1][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato)){
                            temp.Pos_x=temp.Pos_x;
                            temp.Pos_y=temp.Pos_y-1;
                        }
                        else{
                            if((temp.Pos_y!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.Pos_y+1][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato)){
                                temp.Pos_x=temp.Pos_x;
                                temp.Pos_y=temp.Pos_y+1;
                            }
                        }
                    }
                }
            }
            else{
                if(temp.Pos_x != Nodos_Iniciales.at(i).Fin.Pos_x and temp.Pos_y != Nodos_Iniciales.at(i).Fin.Pos_y){
                    return false;
                }
            }
        }
    }
    for(int i = 0 ; i < int(this->Casillas.size()) ; i++){
        for(int j = 0 ; j < int(this->Casillas.size()) ; j++){
            if (Validacion_Casillas.at(i).at(j) != "0"){
                return false;
            }
        }
    }
    return true;
}

bool NumberLink::Verificar(QVector <QVector <QString> > Validacion_Casillas)
{
    for(int i=0 ; i < int(this->Nodos_Iniciales.size()) ; i++){
        Posicion temp;
        temp.Pos_x=this->Nodos_Iniciales.at(i).Inicio.Pos_x;
        temp.Pos_y=this->Nodos_Iniciales.at(i).Inicio.Pos_y;
        while(Validacion_Casillas[temp.Pos_y][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato){
            Validacion_Casillas[temp.Pos_y][temp.Pos_x] ="0";

            int repeticiones = 0;
            if(temp.Pos_x!=0){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y][temp.Pos_x-1]){
                    repeticiones++;
                }
            }
            if(temp.Pos_x!= int(Validacion_Casillas.size())-1){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y][temp.Pos_x+1]){
                    repeticiones++;
                }
            }
            if(temp.Pos_y!=0){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y-1][temp.Pos_x]){
                    repeticiones++;
                }
            }
            if(temp.Pos_y!= int(Validacion_Casillas.size())-1){
                if (Nodos_Iniciales.at(i).Dato==Validacion_Casillas[temp.Pos_y+1][temp.Pos_x]){
                    repeticiones++;
                }
            }
            if(repeticiones == 1 and (temp.Pos_x != Nodos_Iniciales.at(i).Fin.Pos_x or temp.Pos_y != Nodos_Iniciales.at(i).Fin.Pos_y)){
                //this->Casillas.at(temp.Pos_y).at(temp.Pos_x);
                if((temp.Pos_x!=0)and(Validacion_Casillas[temp.Pos_y][temp.Pos_x-1]==this->Nodos_Iniciales.at(i).Dato)){
                    temp.Pos_y=temp.Pos_y;
                    temp.Pos_x=temp.Pos_x-1;
                }
                else{
                    if((temp.Pos_x!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.Pos_y][temp.Pos_x+1]==this->Nodos_Iniciales.at(i).Dato)){
                        temp.Pos_y=temp.Pos_y;
                        temp.Pos_x=temp.Pos_x+1;
                    }
                    else{
                        if((temp.Pos_y!=0)and(Validacion_Casillas[temp.Pos_y-1][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato)){
                            temp.Pos_x=temp.Pos_x;
                            temp.Pos_y=temp.Pos_y-1;
                        }
                        else{
                            if((temp.Pos_y!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.Pos_y+1][temp.Pos_x]==this->Nodos_Iniciales.at(i).Dato)){
                                temp.Pos_x=temp.Pos_x;
                                temp.Pos_y=temp.Pos_y+1;
                            }
                        }
                    }
                }
            }
            else{
                if(temp.Pos_x != Nodos_Iniciales.at(i).Fin.Pos_x and temp.Pos_y != Nodos_Iniciales.at(i).Fin.Pos_y){
                    return false;
                }
            }
        }
    }
    for(int i = 0 ; i < int(this->Casillas.size()) ; i++){
        for(int j = 0 ; j < int(this->Casillas.size()) ; j++){
            if (Validacion_Casillas.at(i).at(j) != "0"){
                return false;
            }
        }
    }
    return true;
}

void NumberLink::Asignar_Casillas(QVector<QVector<QPushButton *> > Casillas)
{
    this->Casillas = Casillas;
}

int NumberLink::Ingenuo()
{
    QVector < QVector <QVector <QString> > > Soluciones_Ingenuas;
    QVector <QVector <QString> > Validacion_Casillas;
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        QVector <QString> temp;
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            temp.append(this->Casillas.at(i).at(j)->text());
        }
        Validacion_Casillas.append(temp);
    }
    Soluciones_Ingenuas.append(Validacion_Casillas);
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            if(this->Casillas.at(i).at(j)->text() == ""){
                QVector < QVector <QVector <QString> > > Soluciones_Ingenuas_temp;
                while(int(Soluciones_Ingenuas.size()) > 0){
                    QVector <QVector <QString> > Validacion_Casillas_temp;
                    Validacion_Casillas_temp = Soluciones_Ingenuas.front();
                    Soluciones_Ingenuas.pop_front();
                    for(int z=0 ; z < int(this->Nodos_Iniciales.size()) ; z++){
                       Validacion_Casillas_temp[i][j]=Nodos_Iniciales.at(z).Dato;
                       Soluciones_Ingenuas_temp.append(Validacion_Casillas_temp);
                    }
                }
                Soluciones_Ingenuas = Soluciones_Ingenuas_temp;
            }
        }
    }
    int cant_soluciones_validas = 0;
    while(int(Soluciones_Ingenuas.size())>0){
        QVector < QVector < QString > > temp;
        temp = Soluciones_Ingenuas.first();
        if(Verificar(Soluciones_Ingenuas.first())){
            cant_soluciones_validas++;
        }
        Soluciones_Ingenuas.pop_front();
    }
    return cant_soluciones_validas;
}



