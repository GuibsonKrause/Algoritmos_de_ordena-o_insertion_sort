#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Fabricante
{
	char nome[50];
	char nacionalidade[50];
	int ano;
}Fabricante;

void insertionSort(Fabricante *vetor, int n)
{
	Fabricante valor;
	int k, j;
	int i;
	for (i = 1; i < n; i++)
	{
		valor = vetor[i];
		k = 0;
		j = i - 1;
		while ((j >= 0) && (k == 0))
		{

			if (strcmp(valor.nome, vetor[j].nome) == 0)
			{
				if (strcmp(valor.nacionalidade, vetor[j].nacionalidade) == 0)
				{
					if (valor.ano < vetor[j].ano)
					{
						strcpy(vetor[j + 1].nome, vetor[j].nome);
						strcpy(vetor[j + 1].nacionalidade, vetor[j].nacionalidade);
						vetor[j + 1].ano = vetor[j].ano;
						j = j - 1;
					}
					else 
					{
						k = j + 1;
					}

				}
				else if (strcmp(valor.nacionalidade, vetor[j].nacionalidade) == -1)
				{
					strcpy(vetor[j + 1].nome, vetor[j].nome);
					strcpy(vetor[j + 1].nacionalidade, vetor[j].nacionalidade);
					vetor[j + 1].ano = vetor[j].ano;
					j = j - 1;
				}
				else 
				{
					k = j + 1;
				}
			}
			else if (strcmp(valor.nome, vetor[j].nome) == -1)
			{
				strcpy(vetor[j + 1].nome, vetor[j].nome);
				strcpy(vetor[j + 1].nacionalidade, vetor[j].nacionalidade);
				vetor[j + 1].ano = vetor[j].ano;
				j = j - 1;
			}
			else 
			{
				k = j + 1;

			}

		}
		vetor[k] = valor;
	}
}

void escreveVetor(Fabricante *vetor, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("vet[%d]\n Nome: %s\n Nacionalidade: %s\n Ano: %d\n\n\n", i, vetor[i].nome, vetor[i].nacionalidade, vetor[i].ano);
	printf("\n\n");
}

int main()
{
	Fabricante  vetor[5];

	strcpy(vetor[0].nome, "Ford");
	strcpy(vetor[0].nacionalidade, "Brasil");
	vetor[0].ano = 2000;

	strcpy(vetor[1].nome, "Fiat");
	strcpy(vetor[1].nacionalidade, "Brasil");
	vetor[1].ano = 1999;

	strcpy(vetor[2].nome, "Fox");
	strcpy(vetor[2].nacionalidade, "Colombia");
	vetor[2].ano = 1998;

	strcpy(vetor[3].nome, "Toyota");
	strcpy(vetor[3].nacionalidade, "Japao");
	vetor[3].ano = 1997;

	strcpy(vetor[4].nome, "Wolskwagen");
	strcpy(vetor[4].nacionalidade, "Coreia");
	vetor[4].ano = 1996;

	insertionSort(vetor, 5);
	escreveVetor(vetor, 5);
	system("pause");
	return 0;
}
