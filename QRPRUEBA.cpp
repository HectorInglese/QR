#include <string.h>
#include<conio.h>
#include<stdlib.h>
#include <iostream>
#include<math.h>

using namespace std;

//Prototipo 
void OP();
void DEL();


//Variables
float **matrizA , **matrizQ , **matrizR , sum, sum2;
int nR , nC ;

int main(){
	
	OP();
	
DEL();
getch();
return 0;
}



void OP(){

	nR = 3;
	nC = 3;
	

	matrizA =new float*[nR];
	matrizQ =new float*[nR];
	matrizR =new float*[nR];
	for (int i=0;i<nR;i++){
		matrizA[i] = new float[nC];
		matrizQ[i] = new float[nC];
		matrizR[i] = new float[nC];
	}
	
	float matrizA[3][3] = { 
            				{12, -51, 4},
           					{6, 167, -68},
        					{-4, 24, -41}
        					};


	for(int j=0; j<nR; j++){
		sum = 0;
		sum2 = 0;		
		for(int i=0; i<nC; i++){	
			if (j == 0 ){ matrizQ[i][j] = matrizA[i][j]; }
			else if (j != 0 ){
				sum = sum + matrizA[i][j] * matrizQ[i][j-1] ;
				sum2 = sum2 + matrizQ[i][j-1] * matrizQ[i][j-1];	
			}
			for(int i=0; i<nC; i++){	
			if (j == 0 ){ matrizQ[i][j] = matrizA[i][j]; }
			else if (j != 0 ){
				matrizQ[i][j] =  matrizA[i][j] - ((sum/sum2)* matrizQ[i][j-1]); 	
			}		
			}					
		}		
	}
	
cout<<"\n\nMatriz Q = \n";	
for(int i=0; i<nR; i++){
	for(int j=0; j<nC; j++){

			printf(" %6.2f ",matrizQ[i][j]); 	
			}
		cout<<"\n";		
	}

}

void DEL(){
	
	cout<<"\n\n\n\tSALIR";
	for(int i=0;i<nR;i++){		
		delete[] matrizA[i];
		delete[] matrizQ[i];
	}
	delete[] matrizA;
	delete[] matrizQ;
	
}



