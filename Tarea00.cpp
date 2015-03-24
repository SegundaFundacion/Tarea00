#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <ctime>
#include <sstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

std::string fechaHora()
{
     string dS[7] = {"Domingo","Lunes","Martes","Miercoles", "Jueves","Viernes","Sabado"};
time_t tSac = time(NULL); // instante actual
 
struct tm* tmP = localtime(&tSac);
// cout << tmP->tm_year+1900 << "-" << tmP->tm_mon+1 << "-" << tmP->tm_mday <<" "<< tmP->tm_hour << ":" << tmP->tm_min << ":" << tmP->tm_sec << endl;
 
std::stringstream ss;
     ss << tmP->tm_year+1900 << "-" << tmP->tm_mon+1 << "-" << tmP->tm_mday <<" "<< tmP->tm_hour << ":" << tmP->tm_min << ":" << tmP->tm_sec;
     std::string s = ss.str();
return s;
} 

string genumal(int max,int gen){
   vector<int> num;
   string numazar;
   stringstream out;
   for(int i=1;i<max;i++){
          num.push_back(i);
       }
  for(int i=1;i<=gen;i++){
      if(num.size()>0){
          int indice = rand()%num.size();
          out<<";"<<num[indice];
          numazar=out.str();
          num.erase(num.begin()+indice);
          }
      }
      return numazar;
}

int main()
{
    const time_t timer = time(NULL);
ofstream entrada;
 
    char selection,v,g;
    string aux= fechaHora();
     srand(time(0));

    do
    {
        cout << "  Programa Qno!!!\n";
        cout << "  ====================================\n";
        cout << "  g.  Ingrese una simulacion al fichero\n";
        cout << "  v.  Integrantes y fecha de compilacion\n";
        cout << "  ====================================\n";
        cout << "  Ingresa tu opcion: ";
        cin >> selection;
        cout << endl;
  

        switch (selection)
        {
            case 'g':
                 entrada.open("Sorteo Qno.csv", ios::app);
if(entrada.fail()){
cout<<"ocurrio un error al abrir o crear el fichero";
 return 1;
 
  }
  else
                entrada<<fechaHora()<<genumal(25,14)<<endl;
                //rand(time(NULL));
                entrada.close();
               
                break;
               
            case 'v':
    cout<<"+-------------------------------------------------------------------------+"<<endl;                 
    cout<<"|  INTEGRANTES                                                            |"<<endl;
    cout<<"+-------------------------------------------------------------------------+"<<endl;
    cout<<"| Franco Morales Barcelo.                                                 |"<<endl;
    cout<<"| Cesar Miranda Guajardo.                                                 |"<<endl; 
    cout<<"| Cristobal Herrera Fuenzalida.                                           |"<<endl;           
    cout<<"+-------------------------------------------------------------------------+"<<endl;
    cout << "Fecha y Hora del Sistema: "<<aux;
    return 0;
                break;   
           
}  
               
               
}while (selection != 3);
}
