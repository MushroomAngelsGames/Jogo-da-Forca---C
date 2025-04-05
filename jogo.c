#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <stdlib.h>
#include <time.h>


char worldSecret[TAMANHO_PALAVRA];
char ChutesUsers[TAMANHO_PALAVRA];
int trys = 0;

// int* variable (*variable) é um ponteiro!

void EscolherPalavra(){

	FILE* f;
	f = fopen("E:/jogoC++/palavras.txt", "r");
	if (f == 0)
	{
		printf("BANCO DE DADOS NAO DISPONIVEL\n"  );
		exit(1);
	}


	int quantidadePalavras;
	fscanf(f,"%d", &quantidadePalavras);

	srand(time(0));
	int randomico = rand() % quantidadePalavras;

	for (int i = 0; i < randomico; ++i)
	{
		fscanf(f,"%s", worldSecret);
	}

	fclose(f);
}

void Abertura()
{
	printf("****************\n");
	printf(" Jogo de Forca *\n");
	printf("****************\n\n");
}

void Chutar(){
	char chute;
	scanf(" %c",&chute);
	ChutesUsers[trys] = chute;
	trys++;
}

int jaChutou(char letras){
	int achou = 0;
	for (int j = 0; j < trys; ++j)
	{	
		if(ChutesUsers[j] == letras){
			achou = 1;
			break;
		}
	}

	return achou;
}

void desenhaForca(){

	for (int i = 0; i < strlen(worldSecret); ++i)
	{		
		if(jaChutou(worldSecret[i])){
			printf("%c ", worldSecret[i]);
		}else{
			printf("_ "); 
		}
	}
	printf("\n");
}

int Inforcou(){
	int erros = 0;
	for (int i = 0; i < trys; ++i)
	{
		int existe = 0;
		for (int ie = 0; ie < strlen(worldSecret); ++ie)
		{
			if(ChutesUsers[i] == worldSecret[ie]){
				existe = 1;
				break;
			}
		}

		if(!existe) erros++;
	}



	return erros >= 5;
}

int Ganhou(){
	for (int i = 0; i < strlen(worldSecret); ++i)
	{
		if(!jaChutou(worldSecret[i]))
			return 0;
	}

	return 1;
}

void MainLogicGame(){

	do {

		desenhaForca();
		Chutar();
		
	} 
	while(!Ganhou() && !Inforcou());

	MostraGanhou();
}

void MostraGanhou(){
	printf(1);
	if(Ganhou()){
		printf("\nParabéns, você ganhou!\n\n");
		printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");
	}else{
		printf("\nPuxa, você foi enforcado!\n");
		printf("A palavra era **%s**\n\n", worldSecret);

		printf("    _______________         \n");
		printf("   /               \\       \n"); 
		printf("  /                 \\      \n");
		printf("//                   \\/\\  \n");
		printf("\\|   XXXX     XXXX   | /   \n");
		printf(" |   XXXX     XXXX   |/     \n");
		printf(" |   XXX       XXX   |      \n");
		printf(" |                   |      \n");
		printf(" \\__      XXX      __/     \n");
		printf("   |\\     XXX     /|       \n");
		printf("   | |           | |        \n");
		printf("   | I I I I I I I |        \n");
		printf("   |  I I I I I I  |        \n");
		printf("   \\_             _/       \n");
		printf("     \\_         _/         \n");
		printf("       \\_______/           \n");
	}
}

int main(int argc, char const *argv[])
{
	Abertura();	
	EscolherPalavra();
	MainLogicGame();
	return 0;
}



