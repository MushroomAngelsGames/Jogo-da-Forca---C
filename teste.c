#include<stdio.h>

int main(int argc, char const *argv[])
{
	
	printf("******************************************\n");
	printf("*              Bem-vindo                 *\n");
	printf("******************************************\n");

	int factorMultiplay = 10;
	int numberTabuada = 0;
	int count = 1;

	printf("QUAL A TABUADA: \n");
	scanf("%d", &numberTabuada);

	if(numberTabuada < 1 || numberTabuada > 99){
		printf("NUMERO FORA DO LIMITE : O LIMITE É 1 - 99 \n");
		return 0;
	}

	printf("A TABUADA DO %d E : \n", numberTabuada);

	while(count <= factorMultiplay){

		int resultado = count * numberTabuada;
		printf("%d X %d : %d \n", count,numberTabuada, resultado);
		count++;
	}

}