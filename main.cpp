/**
 * Alumno:……………………………….                    Fecha:……………………………
    1) Una agencia de reparto posee dos canales para recibir pedidos, uno es 
    la página web de la empresa y el otro un operador que atiende la línea 
    telefónica. La operatoria es que al finalizar el horario de toma de 
    pedidos (de 6.00hs a 12.00hs), se juntan todos los pedidos por orden 
    de llegada y se genera un listado único con los repartos del día. De 
    cada pedido se tiene la siguiente información:
    • Hora Pedido (hora en formato HHMM)
    • Codigo de cliente (numérico)
    • Tipo de paquete: (1-Liviano / 2-Medio / 3-Pesado)
    • Origen(texto)
    • Destino(texto)

La capacidad de reparto varía según cuántos móviles disponga la empresa en el 
momento y las horas que se dispongan para realizar repartos, por lo cual la 
cantidad máxima de pedidos que puede tener el listado unificado resultará de 
un cálculo: 
Pedidos_Max = Móviles * Horas_Reparto * 3

    a. Definir las estructuras necesarias para el enunciado descrito y para 
    los puntos siguientes:
    b. Realizar codificación de un procedimiento que reciba los pedidos de 
    ambos canales de atención y genere un listado de pedidos unificado a 
    atender y otro de los que no entran en el reparto diario por la capacidad 
    máxima.
    c. Realizar diagrama de un procedimiento que reciba el listado de pedidos 
    a realizar en el día y genere el siguiente listado agrupado por hora del pedido recibido:
HORA	LIVIANOS	MEDIO		PESADO	TOTAL X HORA
  6		2	        0		            1			         3
    d. Al finalizar el listado imprimir los siguientes datos de reporte:
TOTAL LIVIANOS: 99 	TOTAL MEDIO: 99	TOTAL PESADOS: 99
HORA CON MENOS ENVIOS: 13

Consideraciones: Los listados de ambos canales de atención se encuentran 
ordenados en forma ascendente por hora de pedido.
Restricciones: Solo se puede recorrer secuencialmente una vez cada vector
*/

/*
    • Hora Pedido (hora en formato HHMM)
    • Codigo de cliente (numérico)
    • Tipo de paquete: (1-Liviano / 2-Medio / 3-Pesado)
    • Origen(texto)
    • Destino(texto)*/


#include <iostream>

using namespace std;

const int TIPO_PAQUETE_LIVIANO = 1;
const int TIPO_PAQUETE_MEDIO   = 2;
const int TIPO_PAQUETE_PESADO  = 3;

const int MAX_CANTIDAD_PEDIDOS = 100;

struct PEDIDO
{
    int hora;
    long codigo_cliente;
    int tipo_paquete;
    string origen;
    string destino;
};

void apareo(PEDIDO vector1[], int n1, PEDIDO vector2[], int n2, PEDIDO vector3[], int &k){
    int i = 0, j = 0;
     k = 0;
     
    while(i < n1 && j < n2){
         if(vector1[i].hora < vector2[j].hora)
        {
            vector3[k++] = vector1[i++];
        }
        else if(vector1[i].hora > vector2[j].hora)
        {
            vector3[k++] = vector2[j++];
        }
        else
        {
            vector3[k++] = vector1[i];
            i++;
            j++;

        }

            //cout << vector3[k-1] << endl;


    }

    while(i < n1)
    {
        vector3[k++] = vector1[i++];
    }

    while(j < n2)
    {
        vector3[k++] = vector2[j++];
    }
}

int main()

{
    int pedidos_total;
    PEDIDO pedidos_web[MAX_CANTIDAD_PEDIDOS];
    PEDIDO pedidos_telefonicos[MAX_CANTIDAD_PEDIDOS];

    PEDIDO pedidos_unificado[MAX_CANTIDAD_PEDIDOS*2];

    int i = 0;
    pedidos_telefonicos[i].hora = 10;
    pedidos_telefonicos[i].tipo_paquete = 1;
    i++;
    pedidos_telefonicos[i].hora = 11;
    pedidos_telefonicos[i].tipo_paquete = 2;
    i++;
    pedidos_telefonicos[i].hora = 12;
    pedidos_telefonicos[i].tipo_paquete = 3;

    i = 0;
    pedidos_web[i].hora= 6;
    pedidos_web[i].tipo_paquete = 1;
    i++;
    pedidos_web[i].hora= 7;
    pedidos_web[i].tipo_paquete = 2;
    i++;
    pedidos_web[i].hora= 8;
    pedidos_web[i].tipo_paquete = 3;

    apareo(pedidos_telefonicos, MAX_CANTIDAD_PEDIDOS, pedidos_web, MAX_CANTIDAD_PEDIDOS, pedidos_unificado,pedidos_total);

    for(int i = 0; i < pedidos_total; i++)
    {
        cout << pedidos_unificado[i].hora << pedidos_unificado[i].tipo_paquete << endl;
    }


}



/**
    2) Realizar diagrama del procedimiento intersección que dados dos arreglos 
    de entrada uno de N y otro de M elementos genere un nuevo arreglo de 
    salida sólo con los elementos que  están en ambos conjuntos ordenado en 
    forma ascendente. 
Ejemplo: vecA = {0, 2, 4, 9} y vecB = {9, 5, 3, 2, 1) => vecC = {2, 9} 

Consideraciones: Ambos arreglos de entrada están ordenados pero el primero 
en forma ascendente y el segundo en forma descendente. Ambos son conjuntos 
sin elementos repetidos 
Restricciones: Sólo se puede recorrer una vez cada vector de entrada

 * 
 */
