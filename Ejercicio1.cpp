/*
TITULO:PRACTICO 4
AUTOR: JUAN JESUS ROSALES SANDOVAL
DESCRICION:GENERAR UN PROGRAMA PARA REALIZAR EL SIGUIENTE MENÚ:
TENER VECTORES DE 10 ELEMENTOS PARA NOMBRE, APELLIDO, CONTRASEÑA Y NOTA.
FECHA:31/01/2024
https://github.com/jesusrosalessandoval/Practicos.git
*/
#include <iostream>
#include <iomanip> // Necesario para usar setw
using namespace std;

//Definimos variables globales y Definimos los vectores.
string nombres[] = {"Gabriel", "Andrea", "Diego", "Paola", "Eduardo", "Jesus", "Javier", "Jose", "Carlos", "Daniela"};
string apellidos[] = {"Perez", "Rosales ", "Lopez", "Sandoval", "Salvatierra", "Gonzalez", "Rodriguez", "Fernandez", "Sanchez", "Ramirez"};
string nombre[10];
string apellido[10];
string contrasena[10];
int nota[10];
char opcion;
int validador, mayor, menor,buscador_mayor, buscador_menor;
double promedio;


//Funciones
// Función para generar nombres aleatorios.
string generar_nombre()
{
    return nombres[rand()% 10];
}
// Función para generar apellidos aleatorios.
string generar_apellido()
{
    return apellidos[rand()% 10];
}
//DEFINIMOS LA FUNCION ofuscar.
string ofuscar(string contra)
{
    for(char&elemento: contra)
    {
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        if(tolower(elemento) == 'a')
        {
            elemento = '4';
        }
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        else if (tolower(elemento) == 'e')
        {
            elemento = '3';
        }
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        else if (tolower(elemento) == 'i')
        {
            elemento = '1';
        }
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        else if (tolower(elemento) == 'o')
        {
            elemento = '0';
        }
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        else if (tolower(elemento) == 's')
        {
            elemento = '5';
        }
        //se hace la comparacion con el caracter en minuscula y si es igual, se modifica.
        else if (tolower(elemento) == 't')
        {
            elemento = '7';
        }
    }
    return contra;
}
// Función para generar notas aleatorias.
int generar_notas()
{
    return rand()% 60 + 40;
}
// Función para generar nombres, apellidos y notas de forma aleatoria, evitando duplicados.
void generar_n_a_n()
{
    srand(time(NULL)); // Establece la semilla para rand
    for(int i= 0; i<10; i++)
    {
        nombre[i]=generar_nombre();
        apellido[i]=generar_apellido();
        nota[i]=generar_notas();
		// Verifica si hay duplicados en los nombres y apellidos, generando nuevos en caso necesario.
        for(int j = 0; j< i; j++)
        {
            if(nombre[j] == nombre[i] && apellido[j] == apellido[i])
            {
                nombre[i]=generar_nombre();
                apellido[i]=generar_apellido();
            }
        }
    }
}
// Función para ofuscar contraseñas utilizando los nombres y apellidos generados.
void ofuscar_contras()
{
    for (int i = 0; i < 10; i++)
    {
        contrasena[i]=ofuscar(nombre[i]+apellido[i]);
    }
}
// Función para calcular el promedio, la nota mayor y la nota menor.
void promedio_mayor_menor()
{
    menor = 100; //Se le asigna 100 por que es el rango maximo del generador de numeros.
    mayor = 40;//Se le asigna 40 por que es el rango minimo del generador de numeros.
    promedio=0;
    buscador_mayor = 0;
    buscador_menor = 0;
    for(int i = 0; i<10; i++)
    {
		// Actualiza la nota mayor y su posición.
        if(nota[i]> mayor)
        {
            mayor = nota[i];
            buscador_mayor = i;
        }
		// Actualiza la nota menor y su posición.
        if (nota[i]< menor)
        {
            menor = nota[i];
            buscador_menor = i;
        }
		// Calcula la suma de todas las notas.
        promedio += nota[i];
    }
	// Calcula el promedio dividiendo la suma de notas entre la cantidad de estudiantes.
    promedio = promedio / 10;
}
// Función para imprimir datos según la opción seleccionada.
void imprimir()
{
    if(validador == 1)
    {
        cout<<" -----------------------------\n";//Diseño
        cout<<"|"<<left<< setw(8)<<" NOMBRE"<<setw(3)<<"|"<<setw(10)<<"APELLIDO"<<setw(2)<<"|"<<setw(6)<<"NOTA"<<setw(2)<<"|"<<endl;
		//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
        cout<<" -----------------------------\n";//Diseño
        for (int i = 0; i < 10; i++)
        {
            cout<<"|"<< left << setw(10) << nombre[i]<< setw(15) << apellido[i]<< setw(5) << nota[i]<< "|" << "\n";
			//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
        }
        cout<<" -----------------------------\n"<<endl;


    }
    else if(validador == 2)
    {
        cout<<" -------------------------------------------------\n";//Diseño
        cout<<"|"<<left<< setw(8)<<" NOMBRE"<<setw(3)<<"|"<<setw(10)<<"APELLIDO"<<setw(2)<<"|"<<setw(6)<<"NOTA"<<setw(2)<<"|"<<setw(18)<<"CONTRASENA"<<"|"<<endl;
        //setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
		cout<<" -------------------------------------------------\n";//Diseño
        for (int i = 0; i < 10; i++)
        {
            cout<<"|"<< left << setw(10) << nombre[i]<< setw(15) << apellido[i]<< setw(5) << nota[i]<< setw(19) << contrasena[i] << "|" << "\n";
			//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
        }
        cout<<" -------------------------------------------------\n"<<endl;
    }
    else if (validador == 3)
    {
        cout<<" -------------------------------------------------\n";
        cout<<"|"<<left<< setw(8)<<" NOMBRE"<<setw(3)<<"|"<<setw(10)<<"APELLIDO"<<setw(2)<<"|"<<setw(6)<<"NOTA"<<setw(2)<<"|"<<setw(18)<<"CONTRASENA"<<"|"<<endl;
		//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
		cout<<" -------------------------------------------------\n";
        for (int i = 0; i < 10; i++)
        {
            cout<<"|"<< left << setw(10) << nombre[i]<< setw(15) << apellido[i]<< setw(5) << nota[i]<< setw(19) << contrasena[i] << "|" << "\n";
			//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
        }
        cout<<" -------------------------------------------------\n"<<endl<<endl;
		cout<<" -------------------------------------------------\n";
        cout<<"Promedio de nota es:"<<promedio<<"\t\t\t |"<<endl;
		cout<<" -------------------------------------------------\n";
        cout<<"Mayor\t\t\t\t\t\t |"<<endl;//\t es una tabulacion
        cout<< left << setw(10) << nombre[buscador_mayor]<< setw(15) << apellido[buscador_mayor]<< setw(5) << nota[buscador_mayor]<< setw(19) << contrasena[buscador_mayor]<<"|" <<endl;
		//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
		cout<<"Menor\t\t\t\t\t\t |"<<endl;//\t es una tabulacion
		//setw se utiliza para establecer el ancho de cada campo, y left indica que la alineación del texto es a la izquierda
		cout<< left << setw(10) << nombre[buscador_menor]<< setw(15) << apellido[buscador_menor]<< setw(5) << nota[buscador_menor]<< setw(19) << contrasena[buscador_menor]<<"|" <<endl;
		cout<<" -------------------------------------------------\n"<<endl<<endl;
    }
    
}
//funcion para mostrar el menu 
void menu()
{
	cout<<"\t\tMENU PRINCIPAL""\n";//\t es una tabulacion
    cout<<"(1)-Llenar nombres, apellidos y notas de forma aleatoria.""\n"; 
    cout<<"(2)-Ofuscar nombres y apellidos para llenar las contrasenas.""\n";
    cout<<"(3)-Sacar la media, el mayor y menor de todas las notas.""\n";
    cout<<"(4)-Imprimir datos.""\n";
    cout<<"(s/S)-Salir"<<endl;
}
// Función para solicitar al usuario que ingrese una opción del menú
char pedir_opcion()
{
    cout<<"Ingrese una opcion:";
    cin>>opcion;
    cout<<endl;
    return opcion = tolower(opcion);// Convierte la opción ingresada a minúsculas
}

int main()
{
    validador = 0;
    opcion=' ';
    do
    {
        menu();// Muestra el menú en la consola
        opcion = pedir_opcion();// Solicita al usuario que ingrese una opción
        if(opcion == '1')
        {
            generar_n_a_n();
            cout<<"Datos Cargados!!"<<endl<<endl;
            validador = 1;
        }
        else if (opcion == '2')
        {
            if(validador >= 1)
            {
                ofuscar_contras();
                cout<<"Contrasenas generadas"<<endl<<endl;
                validador = 2;
            }
            else
            {
                cout<<"Para generar contrasenas necesita cargar los datos primero!!!!"<<endl<<endl;
            }
        }
        else if (opcion == '3')
        {
            if(validador >= 2)
            {
                promedio_mayor_menor();
                cout<<"Datos Generados"<<endl<<endl;
                validador = 3;
            }
            else
            {
                cout<<"Para generar el promedio necesita cargar los datos primero!!!!"<<endl<<endl;
            }
        }
        else if (opcion == '4')
        {
            imprimir();
        }
        else if (opcion == 's')
        {
            cout<<"Saliendo del programa"<<endl;
        }
        
        else
        {
            cout<<"Opcion no valida"<<endl<<endl;
        }
        
    } while (opcion != 's');
    
    return 0;
}
