#include <iostream>
#include <wchar.h>
#include <locale.h>

using namespace std;

double determinante(double array[2][2]) {		//Determinante de la matriz de cofactores.
	double resultado=0;
	resultado=array[0][0]*array[1][1]-array[0][1]*array[1][0];
	return resultado;	
}

int main() {
	
	setlocale(LC_ALL, "spanish");
	
	double matriz_principal[3][3];		//Creación de arreglos bidimensionales (matrices).
	double matriz_cofactores[2][2];
	double matriz_adjunta[3][3];
	double matriz_transpuesta[3][3];
	double matriz_determinante[5][3];
	double dato_1=0, dato_2=0, determinante_3x3=0;	
	
	for(int i=0; i<=2; i++) {		//Solicitud y registro de datos en la matriz principal.
		for(int j=0; j<=2; j++) {
			cout<<"Ingrese el dato "<<j+1<<" de la fila "<<i+1<<" : ";
			cin>>matriz_principal[i][j];
		}
	}	
	
	cout<<endl;
	
	for(int i=0; i<=2; i++) {		//Clonado de la matriz principal a la matriz determinante.
		for(int j=0; j<=2; j++) {
			matriz_determinante[i][j]=matriz_principal[i][j];			
		}
	}
	for(int i=3; i<=4; i++) {		//Registro de datos adicionales en la matriz determinante.
		for(int j=0; j<=2; j++) {
			matriz_determinante[i][j]=matriz_principal[i-3][j];			
		}
	}	
	
	//SARRUS - Determinante matriz 3x3:

	for(int j=0; j<=2; j++) {
		dato_1+=(matriz_determinante[j][0]*matriz_determinante[1+j][1]*matriz_determinante[2+j][2]);
	}	
	
	for(int j=0; j<=2; j++) {
		dato_2+=(matriz_determinante[j][2]*matriz_determinante[1+j][1]*matriz_determinante[2+j][0]);
	}	
	
	determinante_3x3=dato_1-dato_2;
	
	//CÁLCULO DE LA MATRIZ ADJUNTA:
	
	for(int i=0; i<=2; i++) {		//Primer recorrido de la matriz principal.
		for(int j=0; j<=2; j++) {
					
			int m=0, n=0;		//Posiciones de la matriz de cofactores.
					
			for(int k=0; k<=2; k++) {		//Segundo recorrido de la matriz principal. 
				for(int l=0; l<=2; l++) {
						
					if(k!=i && l!=j) {		//Comparación de posiciones entre recorridos. 
						matriz_cofactores[m][n]=matriz_principal[k][l];		//Registro de valores en la matriz de cofactores.
						if(n<1) {
							n++;
						}
						else {
							n=0;
							m++;
						}
					}					
							
				}
			}
			
			if(((i+j) % 2) == 0) {		//Asignación de signo al elemento final de la matriz adjunta.
				matriz_adjunta[i][j]=determinante(matriz_cofactores);
			}
			else {
				matriz_adjunta[i][j]=-determinante(matriz_cofactores);
			}		
			
		}
	}
	
	//REGISTRO DE DATOS EN LA MATRIZ TRANSPUESTA:
	
	for(int i=0; i<=2; i++) {
		for(int j=0; j<=2; j++) {
			matriz_transpuesta[i][j]=(1/determinante_3x3)*matriz_adjunta[j][i];		//Multiplicación de 1/Determinante a la matriz transpuesta.
		}
	}
	
	//IMPRESIÓN DE LA MATRIZ INVERSA:
	
	for(int i=0; i<=2; i++) {
		for(int j=0; j<=2; j++) {
			cout<<matriz_transpuesta[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
	
}
