#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacao de texto por regiao
#include <string.h> //biblioteca respondavel por cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobreNome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado\n\n");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das stings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");	//cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Dgite o sobrenome a ser cadastrado: ");
	scanf("%s", sobreNome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobreNome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese"); //selecionando linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O cpf não está registrado no banco de dados. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:\n\n ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
		system("pause");
		
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	remove(cpf);
	
	if (cpf == NULL)
	{
		printf("CPF não encontrado!. \n");
		system("pause");
	}	
}

int main()
{
	
	int opcao = 0; //definindo variáeis
	int laco = 1;
	
	for (laco == 1; laco == 1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "portuguese"); //selecionando linguagem
		printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opcao desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //coletando dados do usuario
	
		system("cls"); // limpando a caixa de dialogo
		
		switch(opcao)
		{
			case 1: 
				registro();
			break;
			
			case 2: 
				consulta();
			break;
			
			case 3: 
				deletar();
			break;
			
			default: 
				printf("Essa opção não existe, retone ao menu inicial.\n\n");
				system("pause");
			break;
			
		}

		//if (opcao == 1) //inicio das condicionais
		//{ 
		//	printf("Voce escolheu a opção de Registro de nomes\n\n");
		//	system("pause");
		//}
		//if (opcao == 2)
		//{
		//	printf("voce escolheu a opção de consulta de nomes\n\n");
		//	system("pause");
		//}
		//if (opcao == 3)
		//{
		//	printf("voce escolheu a opção de exclusão de cadastro\n\n");
		//	system("pause");
		//}
		//if (opcao >= 4 || opcao <= 0) 
		//{
		//	printf("Essa opção não existe, retone ao menu inicial.\n\n");
		//	system("pause");
		//} //fim das condicionais
	}
}



