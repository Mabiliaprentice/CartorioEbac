#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocaçoes de texto por regiao
#include <string.h> //biblioteca de string


int registrar() //funcão responsável por cadastrar os ususarios.

{
	 //inicio da criação das variaveis/string
	 char arquivo[40]; //caracter tipo char, colchetes refere-se a uma variavel tipo string, de até 40 variaveis, nesse caso, aqui arquivo criado
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 //final da criação das variaveis/string
	 
	 printf("Digite o CPF a ser cadastrado: "); //pergunta feita ao ususario
	 scanf("%s", cpf); //armazena os dados dentro de uma string, %s.
	 
	 strcpy(arquivo, cpf); //responsável por copiar os valores das string 
	 
	 FILE *file; // cria o arquivo no banco de dados, acessa o file e cria o file.
	 file = fopen(arquivo, "w"); // abre o arquivo, a variavel arquivo, escreve, devido o write "W".
	 fprintf(file,cpf); // salva o valor da variavel no arquivo file
	 fclose(file); // depois de salvo, fecha-se o arquivo.
	 
	 file = fopen(arquivo, "a"); //arquivo sendo aberto novamente e "a" atualizando as informaçoes
	 fprintf(file, ","); // adiciona uma virgula no texto salvo no file no arquivo
	 fclose(file); //fecha o arquivo salvo.
	 
	 printf("Digite o Nome a ser cadastrado: "); // 
	 scanf("%s",nome); // salvar na string
	 
	 file = fopen(arquivo, "a"); // abre o arquivo e altera
	 fprintf(file,nome); // salvando o conteúdo da variavel dentro do arquivo
	 fclose(file); // fecha o arquivo depois de salvo.
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,","); // adicionando virgula
	 fclose(file);
	 
	 printf("Digite o sobrenome a ser cadastrado: ");
	 scanf("%s", sobrenome);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file,sobrenome);
	 fclose(file);
	 
	 file = fopen(arquivo, "a");
	 fprintf(file, ",");
	 fclose(file);
	 
	 printf("Digite o cargo a ser cadastrado: "); // pergunta ao usuario
	 scanf("%s", cargo); //%s salva dentro da variavel
	 
	 file = fopen(arquivo, "a"); //atualiza o arquivo
	 fprintf(file,cargo);
	 fclose(file);
	 
	 system("pause"); // sistema em pausa
	 
}

int consultar() //função responsável pelo menu inicial
{
	 setlocale(LC_ALL, "Portuguese"); //definição de linguagem
	 
     char cpf[40]; // criação do conteúdo, no caso o arquivo cpf, do tipo char que refere-se a uma string
     char conteudo[200];
     
     printf("Digite o CPF a ser consultado: "); // perguntando ao usuario
     scanf("%s" ,cpf); // salvar na variavel
     
     FILE *file; // consulta o arquivo file
     file = fopen(cpf, "r"); // apenas read, ler o arquivo
     
     if(file == NULL) // caso ele nao encontre um cpf
     {
     	 printf("Não foi possível abrir o arquivo, não localizado! .\n"); // fala para o usuario, observar o set localle, devido grafia.
	 }
	 
	 while(fgets(conteudo,200, file) != NULL) //busca de acordo com o laço, while, o conteúdo, roda em até 200x dentro do arquivo, para qdo for null, nao achou é NULL
	 {
	 	 printf("\nEssas são as informaçoes do usuário: ");
	 	 printf("%s" ,conteudo);
	 	 printf("\n\n");
	 }
	 
	 system("pause");
	 
}

int deletar()
{
     char cpf[40];
     
     printf("Digite o CPF do usuario a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("O usuário nao se encontra no sistema!.\n");
     	system("pause");
	 }
	 
	 	    
}

int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	  system("cls"); //responsavel por limpar a tela
	  		
	  setlocale(LC_ALL, "Portuguese"); //definição de linguagem
    
	  printf("### Cartório da EBAC ###\n\n"); // inicio do menu
	  printf("Escolha a opção desejada do menu:\n\n");
	  printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consultar Nomes\n");
	  printf("\t3 - Deletar Nomes\n");
	  printf("\t4 - Sair do Sistema\n\n");
	  printf("Digite a Opção: "); // fim do menu
	
	  scanf("%d" , &opcao); //armazenando as opçoes do usuario
	
	  system("cls"); //responsavel por limpar a tela
	  
	  
	  switch(opcao)
	  {
	  	  case 1:
	  	  	registrar(); // chama as  funcoes
	  	  	break;
	  	  	
	  	  case 2:
			consultar();
			break;
			
		  case 3:
		    deletar();
		    break; 
		    
		  case 4:
		    printf("Obrigado por Utilizar o Sistema!\n");
		    return 0;
		    break;
		    
		  default:
		    printf("Essa Opção Não Esta Disponível!\n"); // mostra na tela opçoes não existentes
		    system("pause");
		    break;
		  //fim da seleção
	  }
	
    }
}
