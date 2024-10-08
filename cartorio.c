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



int consulta(){ // fun��o respons�vel por realiar a consulta de usu�rios
	
	setlocale(LC_ALL,"Portuguese");// defini��o da localiza��o
	
	//ini�cio da defini��o das vari�veis
	char cpf[40];
	char conteudo[200];
	
	int escolha = 0;
	// final da defini��o das vari�veis
	
	system("cls");// para limpar a tela
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);// para pegar a escolha digitada pelo usu�rio
	
	FILE *file;// abrir arquivo
	file = fopen(cpf,"r");// abrir arquivo, "r" ler o arquivo
	
	if(file == NULL){// se a op��o for igual a nulo, n�o existir
		printf("\nCPF n�o localizado! N�o foi poss�vel abrir o arquivo!\n\n");
		// informar que os dados n�o foram encontrados
		// logo abaixo dar a op��o de realisar outra pesquisa ou voltar ao menu
		printf("Deseja realizar outra consulta?\n");
		printf("\t1 - SIM\n");// op��o
		printf("\t2 - VOLTAR AO MENU\n");// op��o
		
		scanf("%d", &escolha);// pegar op��o do usu�rio
		
		if(escolha == 1){// se a escolha for 1, retornar a nova consulta
			consulta();
		}
		
		if(escolha == 2){// se a op��o for 2, retornar ao menu
			main();
		}
		
	}
	
	while(fgets(conteudo,200,file) != NULL	){
		printf("\nEssas s�o as informa��es do usu�rio:\n\n");
		printf("%s",conteudo);// mostra informa��es dos dados pesquisados
		printf("\n\n");//quebra de linha
		// ap�s dar a op��o de realizar nova pesquisa ou voltar ao menu
		printf("Deseja realizar outra consulta?\n");
		printf("\t1 - SIM\n");// op��o 1
		printf("\t2 - VOLTAR AO MENU\n");// op��o 2
		
		scanf("%d", &escolha);// pega op��o do usu�rio
		
		if(escolha == 1){// se a escolha for 1, realizar nova consulta
			consulta();
		}
		
		if(escolha == 2){// se a escolha por 2, voltar ao menu
			main();
		}
		
		
	}
	
	fclose(file);
	
	system("pause");
	
}// fechamento da fun��o consulta


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
			printf("Obrigado por utilizar o sistema!\n");
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
