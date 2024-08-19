#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocaçao de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável pelas strings


int registro(){ //função responsável por resgistrar novos usuários
	
	// início da definição das variáveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//final da definição das variáveis
	
	
	printf("Digite o cpf a ser cadastrado: ");//texto informativo de comando ao usuário
	scanf("%s", cpf);//para pegar a informação digitada pelo usuário
	
	strcpy(arquivo,cpf); // para copiar os valores das strings
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo, "w" para "escrever"
	fprintf(file,cpf); // salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");// abrir arquivo, "a" atualizar arquivo
	fprintf(file,",");//atualizar o arquivo, adiciona uma vírgula para separar as informações
	fclose(file);//fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");//texto informativo de comando para o usuário
	scanf("%s",nome);// para escanear a informação digitada pela usuário
	
	file = fopen(arquivo,"a");// abrir arquivo, "a" para atualizar o arquivo
	fprintf(file,nome);// adicionar a variável "nome"
	fclose(file);// fechar o arquivo
	
	file = fopen(arquivo,"a");// abrir o arquivo, "a" atualizar arquivo
	fprintf(file,"_");// adicionar espaço entre os dados armazenados
	fclose(file);// fechar arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");// informação de comando para o usuário
	scanf("%s",sobrenome); // para pegar a informação digitada pelo usuário
	
	file = fopen(arquivo,"a");// abrir arquivo e atualziar 
	fprintf(file,sobrenome);// adicionar variável "sobrenome"
	fclose(file);// fechar arquivo
	
	file = fopen(arquivo,"a");// abrir arquivo e atualizar
	fprintf(file,", ");// adicionar ao arquivo
	fclose(file); // fechar arquivo
	
	printf("Digite o cargo a ser cadastrado: ");// informar o comando ao usuário
	scanf("%s",cargo);// pegar os dados digitados pelo usuário
	
	file = fopen(arquivo,"a");// abrir arquivo e atualizar
	fprintf(file,cargo);// adicionar variável "cargo"
	fclose(file);// fechar o arquivo
	
	system("pause");
	
} //fechamento da função registro()



int consulta(){ // função responsável por realiar a consulta de usuários
	
	setlocale(LC_ALL,"Portuguese");// definição da localização
	
	//iniício da definição das variáveis
	char cpf[40];
	char conteudo[200];
	
	int escolha = 0;
	// final da definição das variáveis
	
	system("cls");// para limpar a tela
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);// para pegar a escolha digitada pelo usuário
	
	FILE *file;// abrir arquivo
	file = fopen(cpf,"r");// abrir arquivo, "r" ler o arquivo
	
	if(file == NULL){// se a opção for igual a nulo, não existir
		printf("\nCPF não localizado! Não foi possível abrir o arquivo!\n\n");
		// informar que os dados não foram encontrados
		// logo abaixo dar a opção de realisar outra pesquisa ou voltar ao menu
		printf("Deseja realizar outra consulta?\n");
		printf("\t1 - SIM\n");// opção
		printf("\t2 - VOLTAR AO MENU\n");// opção
		
		scanf("%d", &escolha);// pegar opção do usuário
		
		if(escolha == 1){// se a escolha for 1, retornar a nova consulta
			consulta();
		}
		
		if(escolha == 2){// se a opção for 2, retornar ao menu
			main();
		}
		
	}
	
	while(fgets(conteudo,200,file) != NULL	){
		printf("\nEssas são as informações do usuário:\n\n");
		printf("%s",conteudo);// mostra informações dos dados pesquisados
		printf("\n\n");//quebra de linha
		// após dar a opção de realizar nova pesquisa ou voltar ao menu
		printf("Deseja realizar outra consulta?\n");
		printf("\t1 - SIM\n");// opção 1
		printf("\t2 - VOLTAR AO MENU\n");// opção 2
		
		scanf("%d", &escolha);// pega opção do usuário
		
		if(escolha == 1){// se a escolha for 1, realizar nova consulta
			consulta();
		}
		
		if(escolha == 2){// se a escolha por 2, voltar ao menu
			main();
		}
		
		
	}
	
	fclose(file);
	
	system("pause");
	
}// fechamento da função consulta


int deletar(){ //função responsável por excluir dados de usuário
	
	char cpf[40];// definição de variável
	
	printf("Digite o CPF a ser deletado: ");// informação de comando ao  usuário
	scanf("%s",cpf);// pegar a informação digitada pelo usuário
	
	remove(cpf);// deletar o arquivo
	
	FILE *file;//abrir o arquivo
	file = fopen(cpf, "r");// abrir e ler o arquivo
	
	if(file == NULL){// cado os dados não sejam encontrados
		printf("Usuário não consta no sistema!\n");
		//informar ao usuário que os dados não existem
		system("pause");
	}
	
	fclose(file);//para fechar o arquivo
} //fechamento da função deletar()

int main(){ //função principal
	
	int opcao=0; // definição da variável
	int laco=1; // definição de variável
	
	for(laco=1;laco=1;){// início do laço de repetição
		
		system("cls"); // para limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); // definição da linguagem
	
		printf("### Cartório da EBAC ###\n\n"); // início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar Nome\n");
		printf("\t2 - Consultar Nome\n");
		printf("\t3 - Deletar Nome\n");
		printf("\t4 - Sair e fechar programa\n\n");
		printf("Opção: "); // final do menu
	
		scanf("%d", &opcao); // usado para armazenar a opção do usuário
	
		system("cls"); // usado para limpar a tela
		
		switch(opcao){
			case 1:// caso o usuário digite 1 ir para a tela de registrar
			registro();
			break;
			
			case 2:// caso o usuário digite 2 ir para a página de consulta
			consulta();	
			break;
			
			case 3:// caso o usuário digite 3 ir para a página de deletar
			deletar();	
			break;
			
			case 4:// caso o usuário digite 4 fechar o programa
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:// caso o usuário digite qualquer tecla diferente das anteriores
				printf("Opção inválida!\n");
				// passar essa informação ao usuário
				system("pause");
				break;
				
		}// fim do switch 
	
	} // fim do for
} //fechamento do main()
