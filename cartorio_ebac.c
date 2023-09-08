#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca�oes de texto por regiao
#include <string.h> //biblioteca de string


int registrar() //func�o respons�vel por cadastrar os ususarios.

{
	 //inicio da cria��o das variaveis/string
	 char arquivo[40]; //caracter tipo char, colchetes refere-se a uma variavel tipo string, de at� 40 variaveis, nesse caso, aqui arquivo criado
	 char cpf[40];
	 char nome[40];
	 char sobrenome[40];
	 char cargo[40];
	 //final da cria��o das variaveis/string
	 
	 printf("Digite o CPF a ser cadastrado: "); //pergunta feita ao ususario
	 scanf("%s", cpf); //armazena os dados dentro de uma string, %s.
	 
	 strcpy(arquivo, cpf); //respons�vel por copiar os valores das string 
	 
	 FILE *file; // cria o arquivo no banco de dados, acessa o file e cria o file.
	 file = fopen(arquivo, "w"); // abre o arquivo, a variavel arquivo, escreve, devido o write "W".
	 fprintf(file,cpf); // salva o valor da variavel no arquivo file
	 fclose(file); // depois de salvo, fecha-se o arquivo.
	 
	 file = fopen(arquivo, "a"); //arquivo sendo aberto novamente e "a" atualizando as informa�oes
	 fprintf(file, ","); // adiciona uma virgula no texto salvo no file no arquivo
	 fclose(file); //fecha o arquivo salvo.
	 
	 printf("Digite o Nome a ser cadastrado: "); // 
	 scanf("%s",nome); // salvar na string
	 
	 file = fopen(arquivo, "a"); // abre o arquivo e altera
	 fprintf(file,nome); // salvando o conte�do da variavel dentro do arquivo
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

int consultar() //fun��o respons�vel pelo menu inicial
{
	 setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
	 
     char cpf[40]; // cria��o do conte�do, no caso o arquivo cpf, do tipo char que refere-se a uma string
     char conteudo[200];
     
     printf("Digite o CPF a ser consultado: "); // perguntando ao usuario
     scanf("%s" ,cpf); // salvar na variavel
     
     FILE *file; // consulta o arquivo file
     file = fopen(cpf, "r"); // apenas read, ler o arquivo
     
     if(file == NULL) // caso ele nao encontre um cpf
     {
     	 printf("N�o foi poss�vel abrir o arquivo, n�o localizado! .\n"); // fala para o usuario, observar o set localle, devido grafia.
	 }
	 
	 while(fgets(conteudo,200, file) != NULL) //busca de acordo com o la�o, while, o conte�do, roda em at� 200x dentro do arquivo, para qdo for null, nao achou � NULL
	 {
	 	 printf("\nEssas s�o as informa�oes do usu�rio: ");
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
     	printf("O usu�rio nao se encontra no sistema!.\n");
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
	  		
	  setlocale(LC_ALL, "Portuguese"); //defini��o de linguagem
    
	  printf("### Cart�rio da EBAC ###\n\n"); // inicio do menu
	  printf("Escolha a op��o desejada do menu:\n\n");
	  printf("\t1 - Registrar Nomes\n");
	  printf("\t2 - Consultar Nomes\n");
	  printf("\t3 - Deletar Nomes\n");
	  printf("\t4 - Sair do Sistema\n\n");
	  printf("Digite a Op��o: "); // fim do menu
	
	  scanf("%d" , &opcao); //armazenando as op�oes do usuario
	
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
		    printf("Essa Op��o N�o Esta Dispon�vel!\n"); // mostra na tela op�oes n�o existentes
		    system("pause");
		    break;
		  //fim da sele��o
	  }
	
    }
}
