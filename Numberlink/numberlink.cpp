#include "numberlink.h"

bool NumberLink::Es_Candidato(QVector<QVector<NumberLink::Backtraking_Elementos> > SolucionParcial, int PosY, int PosX)
{
    int repeticiones = SolucionParcial[PosY][PosX].Control;
    /*
     * primera validacion
     * verificar sus vecinos
     */
    if(PosY-1 >= 0){
        if(SolucionParcial[PosY-1][PosX].Control == -1){
            repeticiones--;
        }
    }
    if(PosY+1 < int(SolucionParcial.size())){
        if(SolucionParcial[PosY+1][PosX].Control == -1){
            repeticiones--;
        }
    }
    if(PosX-1 >= 0){
        if(SolucionParcial[PosY][PosX-1].Control == -1){
            repeticiones--;
        }
    }
    if(PosX+1 < int(SolucionParcial.size())){
        if(SolucionParcial[PosY][PosX+1].Control == -1){
            repeticiones--;
        }
    }
    if(!(repeticiones <=0)){
        return false;
    }
    /*
     * validar sus vecinos si tiene movimientos
     */
    int PosXOrigen = PosX;
    int PosYOrigen = PosY;
    if(PosY-1 >= 0){
        PosY = PosYOrigen-1;
        repeticiones = SolucionParcial[PosY][PosX].Control;
        if(PosY-1 >= 0){
            if(SolucionParcial[PosY-1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosY+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY+1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosX-1 >= 0){
            if(SolucionParcial[PosY][PosX-1].Control == -1){
                repeticiones--;
            }
        }
        if(PosX+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY][PosX+1].Control == -1){
                repeticiones--;
            }
        }
        if(!(repeticiones <=0)){
            return false;
        }
    }
    PosY = PosYOrigen;
    if(PosY+1 < int(SolucionParcial.size())){
        PosY = PosYOrigen+1;
        repeticiones = SolucionParcial[PosY][PosX].Control;
        //si es -1 se salto todo
        if(PosY-1 >= 0){
            if(SolucionParcial[PosY-1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosY+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY+1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosX-1 >= 0){
            if(SolucionParcial[PosY][PosX-1].Control == -1){
                repeticiones--;
            }
        }
        if(PosX+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY][PosX+1].Control == -1){
                repeticiones--;
            }
        }
        if(!(repeticiones <=0)){
            return false;
        }
    }
    PosY = PosYOrigen;
    if(PosX-1 >= 0){
        PosX = PosXOrigen-1;
        repeticiones = SolucionParcial[PosY][PosX].Control;
        if(PosY-1 >= 0){
            if(SolucionParcial[PosY-1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosY+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY+1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosX-1 >= 0){
            if(SolucionParcial[PosY][PosX-1].Control == -1){
                repeticiones--;
            }
        }
        if(PosX+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY][PosX+1].Control == -1){
                repeticiones--;
            }
        }
        if(!(repeticiones <=0)){
            return false;
        }
    }
    PosX = PosXOrigen;
    if(PosX+1 < int(SolucionParcial.size())){
        PosX = PosXOrigen+1;
        repeticiones = SolucionParcial[PosY][PosX].Control;
        if(PosY-1 >= 0){
            if(SolucionParcial[PosY-1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosY+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY+1][PosX].Control == -1){
                repeticiones--;
            }
        }
        if(PosX-1 >= 0){
            if(SolucionParcial[PosY][PosX-1].Control == -1){
                repeticiones--;
            }
        }
        if(PosX+1 < int(SolucionParcial.size())){
            if(SolucionParcial[PosY][PosX+1].Control == -1){
                repeticiones--;
            }
        }
        if(!(repeticiones <=0)){
            return false;
        }
    }
    return true;
}
bool NumberLink::Verificar(QVector<QVector<NumberLink::Backtraking_Elementos> > Validacion_Casillas)
{
    for(int i=0 ; i < int(this->NodosIniciales.size()) ; i++){
        Posicion temp;
        temp.PosX=this->NodosIniciales.at(i).Inicio.PosX;
        temp.PosY=this->NodosIniciales.at(i).Inicio.PosY;
        while(Validacion_Casillas[temp.PosY][temp.PosX].Soluciones==this->NodosIniciales.at(i).Dato){
            Validacion_Casillas[temp.PosY][temp.PosX].Soluciones ="0";

            int repeticiones = 0;
            if(temp.PosX!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX-1].Soluciones){
                    repeticiones++;
                }
            }
            if(temp.PosX!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX+1].Soluciones){
                    repeticiones++;
                }
            }
            if(temp.PosY!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY-1][temp.PosX].Soluciones){
                    repeticiones++;
                }
            }
            if(temp.PosY!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY+1][temp.PosX].Soluciones){
                    repeticiones++;
                }
            }
            if(repeticiones == 1 and (temp.PosX != NodosIniciales.at(i).Fin.PosX or temp.PosY != NodosIniciales.at(i).Fin.PosY)){
                //this->Casillas.at(temp.Pos_y).at(temp.Pos_x);
                if((temp.PosX!=0)and(Validacion_Casillas[temp.PosY][temp.PosX-1].Soluciones==this->NodosIniciales.at(i).Dato)){
                    temp.PosY=temp.PosY;
                    temp.PosX=temp.PosX-1;
                }
                else{
                    if((temp.PosX!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY][temp.PosX+1].Soluciones==this->NodosIniciales.at(i).Dato)){
                        temp.PosY=temp.PosY;
                        temp.PosX=temp.PosX+1;
                    }
                    else{
                        if((temp.PosY!=0)and(Validacion_Casillas[temp.PosY-1][temp.PosX].Soluciones==this->NodosIniciales.at(i).Dato)){
                            temp.PosX=temp.PosX;
                            temp.PosY=temp.PosY-1;
                        }
                        else{
                            if((temp.PosY!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY+1][temp.PosX].Soluciones==this->NodosIniciales.at(i).Dato)){
                                temp.PosX=temp.PosX;
                                temp.PosY=temp.PosY+1;
                            }
                        }
                    }
                }
            }
            else{
                if(temp.PosX != NodosIniciales.at(i).Fin.PosX and temp.PosY != NodosIniciales.at(i).Fin.PosY){
                    return false;
                }
            }
        }
    }
    for(int i = 0 ; i < int(this->Casillas.size()) ; i++){
        for(int j = 0 ; j < int(this->Casillas.size()) ; j++){
            if (Validacion_Casillas.at(i).at(j).Soluciones != "0"){
                return false;
            }
        }
    }
    return true;
}

NumberLink::NumberLink()
{
    this->FilaColumnas = 0;
    this->Colores.append("background-color: red");
    this->Colores.append("background-color: white");
    this->Colores.append("background-color: green");
    this->Colores.append("background-color: blue");
    this->Colores.append("background-color: yellow");
    this->Colores.append("background-color: cyan");
    this->Colores.append("background-color: magenta");
    this->Colores.append("background-color: darkBlue");
    this->Colores.append("background-color: darkRed");
    this->Colores.append("background-color: gray");
}

void NumberLink::AsignarCasillas(QString Nombre_Archivo)
{
    QFile Archivo(Nombre_Archivo);
    if(Archivo.open(QIODevice::ReadOnly))
    {
        QTextStream in(&Archivo);
        QString Linea = in.readLine();
        this->FilaColumnas=QString(Linea).toInt();
        int Temp = this->FilaColumnas;
        int Pos_Filas = 10;
        while(!in.atEnd()and Temp >0)
        {
            int Pos_Columnas = 30;
            QString Linea = in.readLine();
            QVector <QPushButton*> Fila;
            for(int i=0; i < this->FilaColumnas; i++)
            {
                QPushButton* Casilla = new QPushButton();
                if(QString(Linea[i])!="0")
                    Casilla->setText(QString(Linea[i]));
                else
                    Casilla->setText(QString(""));
                Casilla->setGeometry(QRect(QPoint(Pos_Columnas*i+10,Pos_Filas),QSize(30,30)));
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

/*
 * el tipo 0 encuentra los nodos iniciales si es una matriz final
 * el tipo 1 encuentra los nodos iniciales si es una matriz inicial
 */
bool NumberLink::EncontrarNodosIniciales(int Tipo)
{
    QVector <Posicion> VectorPosiciones;
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
                        temp.PosX = j;
                        temp.PosY = i;
                        VectorPosiciones.append(temp);
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
                        temp.PosX = j;
                        temp.PosY = i;
                        VectorPosiciones.append(temp);
                    }
                }
            }
        }
    }

    if(VectorPosiciones.size()%2!=0)
        return false;
    for(int i=0 ; i < int(VectorPosiciones.size()) ; i++){
        Link temp;
        temp.Dato=this->Casillas.at(VectorPosiciones.at(i).PosY).at(VectorPosiciones.at(i).PosX)->text();
        temp.Inicio.PosX=VectorPosiciones.at(i).PosX;
        temp.Inicio.PosY=VectorPosiciones.at(i).PosY;
        temp.Fin.PosX = -1;
        temp.Fin.PosY = -1;
        for(int j=i+1 ; j < int(VectorPosiciones.size()) ; j ++){
            if(Casillas.at(VectorPosiciones.at(j).PosY).at(VectorPosiciones.at(j).PosX)->text()==temp.Dato){
               temp.Fin.PosX=VectorPosiciones.at(j).PosX;
               temp.Fin.PosY=VectorPosiciones.at(j).PosY;
               VectorPosiciones.removeAt(j);
               j=int(VectorPosiciones.size());
            }
        }
        if(temp.Fin.PosX == -1){
            return false;
        }
        this->NodosIniciales.append(temp);
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

    for(int i=0 ; i < int(this->NodosIniciales.size()) ; i++){
        Posicion temp;
        temp.PosX=this->NodosIniciales.at(i).Inicio.PosX;
        temp.PosY=this->NodosIniciales.at(i).Inicio.PosY;
        while(Validacion_Casillas[temp.PosY][temp.PosX]==this->NodosIniciales.at(i).Dato){
            Validacion_Casillas[temp.PosY][temp.PosX] ="0";

            int repeticiones = 0;
            if(temp.PosX!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX-1]){
                    repeticiones++;
                }
            }
            if(temp.PosX!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX+1]){
                    repeticiones++;
                }
            }
            if(temp.PosY!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY-1][temp.PosX]){
                    repeticiones++;
                }
            }
            if(temp.PosY!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY+1][temp.PosX]){
                    repeticiones++;
                }
            }
            if(repeticiones == 1){
                //this->Casillas.at(temp.Pos_y).at(temp.Pos_x);
                if((temp.PosX!=0)and(Validacion_Casillas[temp.PosY][temp.PosX-1]==this->NodosIniciales.at(i).Dato)){
                    temp.PosY=temp.PosY;
                    temp.PosX=temp.PosX-1;
                }
                else{
                    if((temp.PosX!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY][temp.PosX+1]==this->NodosIniciales.at(i).Dato)){
                        temp.PosY=temp.PosY;
                        temp.PosX=temp.PosX+1;
                    }
                    else{
                        if((temp.PosY!=0)and(Validacion_Casillas[temp.PosY-1][temp.PosX]==this->NodosIniciales.at(i).Dato)){
                            temp.PosX=temp.PosX;
                            temp.PosY=temp.PosY-1;
                        }
                        else{
                            if((temp.PosY!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY+1][temp.PosX]==this->NodosIniciales.at(i).Dato)){
                                temp.PosX=temp.PosX;
                                temp.PosY=temp.PosY+1;
                            }
                        }
                    }
                }
            }
            else{
                if(temp.PosX != NodosIniciales.at(i).Fin.PosX and temp.PosY != NodosIniciales.at(i).Fin.PosY){
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
    for(int i=0 ; i < int(this->NodosIniciales.size()) ; i++){
        Posicion temp;
        temp.PosX=this->NodosIniciales.at(i).Inicio.PosX;
        temp.PosY=this->NodosIniciales.at(i).Inicio.PosY;
        while(Validacion_Casillas[temp.PosY][temp.PosX]==this->NodosIniciales.at(i).Dato){
            Validacion_Casillas[temp.PosY][temp.PosX] ="0";

            int repeticiones = 0;
            if(temp.PosX!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX-1]){
                    repeticiones++;
                }
            }
            if(temp.PosX!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY][temp.PosX+1]){
                    repeticiones++;
                }
            }
            if(temp.PosY!=0){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY-1][temp.PosX]){
                    repeticiones++;
                }
            }
            if(temp.PosY!= int(Validacion_Casillas.size())-1){
                if (NodosIniciales.at(i).Dato==Validacion_Casillas[temp.PosY+1][temp.PosX]){
                    repeticiones++;
                }
            }
            if(repeticiones == 1 and (temp.PosX != NodosIniciales.at(i).Fin.PosX or temp.PosY != NodosIniciales.at(i).Fin.PosY)){
                //this->Casillas.at(temp.Pos_y).at(temp.Pos_x);
                if((temp.PosX!=0)and(Validacion_Casillas[temp.PosY][temp.PosX-1]==this->NodosIniciales.at(i).Dato)){
                    temp.PosY=temp.PosY;
                    temp.PosX=temp.PosX-1;
                }
                else{
                    if((temp.PosX!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY][temp.PosX+1]==this->NodosIniciales.at(i).Dato)){
                        temp.PosY=temp.PosY;
                        temp.PosX=temp.PosX+1;
                    }
                    else{
                        if((temp.PosY!=0)and(Validacion_Casillas[temp.PosY-1][temp.PosX]==this->NodosIniciales.at(i).Dato)){
                            temp.PosX=temp.PosX;
                            temp.PosY=temp.PosY-1;
                        }
                        else{
                            if((temp.PosY!= int(Validacion_Casillas.size())-1)and(Validacion_Casillas[temp.PosY+1][temp.PosX]==this->NodosIniciales.at(i).Dato)){
                                temp.PosX=temp.PosX;
                                temp.PosY=temp.PosY+1;
                            }
                        }
                    }
                }
            }
            else{
                if(temp.PosX != NodosIniciales.at(i).Fin.PosX and temp.PosY != NodosIniciales.at(i).Fin.PosY){
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

void NumberLink::AsignarCasillas(QVector<QVector<QPushButton *> > Casillas)
{
    this->Casillas = Casillas;
}

QVector <int> NumberLink::Ingenuo()
{
    QVector <int> respuestas;
    int profundidad =0;
    int cantSolucionesValidas = 0;
    QVector < QVector <QVector <QString> > > SolucionesIngenuas;
    QVector <QVector <QString> > Validacion_Casillas;
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        QVector <QString> temp;
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            temp.append(this->Casillas.at(i).at(j)->text());
        }
        Validacion_Casillas.append(temp);
    }
    SolucionesIngenuas.append(Validacion_Casillas);
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            if(this->Casillas.at(i).at(j)->text() == ""){
                profundidad++;
                QVector < QVector <QVector <QString> > > Soluciones_Ingenuas_temp;
                while(int(SolucionesIngenuas.size()) > 0){
                    QVector <QVector <QString> > Validacion_Casillas_temp;
                    Validacion_Casillas_temp = SolucionesIngenuas.front();
                    SolucionesIngenuas.pop_front();
                    for(int z=0 ; z < int(this->NodosIniciales.size()) ; z++){
                       Validacion_Casillas_temp[i][j]=NodosIniciales.at(z).Dato;
                       Soluciones_Ingenuas_temp.append(Validacion_Casillas_temp);
                    }
                }
                SolucionesIngenuas = Soluciones_Ingenuas_temp;
            }
        }
    }    
    respuestas.append(int(SolucionesIngenuas.size()));
    while(int(SolucionesIngenuas.size())>0){
        QVector < QVector < QString > > temp;
        temp = SolucionesIngenuas.first();
        if(Verificar(SolucionesIngenuas.first())){
            cantSolucionesValidas++;
            for(int i=0 ; i < int(this->Casillas.size()) ; i++){
                for (int j=0 ; j < int(this->Casillas.size()) ; j++){
                    this->Casillas.at(i).at(j)->setText(SolucionesIngenuas.first()[i][j]);
                }
            }
        }
        SolucionesIngenuas.pop_front();
    }
    respuestas.append(cantSolucionesValidas);
    respuestas.append(profundidad);
    /*respuestas pos 0 cantidad de soluciones generadas
     *respuestas pos 1 cantudad de soluciones validas
     *respuestas pos 2 cantidad de la profundidad del arbol
     */
    return respuestas;
}

bool NumberLink::Backtraking(QVector<QVector<NumberLink::Backtraking_Elementos> > Soluciones_Completas, int i, int j)
{
    bool exito = false;
    //seleccionar nueva opción
    if((i < int(this->Casillas.size()))and( j < int(this->Casillas.size()))){
        this->Respuesta.Profundidad++;
        if(this->Casillas.at(i).at(j)->text() == ""){
            for(int z=0 ; z < int(this->NodosIniciales.size()) ; z++){
               QVector <QVector <Backtraking_Elementos> > Soluciones_temp;
               Soluciones_temp = Soluciones_Completas;
               //Soluciones_temp[i][j] = this->NodosIniciales[i][j];
               int validar_candidato = 0;
               if(i-1 >= 0){
                   if((Soluciones_temp[i-1][j].Soluciones == this->NodosIniciales[z].Dato)and(Soluciones_temp[i-1][j].Control == 0)){
                       validar_candidato++;
                   }
               }
               if(i+1 < int(Soluciones_temp.size())){
                   if((Soluciones_temp[i+1][j].Soluciones == this->NodosIniciales[z].Dato)and(Soluciones_temp[i+1][j].Control == 0)){
                       validar_candidato++;
                   }
               }
               if(j-1 >= 0){
                   if((Soluciones_temp[i][j-1].Soluciones == this->NodosIniciales[z].Dato)and(Soluciones_temp[i][j-1].Control == 0)){
                       validar_candidato++;
                   }
               }
               if(j+1 < int(Soluciones_temp.size())){
                   if((Soluciones_temp[i][j+1].Soluciones == this->NodosIniciales[z].Dato)and(Soluciones_temp[i][j+1].Control == 0)){
                       validar_candidato++;
                   }
               }
               if(validar_candidato == 0){
                   int repeticiones = 2;
                   Soluciones_temp[i][j].Soluciones=this->NodosIniciales[z].Dato;
                   if(i-1 >= 0){
                       if(Soluciones_temp[i-1][j].Soluciones == NodosIniciales[z].Dato){
                           repeticiones--;
                           Soluciones_temp[i-1][j].Control -= 1;
                       }
                   }
                   if(i+1 < int(Soluciones_temp.size())){
                       if(Soluciones_temp[i+1][j].Soluciones == NodosIniciales[z].Dato){
                           repeticiones--;
                           Soluciones_temp[i+1][j].Control -= 1;
                       }
                   }
                   if(j-1 >= 0){
                       if(Soluciones_temp[i][j-1].Soluciones == NodosIniciales[z].Dato){
                           repeticiones--;
                           Soluciones_temp[i][j-1].Control -= 1;
                       }
                   }
                   if(j+1 < int(Soluciones_temp.size())){
                       if(Soluciones_temp[i][j+1].Soluciones == NodosIniciales[z].Dato){
                           repeticiones--;
                           Soluciones_temp[i][j+1].Control -= 1;
                       }
                   }
                   Soluciones_temp[i][j].Control = repeticiones;

                   if(Es_Candidato(Soluciones_temp,i,j)){
                       //Soluciones_Completas = Soluciones_temp;
                       if(Verificar(Soluciones_temp)){
                           //asignar respuesta
                           this->Respuesta.CantContruidas++;
                           for(int i=0 ; i< int(this->Casillas.size()) ; i++){
                               for(int j=0 ; j < int(this->Casillas.size()) ; j++){
                                   this->Casillas[i][j]->setText(Soluciones_temp[i][j].Soluciones);
                               }
                           }
                           exito = true;
                       }
                       else{
                           int iOrigen = i;
                           int jOrigen = j;
                           if( j == int(this->Casillas.size())-1){
                               j=0;
                               i++;
                           }
                           else{
                               j++;
                           }
                           exito = Backtraking(Soluciones_temp,i,j);
                           if(!exito){
                               i = iOrigen;
                               j = jOrigen;
                           }
                       }
                   }
                   else{
                       this->Respuesta.CantDesechada++;
                       this->Respuesta.NivelAlternativaDesechada.append(i*(int(this->Casillas.size())-1)+j);
                   }
               }
               else{
                   this->Respuesta.CantDesechada++;
                   this->Respuesta.NivelAlternativaDesechada.append(i*(int(this->Casillas.size())-1)+j);
               }
            }
        }
        else{
            if( j == int(this->Casillas.size())-1){
                j=0;
                i++;
            }
            else{
                j++;
            }
            exito = Backtraking(Soluciones_Completas,i,j);
            if(!exito){
                 return false;
            }
        }
    }
    return false;
}

void NumberLink::Backtraking()
{
    this->Respuesta.CantContruidas = 0;
    this->Respuesta.Profundidad = 0;
    this->Respuesta.CantDesechada = 0;
    this->Respuesta.NivelAlternativaDesechada.clear();
    //lenar matriz de soluciones y control, -1 para indicar que no hay numeros.
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        QVector <Backtraking_Elementos> temp;
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            Backtraking_Elementos temp2;
            temp2.Soluciones = this->Casillas.at(i).at(j)->text();
            if(this->Casillas.at(i).at(j)->text() == ""){
                temp2.Control = -1;
            }
            else{
                temp2.Control = 1;
            }
            temp.append(temp2);
        }
        Soluciones.append(temp);
    }
    for(int i = 0 ; i < int(this->NodosIniciales.size()) ; i++){
        if(this->NodosIniciales[i].Inicio.PosX == this->NodosIniciales[i].Fin.PosX){
            if((this->NodosIniciales[i].Inicio.PosY-this->NodosIniciales[i].Fin.PosY == 1)or(this->NodosIniciales[i].Inicio.PosY-this->NodosIniciales[i].Fin.PosY == -1)){
                Soluciones[this->NodosIniciales[i].Inicio.PosY][this->NodosIniciales[i].Inicio.PosX].Control = 0;
                Soluciones[this->NodosIniciales[i].Fin.PosY][this->NodosIniciales[i].Fin.PosX].Control = 0;
            }
        }
        else{
            if(this->NodosIniciales[i].Inicio.PosY == this->NodosIniciales[i].Fin.PosY){
                if((this->NodosIniciales[i].Inicio.PosX-this->NodosIniciales[i].Fin.PosX == 1)or(this->NodosIniciales[i].Inicio.PosX-this->NodosIniciales[i].Fin.PosX == -1)){
                    Soluciones[this->NodosIniciales[i].Inicio.PosY][this->NodosIniciales[i].Inicio.PosX].Control = 0;
                    Soluciones[this->NodosIniciales[i].Fin.PosY][this->NodosIniciales[i].Fin.PosX].Control = 0;
                }
            }
        }

    }
    Backtraking(Soluciones,0,0);
}

int NumberLink::getRespuestaCantDesachada()
{
    return this->Respuesta.CantDesechada;
}

int NumberLink::getRespuestaCantContruidas()
{
    return this->Respuesta.CantContruidas;
}

int NumberLink::getRespuestaProfundidad()
{
    return this->Respuesta.Profundidad;
}

void NumberLink::Voraz()
{
    QVector <Link> NodosIniciales = this->NodosIniciales;
    QVector <QVector <Link> > NodosInicialesArray;
    this->Respuesta.CantContruidas = 0;
    this->Respuesta.Profundidad = 0;
    this->Respuesta.CantDesechada = 0;
    this->Respuesta.NivelAlternativaDesechada.clear();
    //lenar matriz de soluciones y control, -1 para indicar que no hay numeros.
    for(int i=0 ; i < int(this->Casillas.size()) ; i++){
        QVector <Backtraking_Elementos> temp;
        for (int j=0 ; j < int(this->Casillas.size()) ; j++){
            Backtraking_Elementos temp2;
            temp2.Soluciones = this->Casillas.at(i).at(j)->text();
            if(this->Casillas.at(i).at(j)->text() == ""){
                temp2.Control = -1;
            }
            else{
                temp2.Control = 1;
            }
            temp.append(temp2);
        }
        Soluciones.append(temp);
    }
    for(int i = 0 ; i < int(NodosIniciales.size()) ; i++){
        if(NodosIniciales[i].Inicio.PosX == NodosIniciales[i].Fin.PosX){
            if((NodosIniciales[i].Inicio.PosY-NodosIniciales[i].Fin.PosY == 1)or(NodosIniciales[i].Inicio.PosY-NodosIniciales[i].Fin.PosY == -1)){
                Soluciones[NodosIniciales[i].Inicio.PosY][NodosIniciales[i].Inicio.PosX].Control = 0;
                Soluciones[NodosIniciales[i].Fin.PosY][NodosIniciales[i].Fin.PosX].Control = 0;
            }
        }
        else{
            if(NodosIniciales[i].Inicio.PosY == NodosIniciales[i].Fin.PosY){
                if((NodosIniciales[i].Inicio.PosX-NodosIniciales[i].Fin.PosX == 1)or(NodosIniciales[i].Inicio.PosX-NodosIniciales[i].Fin.PosX == -1)){
                    Soluciones[NodosIniciales[i].Inicio.PosY][NodosIniciales[i].Inicio.PosX].Control = 0;
                    Soluciones[NodosIniciales[i].Fin.PosY][NodosIniciales[i].Fin.PosX].Control = 0;
                }
            }
        }

    }
    NodosIniciales.clear();
    for(int i=0 ; i < int(Soluciones.size()) ; i++){
        for(int j=0 ; j < int(Soluciones.size()) ; j++){
            if((Soluciones[i][j].Soluciones != "")and(Soluciones[i][j].Control == 1)){
                Link temp;
                temp.Dato = Soluciones[i][j].Soluciones;
                temp.Inicio.PosX = j;
                temp.Inicio.PosY = i;
                NodosIniciales.append(temp);
            }
        }
    }
    QVector < QVector <QVector <Backtraking_Elementos> > > Convinaciones;
    Convinaciones.push_back(Soluciones);
    NodosInicialesArray.push_back(NodosIniciales);
    while(int(Convinaciones.size())>0){
        Soluciones = Convinaciones.first();
        NodosIniciales = NodosInicialesArray.first();
        NodosInicialesArray.pop_front();
        if(Verificar(Soluciones)){
            Respuesta.CantContruidas++;
            for(int i=0 ; i< int(this->Casillas.size()) ; i++){
                for(int j=0 ; j < int(this->Casillas.size()) ; j++){
                    this->Casillas[i][j]->setText(Soluciones[i][j].Soluciones);
                }
            }
        }
        else{
            if(int(NodosIniciales.size())==0){
                NodosIniciales.clear();
                for(int i=0 ; i < int(Soluciones.size()) ; i++){
                    for(int j=0 ; j < int(Soluciones.size()) ; j++){
                        if((Soluciones[i][j].Soluciones != "")and(Soluciones[i][j].Control == 1)){
                            Link temp;
                            temp.Dato = Soluciones[i][j].Soluciones;
                            temp.Inicio.PosX = j;
                            temp.Inicio.PosY = i;
                            NodosIniciales.append(temp);
                        }
                    }
                }
            }
            Link temp;
            temp = NodosIniciales.first();
            NodosIniciales.pop_front();
            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control == 0){
                Convinaciones.push_back(Soluciones);
                NodosInicialesArray.push_back(NodosIniciales);
            }
            else{
                if(temp.Inicio.PosY-1 >= 0){
                    if(Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones == ""){
                        Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control = 0;
                        Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones = temp.Dato;
                        Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Control = 2;
                        Link temp_origen = temp;
                        temp.Inicio.PosY-=1;
                        if(temp.Inicio.PosY-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosY+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        temp = temp_origen;
                        Convinaciones.push_back(Soluciones);
                        NodosInicialesArray.push_back(NodosIniciales);
                        Soluciones = Convinaciones.first();
                    }
                }
                if(temp.Inicio.PosY+1 < int(Soluciones.size())){
                    if(Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones == ""){
                        Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones = temp.Dato;
                        Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Control = 2;
                        Link temp_origen = temp;
                        temp.Inicio.PosY+=1;
                        if(temp.Inicio.PosY-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosY+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        temp = temp_origen;
                        Convinaciones.push_back(Soluciones);
                        NodosInicialesArray.push_back(NodosIniciales);
                        Soluciones = Convinaciones.first();
                    }
                }
                if(temp.Inicio.PosX-1 >= 0){
                    if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones == ""){
                        Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones = temp.Dato;
                        Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Control = 2;
                        Link temp_origen = temp;
                        temp.Inicio.PosX-=1;
                        if(temp.Inicio.PosY-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosY+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        temp = temp_origen;
                        Convinaciones.push_back(Soluciones);
                        NodosInicialesArray.push_back(NodosIniciales);
                        Soluciones = Convinaciones.first();
                    }
                }
                if(temp.Inicio.PosX+1 < int(Soluciones.size())){
                    if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones == ""){
                        Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones = temp.Dato;
                        Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Control = 2;
                        Link temp_origen = temp;
                        temp.Inicio.PosX+=1;
                        if(temp.Inicio.PosY-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY-1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosY+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY+1][temp.Inicio.PosX].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX-1 >= 0){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX-1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        if(temp.Inicio.PosX+1 < int(Soluciones.size())){
                            if(Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Soluciones == temp.Dato){
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX+1].Control--;
                                Soluciones[temp.Inicio.PosY][temp.Inicio.PosX].Control--;
                            }

                        }
                        temp = temp_origen;
                        Convinaciones.push_back(Soluciones);
                        NodosInicialesArray.push_back(NodosIniciales);
                        Soluciones = Convinaciones.first();
                    }
                }
            }
        }
        Convinaciones.pop_front();
    }

}

QVector<int> NumberLink::getrespuestanivelAlternativaDesechada()
{
    return this->Respuesta.NivelAlternativaDesechada;
}

void NumberLink::Colorear()
{
    for(int i = 0 ; i < int(this->Casillas.size()) ; i++){
        for(int j = 0 ; j < int(this->Casillas.size()) ; j++){
            for(int z = 0 ; z < int(this->NodosIniciales.size()) ; z++){
                if(this->Casillas[i][j]->text() == this->NodosIniciales[z].Dato)
                {
                    if(z < int(this->Colores.size())){
                        this->Casillas[i][j]->setStyleSheet(this->Colores[z]);
                    }
                    z = int(this->NodosIniciales.size());
                }
            }
        }
    }
}

void NumberLink::ArchivoSalida()
{
       //QFile file(Nombre_Archivo);
       QFile file("SALIDA.txt");
       file.open(QIODevice::WriteOnly | QIODevice::Text);
       QTextStream out(&file);
       QString text ="";
       text = QString::number(int(this->Casillas.size()))+"\n";
       for(int i = 0 ; i < int(this->Casillas.size()) ; i++){
           for(int j = 0; j < int(this->Casillas.size()) ; j++){
               text+=this->Casillas[i][j]->text();
           }
           text+="\n";
       }
       out << text.toStdString().c_str();

       // optional, as QFile destructor will already do it:
       file.close();
}



