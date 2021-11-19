/*
 
 TITULO: PROTOTIPO DE AUTOMATIZACION DE BUSQUEDA DE VULNERABILIDADES PARA DEPENDENCIAS Y PAQUETES INSTALADOS EN CANAIMA

 SUSCERTE: VENCERT
 DIRECCION DE VENCERT
 AUTOR: MIGUEL MARQUEZ 
 CARACAS, NOVIEMBRE DEL 2021

 vulscancanaima.c V 1.0

 DESCRIPCION:

	En vista a la necesidad de contar con un sistema que 
automatizara la busqueda de vulnerabilidades en canaima la
dirección del vencert se ha decidido por elaborar este prototipo
sencillo en c para facilitar el proceso, el script utiliza
por ahora el programa "searchexploit" que busca exploits en la base
de datos de "exploitdb" para las  dependencias y paquetes. Se 
espera que el codigo fuente se expanda y pueda al menos tambien
buscar vulnerabilidades en las bases de datos de la CVE.

BUGS:

1.- modular el programa
2.- expandir y buscar vulnerabilidades en la base de datos de las CVE
3.- mejorar o generalizar la seleccion de columnas para los ficheros
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){

	int cont=0;
	char salida[1035];
	FILE *fichero= fopen("paquetesinstalados.txt",3.- "r");
	
	if(fichero == NULL)
		printf("\n\nERROR!! no existe el ficheroņ\n");
	else{
		
		while(fgets(salida, sizeof(salida), fichero) != NULL){//recorre el fichero en un ciclo
		
		
			if(cont >= 5){
			
				char cadena1[100]="";
				char cadena2[100]="";
				char cadena[200]="";
				char cadenab[200]="";
				
				//printf("%s", salida);
				
//---------------------------------------------------------------------------------------------------------------------------
				for(int i=4; i<strlen(salida); i++){// limpia y obtiene la segunda columna de la salida de dpkg -l
				
					if(salida[i] != ' ')
					 	sprintf(cadena1, "%s%c", cadena1, salida[i]);
					 	
					else{
						sprintf(cadena1, "%s%c", cadena1, '\0');
						break;
					}//else
				
				}//for
				
				//printf("%s\n", cadena1);
//---------------------------------------------------------------------------------------------------------------------------

				for(int i=43; i<strlen(salida); i++){// limpia y obtiene la tercera columna de dpkg la salida de dpkg -l
				
					//printf("%c-",salida[i]);
				
					if(salida[i] != ' ')
					 	sprintf(cadena2, "%s%c", cadena2, salida[i]);
					else{
			
						sprintf(cadena2, "%s%c", cadena2, '\0');
						break;
					}//else
				
				}//for
				//printf("%s\n", cadena2);
//---------------------------------------------------------------------------------------------------------------------------
				int indexp=-1;
				int index2p=-1;
				int contp=0;
				char cadena3[100]="";
				
				for(int i=0; i<strlen(cadena2); i++){//limpia la stercera columna y obtiene cadena de las versiones
				
					if(cadena2[i] == ':'){// obtiene el indice del caracter ':'
					
						index2p= i;
					}//if
					
					
					/*
					if(cadena2[i] == '-'  || cadena2[i] == '+'){
						break;
					}
					*/
					
					if(cadena2[i] == '.'){// contador de numeros de puntos que encuentra en la cadena
					
						contp++;
					}//if
					if(contp == 3){
					
						indexp= i;
						break;
					}//if
					
				}//for
			
				//printf("%d << valor contp\n\n", contp);
				for(int i=index2p+1; i<=strlen(cadena2); i++){
				
					if(cadena2[i] == '-'  || cadena2[i] == '+' || cadena2[i] == '~')//rompe el ciclo al coincidir con cualquiera de esos caracteres
						break;
					
					if(contp <= 2 || contp == 0)
						sprintf(cadena3, "%s%c", cadena3, cadena2[i]);
					else{//solo permite el primer y segundo punto
						if(i < indexp)
							sprintf(cadena3, "%s%c", cadena3, cadena2[i]);
						else
							break;
					
					}//if
					
				}//for
				
				//sprintf(cadena3, "%s%c", cadena3, '\0');

//---------------------------------------------------------------------------------------------------------------------------

				//printf(">>%s\n", cadena3);
				sprintf(cadena, "%s%s%s%c%s", cadena, "searchsploit ", cadena1,' ', cadena3);
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				printf("BUSQUEDA No %d: %s\n", (cont -4 ), cadena);
				printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
				system(cadena);//llama al sistema y utiliza el programa "searchsploit" para buscar exploit
				sleep(3);
				
//---------------------------------------------------------------------------------------------------------------------------

			}//if
			
			cont++;
		}//while
		
	}//if

}//main

