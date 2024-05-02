#include <stdio.h> //biblioteca de comunicção com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <windows.h>
#include <string.h> //biblioteca responsável porcuidar das strings

int registrar() //ciando a função de registar os nomes
{ 
  //criando as variáveis/strings
  char arquivo [40];
  char cpf[40]; 
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //final da criação de variáveis/strings
  
  printf("Você escolheu o registro de nomes\n\n"); //mostrando ao usuário qual opção foi escolhida
  
  
  printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
  scanf("%s", cpf); //armazenando as stings
  
   strcpy(arquivo, cpf); //copia os valores das strings
  
   FILE *file; //cria o arquivo no banco de dados
   file = fopen(arquivo, "w"); //cria um arquivo novo
   fprintf(file,cpf); //salva o valor da variável
   fclose(file); //fecha o arquivo
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file,","); //adiciona uma "," para dividir o texto do arquivo
   fclose(file); //fecha o arquivo
  
  printf("Digete o NOME a ser cadastrado: "); //coletando as informações do usuário
  scanf("%s", nome); //armazenando as stings
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file,nome); //adiciona a informação do nome
   fclose(file); //fecha o arquivo
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file,","); //adiciona uma "," para dividir o texto do arquivo
   fclose(file);  
  
  printf ("Digite o SOBRENOME a ser cadastrado: "); //coletando as informações do usuário
  scanf("%s", sobrenome); //armazenando as stings
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file,sobrenome); //adiciona a informação do sobrenome
   fclose(file); //fecha o arquivo
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file,","); //adiciona uma "," para dividir o texto do arquivo
   fclose(file); //fecha o arquivo
  
  printf ("Digite o CARGO a ser cadastrado: "); //coletando as informações do usuário
  scanf("%s", cargo); //armazenando as stings
  
   file = fopen(arquivo, "a"); //atualiza o arquivo já existente
   fprintf(file, cargo); //adiciona a informação do cargo
   fclose(file);//fecha o arquivo
 
 system("pause"); //mantem o usuário na tela
}

int consultar()
{
  //criando as variáveis/strings
  char cpf[40];
  char conteudo[200];
  //final da criação das variáveis/strings
  
  printf("Você escolheu colsultar os nomes\n\n"); //mostrando ao usuário qual opção foi escolhida
  printf("\n"); //cria um epaçamento entre os textos
  printf("Digite o CPF a ser consultado: "); //coleta as informações do usuário
  scanf("%s",cpf); //amazena as strings
  
  FILE *file; //cria um arquivo no banco de dados
  file = fopen(cpf, "r"); //abre o aquivo e faz uma leitura
  
  if(file == NULL) //caso a informação digitada seja nula (não faça parte do sistema)
  {
  	printf("\n"); //espaçamento entre os textos
	printf("CPF não localizado\n\n"); //aviso que não existe o arquivo no sistema
  }
 
  while (fgets(conteudo, 200, file) != NULL) //enquanto a informação não for nula
  {
  	printf("\n"); //espaçamento
	printf("Essas são as informações do usuário: "); //texto indicando as informações
  	printf("%s", conteudo); //mostra as informações presentes no arquivo
  	printf("\n\n"); //espaçamento
  }	
  
  system("pause"); //mantém o usuário na tela
}

int deletar()
{
  char cpf[40]; //cria a variável
  
 printf("Você escolheu deletar os nomes\n"); //mostra o opção selecionada
 printf("\n"); //espaçamento
 
 printf("Digite o CPF do usuário a ser deletado: "); //coleta informações do usuário
 scanf("%s", cpf); //amazena na string
 
 FILE *file;
 file = fopen(cpf,"r"); //abre e lê o arquivo
 fclose(file); //fecha o arquivo
 
if(file == NULL) //caso a informação digitada seja nula (não faça parte do sistema)
{
	printf("\n"); //espaçamento
	printf("CPF inválido\n\n"); //informa que o arquivo não existe no sistema
}
else //se não
{
	remove(cpf); //deleta o arquivo
	printf("\n"); //espaçamento
	printf("Usuário deletado com sucesso!\n\n"); //informando que o arquivo foi deletado
}
system("pause"); //mantém o usuário na tela
}


int main()
{
    int opcao=0; //definindo variáveis
    int laco=1;
	
	for(laco=1;laco=1;) //criando repetição
	{
	 system("cls"); //limpa a tela
	 
	 SetConsoleOutputCP(CP_UTF8); //definindo a linguagem
	
	//inicio do menu
	 printf("     ===# Cartório da EBAC #===\n\n");  
	 printf("   Escolha a opção desejada do menu:\n\n");
	 printf("\t1 -> Registrar nomes\n");
	 printf("\t2 -> Consultar nomes\n");
	 printf("\t3 -> Deletar nomes\n"); 
	 printf("\t4 -> Sair do sistema\n\n");
	 printf("   Digite o número da opção: "); 
	 //final do menu
	
	 scanf("%d", &opcao); //armazenando a escolha do usuário
	
	 system("cls"); //limpando o menu
	
	 switch(opcao) //analisando a variável e criando as opções
	 {
	 	case 1: //caso o usuário digite "1"
	 	 registrar(); //chama a função de registrar	
	     break; //fechandondo as "chaves"
	     
	     case 2: //caso o usuário digite "2"
	     consultar(); //chama a função de consultar
	     break; //fecha a "chave"
	     
	     case 3: //caso o usuário digite "3"
	     deletar(); //chama a função de deletar
	     break; //fecha a "chave"
	     
	     case 4: //caso o usuário digite "3"
	     printf("Você escolheu sair do sistema.\n"); //informando que o usuário sairá do sistema
		 printf("Obrigado por utilizar o sisstema!\n"); 
	     return 0; //retarna ao valor 0 quebrando o laço, função etc e fecha o sistema
	     break; //fecha a "chave"
	     
	     default: //caso seja uma opção não mapeada
	     printf("\n"); //epaçamento
		 printf("Essa opção não está disponível\n"); //informando que não existe essa opção
	     printf("\n"); //espaçamento
		 system("pause"); //mantém o usuário na tela
	     break; //fecha "chave"
	 }// fim da seleção
	}
	
	
	
	
}