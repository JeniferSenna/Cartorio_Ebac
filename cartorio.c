#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca�ao de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel pelas strings


int registro(){ //fun��o respons�vel por resgistrar novos usu�rios
	
	// in�cio da defini��o das vari�veis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da defini��o das vari�veis
	
	
	printf("Digite o cpf a ser cadastrado: ");//texto informativo de comando ao usu�rio
	scanf("%s", cpf);//para pegar a informa��o digitada pelo usu�rio
	
	strcpy(arquivo,cpf); // para copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" para "escrever"
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");// abrir arquivo, "a" atualizar arquivo
	fprintf(file,",");//atualizar o arquivo, adiciona uma v�rgula para separar as informa��es
	fclose(file);//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//texto informativo de comando para o usu�rio
	scanf("%s",nome);// para escanear a informa��o digitada pela usu�rio
	
	file = fopen(arquivo,"a");// abrir arquivo, "a" para atualizar o arquivo
	fprintf(file,nome);// adicionar a vari�vel "nome"
	fclose(file);// fechar o arquivo
	
	file = fopen(arquivo,"a");// abrir o arquivo, "a" atualizar arquivo
	fprintf(file,"_");// adicionar espa�o entre os dados armazenados
	fclose(file);// fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// informa��o de comando para o usu�rio
	scanf("%s",sobrenome); // para pegar a informa��o digitada pelo usu�rio
	
	file = fopen(arquivo,"a");// abrir arquivo e atualziar 
	fprintf(file,sobrenome);// adicionar vari�vel "sobrenome"
	fclose(file);// fechar arquivo
	
	file = fopen(arquivo,"a");// abrir arquivo e atualizar
	fprintf(file,", ");// adicionar ao arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// informar o comando ao usu�rio
	scanf("%s",cargo);// pegar os dados digitados pelo usu�rio
	
	file = fopen(arquivo,"a");// abrir arquivo e atualizar
	fprintf(file,cargo);// adicionar vari�vel "cargo"
	fclose(file);// fechar o arquivo
	
	system("pause");
	
} //fechamento da fun��o registro()



int consulta(){ //fun��o respons�vel por mostrar a pesquisa da cosulta de usu�rio
	
	setlocale(LC_ALL,"Portuguese");// para definir a linguagem
	
	char cpf[40];// definindo as vari�veis
	char conteudo[300];// definindo as vari�veis
	
	printf("Digite o CPF que deseja consultar: ");//informa��o de comando para o usu�rio
	scanf("%s",cpf);// respons�vel por pegar a informa��o digitada pelo usu�rio
	
	FILE *file;// abrir arquivo
	file = fopen(cpf,"r");// abrir arquivo e ler
	
	if(file == NULL){// se o arquivo for igual a nulo (n�o existir)
		printf("CPF n�o localizado! N�o foi poss�vel abrir o arquivo!\n");
		//informar ao usu�rio que os dados digitados n�o existem
		system("pause");
	}
	
	while(fgets(conteudo,200,file) != NULL){//caso os dados sejam encontrados
		printf("\nEssas s�o as informa��es do usu�rio: \n");//informar dados ao usu�rio
		printf("%s",conteudo);//informa��o de dados ao usu�rio
		printf("\n");	
		
	}
	
	fclose(file);//fechamento do arquivo
	
	system("pause");
	
} // fechamento da fun��o consulta()


int deletar(){ //fun��o respons�vel por excluir dados de usu�rio
	
	char cpf[40];// defini��o de vari�vel
	
	printf("Digite o CPF a ser deletado: ");// informa��o de comando ao  usu�rio
	scanf("%s",cpf);// pegar a informa��o digitada pelo usu�rio
	
	remove(cpf);// deletar o arquivo
	
	FILE *file;//abrir o arquivo
	file = fopen(cpf, "r");// abrir e ler o arquivo
	
	if(file == NULL){// cado os dados n�o sejam encontrados
		printf("Usu�rio n�o consta no sistema!\n");
		//informar ao usu�rio que os dados n�o existem
		system("pause");
	}
	
	fclose(file);//para fechar o arquivo
} //fechamento da fun��o deletar()

int main(){ //fun��o principal
	
	int opcao=0; // defini��o da vari�vel
	int laco=1; // defini��o de vari�vel
	
	for(laco=1;laco=1;){// in�cio do la�o de repeti��o
		
		system("cls"); // para limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // defini��o da linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar Nome\n");
		printf("\t4 - Sair e fechar programa\n\n");
		printf("Op��o: "); // final do menu
	
		scanf("%d", &opcao); // usado para armazenar a op��o do usu�rio
	
		system("cls"); // usado para limpar a tela
		
		switch(opcao){
			case 1:// caso o usu�rio digite 1 ir para a tela de registrar
			registro();
			break;
			
			case 2:// caso o usu�rio digite 2 ir para a p�gina de consulta
			consulta();	
			break;
			
			case 3:// caso o usu�rio digite 3 ir para a p�gina de deletar
			deletar();	
			break;
			
			case 4:// caso o usu�rio digite 4 fechar o programa
			printf("Obrigada por utilizar o sistema!\n");
			return 0;
			break;
			
			default:// caso o usu�rio digite qualquer tecla diferente das anteriores
				printf("Op��o inv�lida!\n");
				// passar essa informa��o ao usu�rio
				system("pause");
				break;
				
		}// fim do switch 
	
	} // fim do for
} //fechamento do main()
