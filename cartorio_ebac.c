#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Bilbioteca de aloca��o de espa�o e mem�ria
#include <locale.h> //Biblioteca respons�vel por aloa��o de texto regi�o
#include <string.h> //Biblioteca respons�vel pela string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Inic�o da cria��o das varia�veis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//Final da cria��o das varia�veis/string
	
	printf("Digite CPF a ser cadastrado: "); // coletando as informa��es do usu�rio
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // Cria arquivo
	file = fopen(arquivo, "w"); // Cria arquivo e "w" significa escrever
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome para cadastro: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome para cadastro: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo para cadastro: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	char cpf[50];
	char conteudo[200];
	
	setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
	printf("Digite o cpf para consulta: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o existente!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)	
	{
		printf("\nInforma��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[50];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado.\n");
		system("pause");
	}
}

int main()
{

	int opcao=0; // Definindo as Variav�is
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls"); //respons�vel por limpar a tela do usu�rio
		
		setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
		printf("\t Cart�rio da EBAC\n\n"); // In�cio do menu
		printf("Escolha a op��o desejada no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); // Final do menu
			
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
		
		system("cls");
		
		switch(opcao)
		{
			case 1:   // inicio da sele��o do menu
			registro();
			break;
		
			case 2:		
			consulta();	
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:			
			printf("Op��o indispon�vel!\n"); 
			system("pause");
			break; 
			// Fim da sele��o
		}

		
	}	
}


