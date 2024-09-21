#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Bilbioteca de alocação de espaço e memória
#include <locale.h> //Biblioteca responsável por aloação de texto região
#include <string.h> //Biblioteca responsável pela string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	//Inicío da criação das variaáveis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//Final da criação das variaáveis/string
	
	printf("Digite CPF a ser cadastrado: "); // coletando as informações do usuário
	scanf("%s",cpf); // %s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	FILE *file; // Cria arquivo
	file = fopen(arquivo, "w"); // Cria arquivo e "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variável
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
		printf("Usuário não existente!\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)	
	{
		printf("\nInformações do usuário: ");
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
		printf("Usuário não encontrado.\n");
		system("pause");
	}
}

int main()
{

	int opcao=0; // Definindo as Variavéis
	int laco=1;

	for(laco=1;laco=1;)
	{
	
		system("cls"); //responsável por limpar a tela do usuário
		
		setlocale(LC_ALL, "portuguese"); // Definindo a Linguagem
	
		printf("\t Cartório da EBAC\n\n"); // Início do menu
		printf("Escolha a opção desejada no menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); // Final do menu
			
		scanf("%d", &opcao); // armazenando a escolha do usuário
		
		system("cls");
		
		switch(opcao)
		{
			case 1:   // inicio da seleção do menu
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
			printf("Opção indisponível!\n"); 
			system("pause");
			break; 
			// Fim da seleção
		}

		
	}	
}


