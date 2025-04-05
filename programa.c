#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUMBER_TRY 5

int main(int argc, char const *argv[])
{
	printf("******************************************\n");
	printf("* Bem-vindo ao nosso jogo de adivinhacao *\n");
	printf("******************************************\n");
	

	int numberSecrete = 0;
	int seconds = time(0);
	srand(seconds);
	int n1 = rand();
	numberSecrete = n1 % 100;



	int chutePlayer = 0;
	int ganhou = 0;
	int tentativas = 1;
	float pontos = 1000;

	while(ganhou == 0)
	{	
		
		printf("QUAL O SEU CHUTE: ");
		scanf("%d", &chutePlayer);
		printf("SEU CHUTE FOI:  %d\n", chutePlayer);

		if(chutePlayer < 0){
			printf("VOCE NAO PODE CHUTAR NUMEROS NEGATIVOS\n");
			//i--;
			continue;
		}

		tentativas++;

		int acertou = (chutePlayer == numberSecrete);
		int maior = (chutePlayer > numberSecrete);	

		if(acertou){
			printf("Parabens Voce Acertou\n");
			printf("TENTATIVAS: %d \n",tentativas);
			ganhou = 1;
			break;
		}
		else if(maior)
		{
			printf("Voce Errou!!\n");
			printf("Seu chute foi maior\n");		
		}
		else {
			printf("Voce Errou!!\n");
			printf("Seu chute foi melhor\n");
		}

		double pontosPerdidos = abs(chutePlayer - tentativas) / (double) 2;
		pontos = pontos - pontosPerdidos;

	}
	
	printf("TOTAL DE PONTOS : %.1f\n",pontos);
	printf("FINAL DE JOGO!!");
}


