#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include <dos.h>
#include <windows.h>

void Funcionarios();
	void FuncionariosCadastro();
	void FuncionariosConsulta();
	void FuncionariosAlteracao();
	void FuncionariosLista();
	void FuncionariosRelatorio();
void Clientes();
	void ClientesCadastro();
	void ClientesConsulta();
	void ClientesAlteracao();
	void ClientesLista();
	void ClientesRelatorio();
void Editoras();
	void NossasEditoras();
		void EditorasCadastro();
		void EditorasConsulta();
		void EditorasAlteracao();
		void EditorasLista();
		void EditorasRelatorio();
void Livros();

	void NossosLivros();
		void LivrosCadastro();
		void LivrosConsulta();
		void LivrosAlteracao();
			void EditoraConsultarNome(int codigo);
		void LivrosLista();
		void LivrosListaNome();
	void Estoque();
		void EditoraListaNome();
		
void Vendas();
	void VendasLista();
	void VendasCadastro();
		
void Pedidos();
	void PedidosCadastro();
	
void Contas();
	void ContasCadastro();
	void ContasConsulta();
	void ContasPagamento();
	void ContasLista();
	void ContasRelatorio();
	
	
			int NumeroLinhas(char path[100]);
			int ValidarEmail(char email[]);
			void retornarData(char *data);
			void SetColor(int ForgC);

int main(){
	int opcaoMenu, voltaMenu = 2;
	setlocale(LC_ALL, "");
	while(voltaMenu == 2){
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Bem vindoª à Livraria Sega.                                                                                |\n");
		printf("|============================================================================================================|\n");
		printf("| Selecione uma das opções abaixo:                                                                           |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Livros                                                                                                 |\n");
		printf("| 2 - Clientes                                                                                               |\n");
		printf("| 3 - Funcionários                                                                                           |\n");
		printf("| 4 - Editoras                                                                                               |\n");
		printf("| 5 - Vendas                                                                                                 |\n");
		printf("| 6 - Contas                                                                                                 |\n");
		printf("| 7 - Sair                                                                                                   |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		scanf("%d", &opcaoMenu);
		while(opcaoMenu < 1 || opcaoMenu > 8 ){
			printf("\n  Digite uma opção válida. (Valores de 1 a 8).\n  ");
			scanf("%d", &opcaoMenu);
		}
		switch(opcaoMenu){
			case 1:
				system("cls");
				Livros();
				break;
			case 2:
				system("cls");
				Clientes();
				break;
			case 3:
				system("cls");
				Funcionarios();
				break;
			case 4:
				system("cls");
				Editoras();
				break;
			case 5:
				system("cls");
				Vendas();
				break;
			case 6:
				system("cls");
				Contas();
				break;
			case 7:
				voltaMenu = 0;
				break;
		}
	}
	return 0;    
}

void Funcionarios(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoFuncionario;		
		printf("==============================================================================================================\n");
		printf("| Funcionários                                                                                               |\n");
		printf("|============================================================================================================|\n");
		FuncionariosLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Cadastrar                                                                                              |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Alterar                                                                                                |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &opcaoFuncionario);
		while(opcaoFuncionario < 1 || opcaoFuncionario > 5){
			printf("\n  Digite uma opção válida. (Valores de 1 a 5).\n  ");
			scanf("%d", &opcaoFuncionario);
		}
		switch(opcaoFuncionario){
			case 1:
				system("cls");
				FuncionariosCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				FuncionariosConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				FuncionariosAlteracao();
				continua = 0;
				break;
			case 4:
				system("cls");
				FuncionariosRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void FuncionariosCadastro(){
	
	struct Funcionario{
		char nome[41];
		char rg[13];
		char cpf[15];
		char contratacao[11];
		int funcao;
		char telefone[16];
		char email[51];
	};
	
	
	struct Funcionario funcionarioVar;
	
	
	
	printf("==============================================================================================================\n");
	printf("| Cadastro de Funcionários.                                                                                  |\n");
	printf("|============================================================================================================|\n");
	printf("| Digite o nome doª funcionárioª:                                                                            |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	fflush(stdin);
	fgets(funcionarioVar.nome,41,stdin);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o RG doª funcionárioª:                                                                              |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(funcionarioVar.rg);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o CPF doª funcionárioª:                                                                             |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(funcionarioVar.cpf);
	/*while(!ValidarCPF(cpf)){
		printf("\nCPF INVÁLIDO!\n");
		printf("Digite o CPF doª funcionárioª:\n");
		gets(funcionarioVar.cpf);
	}*/
	retornarData(funcionarioVar.contratacao);
	
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite a função doª funcionárioª:                                                                          |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| 1 - Gerente                                                                                                |\n");
	printf("| 2 - Vendedor                                                                                               |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	scanf("%d", &funcionarioVar.funcao);
	fflush(stdin);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o telefone doª funcionárioª:                                                                        |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(funcionarioVar.telefone);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o email doª funcionárioª:                                                                           |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(funcionarioVar.email);

	while(!ValidarEmail(funcionarioVar.email)){
		printf("| EMAIL INVÁLIDO!                                                                                            |\n");
		printf("| Digite o email doª funcionárioª:                                                                           |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		gets(funcionarioVar.email);
		printf("--------------------------------------------------------------------------------------------------------------\n");
	}
	
	int codigo = NumeroLinhas("Funcionários.txt") / 9 + 1;
	FILE *f = fopen("Funcionários.txt", "a");
	fprintf(f, "%d\n", codigo);	    
	if(strlen(funcionarioVar.nome) == 40){
		fprintf(f, "%s\n", funcionarioVar.nome);
	}else{
		fprintf(f, "%s", funcionarioVar.nome);
	}
						
	fprintf(f, "%s\n", funcionarioVar.rg);
	fprintf(f, "%s\n", funcionarioVar.cpf);
	fprintf(f, "%s\n", funcionarioVar.contratacao); 
	if(funcionarioVar.funcao == 1){
		fprintf(f, "%s\n", "Gerente");   
	}else if(funcionarioVar.funcao == 2){
		fprintf(f, "%s\n", "Vendedor");   
	}
	fprintf(f, "%s\n", funcionarioVar.telefone);   
	fprintf(f, "%s\n", funcionarioVar.email);   
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	printf("  Funcionárioª %s registradoª com sucesso. Pressione qualquer tecla para continuar.", funcionarioVar.nome);
	getch();
	system("cls");
}

void FuncionariosConsulta(){
	int continua = 0;
	while(continua == 0){
		
		
		printf("==============================================================================================================\n");
		printf("| Consulta de Funcionários.                                                                                  |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código doª funcionárioª que deseja consultar:                                                     |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Funcionários.txt") / 9){
			printf("----------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe um funcionário registrado com o código %-6d |\n", codigo);
			printf("| Digite o código doª funcionárioª que deseja consultar:   |\n");
			printf("----------------------------------------------------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Funcionários.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados do Funcionário                                                                                       |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (9*(codigo-1))){
				printf("| Código:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			if(i == (9*(codigo-1))+1){
				printf("| Nome:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+2){
				printf("| RG.:      %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+3){
				printf("| CPF.:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+5){
				printf("| Função:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+6){
				printf("| Telefone: %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+7){
				printf("| E-mail:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		fclose(f);
		printf("| Deseja efetuar uma nova consulta?                                                                          |\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void FuncionariosAlteracao(){
	int continua = 0;
	while(continua == 0){
		
		
		printf("==============================================================================================================\n");
		printf("| Alteração de Funcionários.                                                                                 |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código doª funcionárioª que deseja alterar:                                                       |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		
		

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Funcionários.txt") / 9){
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe um funcionário registrado com o código %-6d                                                   |\n", codigo);
			printf("| Digite o código doª funcionárioª que deseja alterar:                                                       |\n");
			printf("--------------------------------------------------------------------------------------------------------------\n");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Funcionários.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados do Funcionário                                                                                       |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (9*(codigo-1))){
				printf("| Código:   %-40s |\n", strtok(line,"\n"));
			}
			if(i == (9*(codigo-1))+1){
				printf("| Nome:     %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+2){
				printf("| RG.:      %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+3){
				printf("| CPF.:     %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+5){
				printf("| Função:   %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+6){
				printf("| Telefone: %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (9*(codigo-1))+7){
				printf("| E-mail:   %-40s |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("==============================================================================================================\n");
		fclose(f);
		int opcaoalteracao;
		printf("|  Digite o dado que deseja alterar                                                                          |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("| 1 - Nome                                                                                                   |\n");
		printf("| 2 - RG                                                                                                     |\n");
		printf("| 3 - CPF                                                                                                    |\n");
		printf("| 4 - Função                                                                                                 |\n");
		printf("| 5 - Telefone                                                                                               |\n");
		printf("| 6 - Email                                                                                                  |\n");
		printf("==============================================================================================================\n  ");
		scanf("%d", &opcaoalteracao);
		char novodado[100];
		char novonome[42];
		FILE *from = fopen("Funcionários.txt", "r");
		FILE *to = fopen("Funcionários2.txt", "w");
		i = 0;
		fflush(stdin);
		switch(opcaoalteracao){
			case 1:
				printf("==============================================================================================================\n");
				printf("| Digite o novo nome:                                                                                        |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				fgets(novonome,41,stdin);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+1){
						if(strlen(novonome) == 40){
							fprintf(to, "%s\n", novonome);
						}else{
							fprintf(to, "%s", novonome);
						}
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
			case 2:
				printf("==============================================================================================================\n");
				printf("| Digite o novo RG.:                                                                                         |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+2){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
			case 3:
				printf("==============================================================================================================\n");
				printf("| Digite o novo CPF.:                                                                                         |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+3){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
			case 4:
				printf("==============================================================================================================\n");
				printf("| Digite a nova Função:                                                                                      |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+5){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
			case 5:
				printf("==============================================================================================================\n");
				printf("| Digite o novo Telefone:                                                                                    |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+6){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
			case 6:
				printf("==============================================================================================================\n");
				printf("| Digite o novo E-mail:                                                                                      |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(!ValidarEmail(novodado)){                                                        
					printf("| EMAIL INVÁLIDO!                                                                                            |\n");
					printf("| Digite o novo E-mail:                                                                                      |\n");
					printf("|------------------------------------------------------------------------------------------------------------|\n  ");
					gets(novodado);
				}
				
				while(fgets(line, sizeof(line), from)){
					if(i == (9*(codigo-1))+7){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Funcionários.txt");
				rename("Funcionários2.txt", "Funcionários.txt");
				break;
		}
		
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("| Deseja efetuar uma nova alteração?                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		fflush(stdin);
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void FuncionariosLista(){
	struct Funcionario{
		char codigo[6];
		char nome[71];
		char rg[13];
		char cpf[15];
		char funcao[16];
	};
	
	printf("| Lista de Funcionários                                                                                      |\n");
	printf("|============================================================================================================|\n");
	struct Funcionario funcionarioVar;
	if(NumeroLinhas("Funcionários.txt") == 0){
		printf("Não há funcionários registrados.");
	}else{
		printf("| %6s     %-40s   %-12s   %-14s   %-20s |\n", "CÓDIGO", "NOME", "RG", "CPF", "FUNÇÃO");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Funcionários.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(funcionarioVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(funcionarioVar.nome, strtok(line,"\n"));	
					break;
				case 2:
					strcpy(funcionarioVar.rg, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(funcionarioVar.cpf, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(funcionarioVar.funcao, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 9){
				printf("| %6s     %-40s   %-12s   %-14s   %-20s |\n", funcionarioVar.codigo, funcionarioVar.nome, funcionarioVar.rg, funcionarioVar.cpf, funcionarioVar.funcao);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");

	}
}

void FuncionariosRelatorio(){
	struct Funcionario{
		char codigo[6];
		char nome[71];
		char rg[13];
		char cpf[15];
		char funcao[16];
	};
	remove("FuncionáriosRel.txt");
	FILE *rel = fopen("FuncionáriosRel.txt", "w");
	fprintf(rel, "===============================================================================================================\n");
	fprintf(rel, "|                                            Lista de Funcionários                                            |\n");
	fprintf(rel, "|=============================================================================================================|\n");
	struct Funcionario funcionarioVar;
	if(NumeroLinhas("Funcionários.txt") == 0){
		printf("Não há funcionários registrados.");
	}else{
		fprintf(rel, "| %6s     %-40s   %-12s   %-14s   %-20s  |\n", "CÓDIGO", "NOME", "RG", "CPF", "FUNÇÃO");
		fprintf(rel, "|-------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Funcionários.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(funcionarioVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(funcionarioVar.nome, strtok(line,"\n"));	
					break;
				case 2:
					strcpy(funcionarioVar.rg, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(funcionarioVar.cpf, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(funcionarioVar.funcao, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 9){
				fprintf(rel, "| %6s     %-40s   %-12s   %-14s   %-20s  |\n", funcionarioVar.codigo, funcionarioVar.nome, funcionarioVar.rg, funcionarioVar.cpf, funcionarioVar.funcao);
				i = 0;
			}
		}
		fclose(f);
		fprintf(rel, "===============================================================================================================\n");
		fclose(rel);
		
		printf("==============================================================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		getch();
	}
}

void Clientes(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoCliente;
		
		
		printf("==============================================================================================================\n");
		printf("| Clientes                                                                                                   |\n");
		printf("|============================================================================================================|\n");
		ClientesLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Cadastrar                                                                                              |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Alterar                                                                                                |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");

		scanf("%d", &opcaoCliente);
		while(opcaoCliente < 1 || opcaoCliente > 5){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoCliente);
		}
		switch(opcaoCliente){
			case 1:
				system("cls");
				ClientesCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				ClientesConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				ClientesAlteracao();
				continua = 0;
				break;
			case 4:
				system("cls");
				ClientesRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void ClientesCadastro(){
	
	struct Cliente{
		char nome[71];
		char rg[13];
		char cpf[15];
		char contratacao[11];
		char telefone[16];
		char email[51];
	};
	
	
	struct Cliente ClienteVar;
	
	printf("==============================================================================================================\n");
	printf("| Cadastro de Clientes.                                                                                      |\n");
	printf("|============================================================================================================|\n");
	printf("| Digite o nome doª Cliente:                                                                                 |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	fflush(stdin);
	gets(ClienteVar.nome);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o RG doª Cliente:                                                                                   |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(ClienteVar.rg);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o CPF doª Cliente:                                                                                  |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(ClienteVar.cpf);
	/*while(!ValidarCPF(cpf)){
		printf("\nCPF INVÁLIDO!\n");
		printf("Digite o CPF doª Cliente:\n");
		gets(ClienteVar.cpf);
	}*/
	retornarData(ClienteVar.contratacao);
	
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o telefone doª Cliente:                                                                             |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(ClienteVar.telefone);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o email doª Cliente:                                                                                |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(ClienteVar.email);
	printf("--------------------------------------------------------------------------------------------------------------\n");

	while(!ValidarEmail(ClienteVar.email)){
		printf("| EMAIL INVÁLIDO!                                                                                            |\n");
		printf("| Digite o email doª Cliente:                                                                                |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		gets(ClienteVar.email);
		printf("--------------------------------------------------------------------------------------------------------------\n");
	}
	
	int codigo = NumeroLinhas("Clientes.txt") / 8 + 1;
	FILE *f = fopen("Clientes.txt", "a");
	fprintf(f, "%d\n", codigo);	    
	fprintf(f, "%s\n", ClienteVar.nome);
	fprintf(f, "%s\n", ClienteVar.rg);
	fprintf(f, "%s\n", ClienteVar.cpf);
	fprintf(f, "%s\n", ClienteVar.contratacao); 
	fprintf(f, "%s\n", ClienteVar.telefone);   
	fprintf(f, "%s\n", ClienteVar.email);   
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	system("cls");
}

void ClientesConsulta(){
	int continua = 0;
	while(continua == 0){
		printf("==============================================================================================================\n");
		printf("| Consulta de Clientes.                                                                                      |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código doª Cliente que deseja consultar:                                                          |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		int codigo = 0;
		scanf("%d", &codigo);	
		while(codigo < 1 || codigo > NumeroLinhas("Clientes.txt") / 8){
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe um Cliente registrado com o código %-6d                                                       |\n", codigo);
			printf("| Digite o código doª Cliente que deseja consultar:                                                          |\n");
			printf("--------------------------------------------------------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}	
		FILE *f = fopen("Clientes.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados doª Cliente                                                                                          |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (8*(codigo-1))){
				printf("| Código:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			if(i == (8*(codigo-1))+1){
				printf("| Nome:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+2){
				printf("| RG.:      %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+3){
				printf("| CPF.:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+5){
				printf("| Telefone: %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+6){
				printf("| E-mail:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		fclose(f);
		printf("| Deseja efetuar uma nova consulta?                                                                          |\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void ClientesAlteracao(){
	int continua = 0;
	while(continua == 0){
		
		printf("==============================================================================================================\n");
		printf("| Alteração de Clientes.                                                                                     |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código doª Cliente que deseja alterar:                                                            |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		
		

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Clientes.txt") / 8){
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe um Cliente registrado com o código %-6d                                                       |\n", codigo);
			printf("| Digite o código doª Cliente que deseja alterar:                                                            |\n");
			printf("--------------------------------------------------------------------------------------------------------------\n  ");		
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Clientes.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados doª Cliente                                                                                          |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (8*(codigo-1))){
				printf("| Código:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			if(i == (8*(codigo-1))+1){
				printf("| Nome:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+2){
				printf("| RG.:      %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+3){
				printf("| CPF.:     %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+5){
				printf("| Telefone: %-40s                                                         |\n", strtok(line,"\n"));
			}
			
			if(i == (8*(codigo-1))+6){
				printf("| E-mail:   %-40s                                                         |\n", strtok(line,"\n"));
			}
			i++;
		}		
		printf("==============================================================================================================\n");
		fclose(f);
		int opcaoalteracao;
		printf("|  Digite o dado que deseja alterar                                                                          |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("| 1 - Nome                                                                                                   |\n");
		printf("| 2 - RG                                                                                                     |\n");
		printf("| 3 - CPF                                                                                                    |\n");
		printf("| 4 - Telefone                                                                                               |\n");
		printf("| 5 - Email                                                                                                  |\n");
		printf("==============================================================================================================\n  ");
		
		scanf("%d", &opcaoalteracao);
		char novodado[100];
		char novonome[42];
		FILE *from = fopen("Clientes.txt", "r");
		FILE *to = fopen("Clientes2.txt", "w");
		i = 0;
		fflush(stdin);
		switch(opcaoalteracao){
			case 1:
				printf("==============================================================================================================\n");
				printf("| Digite o novo nome:                                                                                        |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				fgets(novonome,41,stdin);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (8*(codigo-1))+1){
						if(strlen(novonome) == 40){
							fprintf(to, "%s\n", novonome);
						}else{
							fprintf(to, "%s", novonome);
						}
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Clientes.txt");
				rename("Clientes2.txt", "Clientes.txt");
				break;
			case 2:
				printf("==============================================================================================================\n");
				printf("| Digite o novo RG.:                                                                                         |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (8*(codigo-1))+2){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Clientes.txt");
				rename("Clientes2.txt", "Clientes.txt");
				break;
			case 3:
				printf("==============================================================================================================\n");
				printf("| Digite o novo CPF.:                                                                                        |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(fgets(line, sizeof(line), from)){
					if(i == (8*(codigo-1))+3){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Clientes.txt");
				rename("Clientes2.txt", "Clientes.txt");
				break;
			case 4:
				printf("==============================================================================================================\n");
				printf("| Digite o novo Telefone:                                                                                    |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (8*(codigo-1))+5){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Clientes.txt");
				rename("Clientes2.txt", "Clientes.txt");
				break;
			case 5:
				printf("==============================================================================================================\n");
				printf("| Digite o novo E-mail:                                                                                      |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(!ValidarEmail(novodado)){
					printf("| EMAIL INVÁLIDO!                                                                                            |\n");
					printf("| Digite o novo E-mail:                                                                                      |\n");
					printf("|------------------------------------------------------------------------------------------------------------|\n  ");
					gets(novodado);
				}			
				while(fgets(line, sizeof(line), from)){
					if(i == (8*(codigo-1))+6){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Clientes.txt");
				rename("Clientes2.txt", "Clientes.txt");
				break;
		}
		
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("| Deseja efetuar uma nova alteração?                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void ClientesLista(){
		struct Cliente{
		char codigo[6];
		char nome[71];
		char rg[13];
		char cpf[15];
	};
	
	printf("| Lista de Clientes                                                                                          |\n");
	printf("|============================================================================================================|\n");
	
	struct Cliente ClienteVar;
	if(NumeroLinhas("Clientes.txt") == 0){
		printf("Não há Clientes registrados.");
	}else{
		printf("| %6s     %-40s   %-12s   %-37s |\n", "CÓDIGO", "NOME", "RG", "CPF");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Clientes.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(ClienteVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(ClienteVar.nome, strtok(line,"\n"));	
					break;
				case 2:
					strcpy(ClienteVar.rg, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(ClienteVar.cpf, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 8){
					printf("| %6s     %-40s   %-12s   %-37s |\n", ClienteVar.codigo, ClienteVar.nome, ClienteVar.rg, ClienteVar.cpf);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");		
	}
}

void ClientesRelatorio(){
	struct Cliente{
		char codigo[6];
		char nome[71];
		char rg[13];
		char cpf[15];
	};
	remove("ClientesRel.txt");
	FILE *rel = fopen("ClientesRel.txt", "w");
	fprintf(rel, "========================================================================================\n");
	fprintf(rel, "|                                            Lista de Clientes                         |\n");
	fprintf(rel, "|======================================================================================|\n");
	struct Cliente ClienteVar;
	if(NumeroLinhas("Clientes.txt") == 0){
		printf("Não há Clientes registrados.");
	}else{
		fprintf(rel, "| %6s     %-40s   %-12s   %-14s  |\n", "CÓDIGO", "NOME", "RG", "CPF");
		fprintf(rel, "|--------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Clientes.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(ClienteVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(ClienteVar.nome, strtok(line,"\n"));	
					break;
				case 2:
					strcpy(ClienteVar.rg, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(ClienteVar.cpf, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 8){
				fprintf(rel, "| %6s     %-40s   %-12s   %-14s  |\n", ClienteVar.codigo, ClienteVar.nome, ClienteVar.rg, ClienteVar.cpf);
				i = 0;
			}
		}
		fclose(f);
		fprintf(rel, "========================================================================================\n");
		fclose(rel);
		
		printf("==============================================================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		getch();
	}
}

void Editoras(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoEditora;
		
		printf("==============================================================================================================\n");
		printf("| Editoras                                                                                                   |\n");
		printf("|============================================================================================================|\n");
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Nossas Editoras                                                                                        |\n");
		printf("| 2 - Pedidos ***                                                                                            |\n");
		printf("| 3 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &opcaoEditora);
		while(opcaoEditora < 1 || opcaoEditora > 3){
			printf("\nDigite uma opção válida. (Valores de 1 a 4)\n");
			scanf("%d", &opcaoEditora);
		}
		switch(opcaoEditora){
			case 1:
				system("cls");
				NossasEditoras();
				continua = 0;
				break;
			case 2:
				system("cls");
				Pedidos();
				continua = 0;
			default:
				continua = 1;
				break;
		}
	}
}

void NossasEditoras(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoEditora;
		
		printf("==============================================================================================================\n");
		printf("| Nossas Editoras                                                                                            |\n");
		printf("|============================================================================================================|\n");
		EditorasLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Cadastrar                                                                                              |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Alterar                                                                                                |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		
		scanf("%d", &opcaoEditora);
		while(opcaoEditora < 1 || opcaoEditora > 5){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoEditora);
		}
		switch(opcaoEditora){
			case 1:
				system("cls");
				EditorasCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				EditorasConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				EditorasAlteracao();
				continua = 0;
				break;
			case 4:
				system("cls");
				EditorasRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void EditorasCadastro(){
	
	struct Editora{
		char nomefantasia[71];
		char razaosocial[71];
		char cnpj[13];
		char telefone[16];
		char email[51];
	};
	
	
	struct Editora EditoraVar;
	printf("==============================================================================================================\n");
	printf("| Cadastro de Editoras.                                                                                      |\n");
	printf("|============================================================================================================|\n");
	printf("| Digite o Nome Fantasia da Editora:                                                                         |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	fflush(stdin);
	gets(EditoraVar.nomefantasia);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite a Razão Social da Editora:                                                                          |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");	
	gets(EditoraVar.razaosocial);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o CNPJ da Editora:                                                                                  |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(EditoraVar.cnpj);
	/*while(!ValidarCNPJ(cpf)){
		printf("\nCNPJ INVÁLIDO!\n");
		printf("Digite o CNPJ da Editora:\n");
		gets(EditoraVar.cnpj);
	}*/
	
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o telefone da Editora:                                                                              |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(EditoraVar.telefone);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o email da Editora:                                                                                 |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n  ");
	gets(EditoraVar.email);

	while(!ValidarEmail(EditoraVar.email)){
		printf("| EMAIL INVÁLIDO!                                                                                            |\n");
		printf("| Digite o email da Editora:                                                                                 |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		gets(EditoraVar.email);
		printf("--------------------------------------------------------------------------------------------------------------\n");
	}
	
	int codigo = NumeroLinhas("Editoras.txt") / 9 + 1;
	FILE *f = fopen("Editoras.txt", "a");
	fprintf(f, "%d\n", codigo);	    
	fprintf(f, "%s\n", EditoraVar.nomefantasia);
	fprintf(f, "%s\n", EditoraVar.razaosocial);
	fprintf(f, "%s\n", EditoraVar.cnpj);
	fprintf(f, "%s\n", EditoraVar.telefone);   
	fprintf(f, "%s\n", EditoraVar.email);   
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	printf("  Editora %s registrada com sucesso. Pressione qualquer tecla para continuar.", EditoraVar.nomefantasia);
	getch();
	system("cls");
}

void EditorasConsulta(){
	int continua = 0;
	while(continua == 0){
		printf("==============================================================================================================\n");
		printf("| Consulta de Editoras.                                                                                      |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código da Editora que deseja consultar:                                                           |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Editoras.txt") / 7){
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe uma Editora registrado com o código %-5d                                                        |\n", codigo);
			printf("| Digite o código da Editora que deseja consultar:                                                           |\n");
			printf("--------------------------------------------------------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Editoras.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados da Editora                                                                                           |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (7*(codigo-1))){
				printf("| Código:         %-40s                                                   |\n", strtok(line,"\n"));
			}
			if(i == (7*(codigo-1))+1){
				printf("| Nome Fantasia:  %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+2){
				printf("| Razão Social:   %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+3){
				printf("| CNPJ.:          %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+4){
				printf("| Telefone:       %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+5){
				printf("| E-mail:         %-40s                                                   |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		fclose(f);
		printf("| Deseja efetuar uma nova consulta?                                                                          |\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void EditorasAlteracao(){
	int continua = 0;
	while(continua == 0){
		printf("==============================================================================================================\n");
		printf("| Alteração de Editoras.                                                                                     |\n");
		printf("|============================================================================================================|\n");
		printf("| Digite o código da Editora que deseja alterar:                                                             |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Editoras.txt") / 7){
			printf("--------------------------------------------------------------------------------------------------------------\n");
			printf("| Não existe uma Editora registrado com o código %-5d                                                        |\n", codigo);
			printf("| Digite o código da Editora que deseja alterar:                                                             |\n");
			printf("--------------------------------------------------------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Editoras.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("==============================================================================================================\n");
		printf("| Dados da Editora                                                                                           |\n");
		printf("|============================================================================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (7*(codigo-1))){
				printf("| Código:         %-40s                                                   |\n", strtok(line,"\n"));
			}
			if(i == (7*(codigo-1))+1){
				printf("| Nome Fantasia:  %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+2){
				printf("| Razão Social:   %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+3){
				printf("| CNPJ.:          %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+4){
				printf("| Telefone:       %-40s                                                   |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+5){
				printf("| E-mail:         %-40s                                                   |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("==============================================================================================================\n");
		fclose(f);
		int opcaoalteracao;
		printf("|  Digite o dado que deseja alterar                                                                          |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("| 1 - Nome Fantasia                                                                                          |\n");
		printf("| 2 - Razão Social                                                                                           |\n");
		printf("| 3 - CNPJ                                                                                                   |\n");
		printf("| 4 - Telefone                                                                                               |\n");
		printf("| 5 - Email                                                                                                  |\n");
		printf("==============================================================================================================\n  ");
		
		scanf("%d", &opcaoalteracao);
		char novodado[100];
		char novonome[42];
		FILE *from = fopen("Editoras.txt", "r");
		FILE *to = fopen("Editoras2.txt", "w");
		i = 0;
		fflush(stdin);
		switch(opcaoalteracao){
			case 1:
				printf("==============================================================================================================\n");
				printf("| Digite o novo Nome Fantasia:                                                                               |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				fgets(novonome,41,stdin);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (7*(codigo-1))+1){
						if(strlen(novonome) == 40){
							fprintf(to, "%s\n", novonome);
						}else{
							fprintf(to, "%s", novonome);
						}
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Editoras.txt");
				rename("Editoras2.txt", "Editoras.txt");
				break;			
			case 2:
				printf("==============================================================================================================\n");
				printf("| Digite a nova Razão Social:                                                                                |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				fgets(novonome,41,stdin);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (7*(codigo-1))+2){
						if(strlen(novonome) == 40){
							fprintf(to, "%s\n", novonome);
						}else{
							fprintf(to, "%s", novonome);
						}
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				
				fclose(from);
				fclose(to);
				remove("Editoras.txt");
				rename("Editoras2.txt", "Editoras.txt");
				break;
			case 3:
				printf("==============================================================================================================\n");
				printf("| Digite o novo CNPJ.:                                                                                       |\n");
				printf("--------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(fgets(line, sizeof(line), from)){
					if(i == (7*(codigo-1))+3){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Editoras.txt");
				rename("Editoras2.txt", "Editoras.txt");
				break;
			case 4:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Telefone:                                                                                     |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (7*(codigo-1))+4){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Editoras.txt");
				rename("Editoras2.txt", "Editoras.txt");
				break;
			case 5:
				printf("===============================================================================================================\n");
				printf("| Digite o novo E-mail:                                                                                       |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(!ValidarEmail(novodado)){
					printf("| EMAIL INVÁLIDO!                                                                                             |\n");
					printf("| Digite o novo E-mail:                                                                                       |\n");
					printf("|-------------------------------------------------------------------------------------------------------------|\n  ");
					gets(novodado);
				}
				
				while(fgets(line, sizeof(line), from)){
					if(i == (7*(codigo-1))+5){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Editoras.txt");
				rename("Editoras2.txt", "Editoras.txt");
				break;
		}
		printf("---------------------------------------------------------------------------------------------------------------\n");
		printf("| Deseja efetuar uma nova alteração?                                                                          |\n");
		printf("|-------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Sim                                                                                                     |\n");
		printf("| 2 - Não                                                                                                     |\n");
		printf("---------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void EditorasLista(){
	struct Editora{
		char codigo[6];
		char nomefantasia[71];
		char cnpj[25];
	};
	
	printf("| Lista de Editoras                                                                                          |\n");
	printf("|============================================================================================================|\n");

	struct Editora EditoraVar;
	if(NumeroLinhas("Editoras.txt") == 0){
		printf("Não há Editoras registrados.");
	}else{
		
		printf("| %6s     %-40s   %-40s             |\n", "CÓDIGO", "NOME", "CNPJ");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Editoras.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(EditoraVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(EditoraVar.nomefantasia, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(EditoraVar.cnpj, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 7){
				printf("| %6s     %-40s   %-40s             |\n", EditoraVar.codigo, EditoraVar.nomefantasia, EditoraVar.cnpj);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");
	}
}

void EditorasRelatorio(){
		struct Editora{
		char codigo[6];
		char nomefantasia[71];
		char cnpj[25];
	};
	remove("EditorasRel.txt");
	FILE *rel = fopen("EditorasRel.txt", "w");
	fprintf(rel, "========================================================================================\n");
	fprintf(rel, "|                                            Lista de Editoras                         |\n");
	fprintf(rel, "|======================================================================================|\n");
	struct Editora EditoraVar;
	if(NumeroLinhas("Editoras.txt") == 0){
		printf("Não há Editoras registrados.");
	}else{
		fprintf(rel, "| %6s     %-40s   %-30s |\n", "CÓDIGO", "NOME", "CNPJ");
		fprintf(rel, "|--------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Editoras.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(EditoraVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(EditoraVar.nomefantasia, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(EditoraVar.cnpj, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 7){
				fprintf(rel, "| %6s     %-40s   %-30s |\n", EditoraVar.codigo, EditoraVar.nomefantasia, EditoraVar.cnpj);
				i = 0;
			}
		}
		fclose(f);
		fprintf(rel, "========================================================================================\n");
		fclose(rel);
		
		printf("==============================================================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		getch();
	}
}

void Pedidos(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoPedido;
		
		printf("==============================================================================================================\n");
		printf("| Pedidos                                                                                                    |\n");
		printf("|============================================================================================================|\n");
		EditorasLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Novo Pedido                                                                                            |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Registrar Chegada                                                                                      |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");

		scanf("%d", &opcaoPedido);
		while(opcaoPedido < 1 || opcaoPedido > 5){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoPedido);
		}
		switch(opcaoPedido){
			case 1:
				system("cls");
				PedidosCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				//PedidosConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				//PedidosAlteracao();
				continua = 0;
				break;
			case 4:
				system("cls");
				//PedidosRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void PedidosCadastro(){
	
	struct Itens{
		int codigo;
		int quantidade;
	};
	struct Itens ItensVar[NumeroLinhas("Livros.txt") / 7];
	
	int codigoEditora;
	printf("================================================================================================================================================\n");
	printf("| Cadastro de Pedidos.                                                                                                                         |\n");
	printf("|==============================================================================================================================================|\n");
	printf("| Editoras disponíveis:                                                                                                                        |\n");
	EditoraListaNome();
	printf("| Digite o código da editora do Pedido:                                                                                                        |\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------\n  ");
	scanf("%d", &codigoEditora);
	while(codigoEditora > NumeroLinhas("Editoras.txt") / 7 || codigoEditora < 1){
		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| Não existe uma Editora registrado com o código %-5d                                                                                         |\n", codigoEditora);
		printf("| Digite o código da Editora que deseja consultar:                                                                                             |\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &codigoEditora);
	}
	printf("================================================================================================================================================\n");
	printf("| Livros disponíveis:                                                                                                                          |\n");
	int codigos[NumeroLinhas("Livros.txt") / 7];
	LivrosListaNome(codigoEditora, codigos);

	int i = 0;
	int j = 0;
	int continua = 0;
	while(continua == 0){
		printf("| Digite o código do livro:                                                                                                                    |\n");
		printf("|----------------------------------------------------------------------------------------------------------------------------------------------|\n  ");
		scanf("%d", &ItensVar[i].codigo);
		int existe = 0;
		while(!existe){
			existe = 0;
			j = 0;
			while(codigos[j] != 0){
				if(codigos[j] == ItensVar[i].codigo){
					existe = 1;
				}
				j++;
			}
			if(existe == 0){
				printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
				printf("| Não existe um livro com esse código na Editora escolhida.                                                                                    |\n");
				printf("| Digite o código do livro:                                                                                                                    |\n");
				printf("------------------------------------------------------------------------------------------------------------------------------------------------\n");
				scanf("%d", &ItensVar[i].codigo);
			}
		}
		printf("|----------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("| Digite a quantidade a ser inserida:                                                                                                          |\n");
		printf("|----------------------------------------------------------------------------------------------------------------------------------------------|\n  ");
		scanf("%d", &ItensVar[i].quantidade);
		existe = 0;
		j = 0;
		while(ItensVar[j].codigo != 0 && existe == 0){
			if(ItensVar[j].codigo == ItensVar[i].codigo && i != j){
				ItensVar[j].quantidade = ItensVar[j].quantidade + ItensVar[i].quantidade; 
				ItensVar[i].codigo = 0;
				ItensVar[i].quantidade = 0;
				existe = 1;
			}
			j++;
		}
		if(existe == 0){
			i++;
		}
		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n  ");
		printf("| Deseja adicionar mais um livro?                                                                                                              |\n");
		printf("| 1 - Sim                                                                                                                                      |\n");
		printf("| 2 - Não                                                                                                                                      |\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		
	}
	
	char emissao[11];
	retornarData(emissao);
	
	int codigoo = NumeroLinhas("Pedidos.txt") / 9 + 1;
	FILE *f = fopen("Pedidos.txt", "a");
	fprintf(f, "%d\n", codigoo);	    
	fprintf(f, "%d\n", codigoEditora);
	fprintf(f, "%s\n", emissao);
	fprintf(f, "0\n");
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	
	j = 0;
	f = fopen("LivrosPedidos.txt", "a");
	while(j < i){
		fprintf(f, "%d\n", codigoo);	    
		fprintf(f, "%d\n", ItensVar[j].codigo);
		fprintf(f, "%d\n", ItensVar[j].quantidade);
		fprintf(f, "-----------------------------------------------------------------\n");
		j++;
	}
	fclose(f);
	
	
	getch();
	system("cls");
}

void Livros(){
	system("cls");
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoLivro;
		printf("==============================================================================================================\n");
		printf("| Livros                                                                                                     |\n");
		printf("|============================================================================================================|\n");
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Nossos Livros                                                                                          |\n");
		printf("| 2 - Estoque                                                                                                |\n");
		printf("| 3 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		
		scanf("%d", &opcaoLivro);
		while(opcaoLivro < 1 || opcaoLivro > 3){
			printf("\nDigite uma opção válida. (Valores de 1 a 3)\n");
			scanf("%d", &opcaoLivro);
		}
		switch(opcaoLivro){
			case 1:
				system("cls");
				NossosLivros();
				continua = 0;
				break;
			case 2:
				system("cls");
				Estoque();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void NossosLivros(){
	system("cls");
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoLivro;
		
		printf("|============================================================================================================|\n");
		printf("| Nossos Livros                                                                                              |\n");
		printf("|============================================================================================================|\n");
		LivrosLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Cadastrar                                                                                              |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Alterar                                                                                                |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");
		
		
		
		scanf("%d", &opcaoLivro);
		while(opcaoLivro < 1 || opcaoLivro > 5){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoLivro);
		}
		switch(opcaoLivro){
			case 1:
				system("cls");
				LivrosCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				LivrosConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				LivrosAlteracao();
				continua = 0;
				break;
			case 4:
				system("cls");
				LivrosRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void LivrosCadastro(){
	
	struct Livro{
		char 	nome[71];
		int  	edicao;
		int  	paginas;
		double	compra;
		double	venda;
		int  	editora;
		char 	idioma[51];
		char 	genero[51];
		char 	autor[51];
		char 	ISBN[14];
	};
	
	
	struct Livro LivroVar;
	
	printf("======================================================\n");
	printf("| Cadastro de Livros.                                |\n");
	printf("|====================================================|\n");
	printf("| Digite o nome do Livro:                            |\n");
	printf("|----------------------------------------------------|\n  ");
	fflush(stdin);
	gets(LivroVar.nome);
	printf("|----------------------------------------------------|\n");
	printf("| Digite a edição do Livro:                          |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%d", &LivroVar.edicao);
	printf("|----------------------------------------------------|\n");
	printf("| Digite a quantidade de páginas do Livro:           |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%d", &LivroVar.paginas);
	printf("|----------------------------------------------------|\n");
	printf("| Digite o valor de compra do Livro:                 |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%lf", &LivroVar.compra);
	printf("|----------------------------------------------------|\n");
	printf("| Digite o valor de venda do Livro:                  |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%lf", &LivroVar.venda);
	printf("|----------------------------------------------------|\n");
	printf("| Digite o código da Editora do Livro:               |\n");
	printf("|----------------------------------------------------|\n  ");
	EditoraListaNome();
	scanf("%d", &LivroVar.editora);
	while(LivroVar.editora < 1 || LivroVar.editora > NumeroLinhas("Editoras.txt") / 7){
		printf("| Não existe um Editora registrado com o código %-4d |\n", LivroVar.editora);
		printf("| Digite o código da Editora do Livro:               |\n");
		printf("|----------------------------------------------------|\n  ");
		EditoraListaNome();
		scanf("%d", &LivroVar.editora);
	}             
	printf("|----------------------------------------------------|\n");
	printf("| Digite o idioma do Livro:                          |\n");
	printf("|----------------------------------------------------|\n  ");
	
	fflush(stdin);                      
	gets(LivroVar.idioma);  
	printf("|----------------------------------------------------|\n");
	printf("| Digite o genero do Livro:                          |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(LivroVar.genero);      
	printf("|----------------------------------------------------|\n");
	printf("| Digite o nome doª autorª do Livro:                 |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(LivroVar.autor);       
	printf("|----------------------------------------------------|\n");
	printf("| Digite o ISBN (Código de Barras) do Livro:         |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(LivroVar.ISBN); 
	
	int codigo = NumeroLinhas("Livros.txt") / 9 + 1;
	FILE *f = fopen("Livros.txt", "a");
	fprintf(f, "%d\n", codigo);	    
	fprintf(f, "%s\n", LivroVar.nome);
	fprintf(f, "%d\n", LivroVar.edicao);	    
	fprintf(f, "%d\n", LivroVar.paginas);	    
	fprintf(f, "%.2lf\n", LivroVar.compra);	    
	fprintf(f, "%.2lf\n", LivroVar.venda);	    
	fprintf(f, "%d\n", LivroVar.editora);	    
	fprintf(f, "%s\n", LivroVar.idioma);
	fprintf(f, "%s\n", LivroVar.genero);
	fprintf(f, "%s\n", LivroVar.autor);
	fprintf(f, "%s\n", LivroVar.ISBN); 
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	
	FILE *ff = fopen("Estoque.txt", "a");
	fprintf(ff, "%d\n", codigo);	    
	fprintf(ff, "0\n");
	fprintf(ff, "-----------------------------------------------------------------\n");
	fclose(ff);
}

void LivrosConsulta(){
	int continua = 0;
	while(continua == 0){
		printf("============================================================\n");
		printf("| Consulta de Livros.                                      |\n");
		printf("|==========================================================|\n");
		printf("| Digite o código do Livro que deseja consultar:           |\n");
		printf("------------------------------------------------------------\n  ");
		
		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Livros.txt") / 12){
			printf("------------------------------------------------------------\n");
			printf("| Não existe um Livro registrado com o código %-5d         |\n", codigo);
			printf("| Digite o código do Livro que deseja consultar:           |\n");
			printf("------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("=============================================================\n");
		printf("| Dados do Livro                                            |\n");
		printf("|===========================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (12*(codigo-1))){
				printf("| Código:          %-40s |\n", strtok(line,"\n"));
			}
			if(i == (12*(codigo-1))+1){
				printf("| Nome:            %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+2){
				printf("| Edição:          %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+3){
				printf("| Páginas:         %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (1123*(codigo-1))+4){
				printf("| Valor de Compra: R$ %-37s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+5){
				printf("| Valor de Venda:  R$ %-37s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+6){
				EditoraConsultarNome(atoi(strtok(line,"\n")));
			}
						
			if(i == (12*(codigo-1))+7){
				printf("| Idioma:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+8){
				printf("| Gênero:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+9){
				printf("| Autorª:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+10){
				printf("| ISBN:            %-40s |\n", strtok(line,"\n"));
			}
			i++;
		}
		fclose(f);
		
		printf("|-----------------------------------------------------------|\n");
		fclose(f);
		printf("| Deseja efetuar uma nova consulta?                         |\n");
		printf("| 1 - Sim                                                   |\n");
		printf("| 2 - Não                                                   |\n");
		printf("-------------------------------------------------------------\n  ");
		
		
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void LivrosAlteracao(){
	int continua = 0;
	while(continua == 0){
		printf("============================================================\n");
		printf("| Alteração de Livros.                                     |\n");
		printf("|==========================================================|\n");
		printf("| Digite o código do Livro que deseja alterar:             |\n");
		printf("------------------------------------------------------------\n  ");
		

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Livros.txt") / 7){
			printf("------------------------------------------------------------\n");
			printf("| Não existe um Livro registrado com o código %-5d         |\n", codigo);
			printf("| Digite o código do Livro que deseja alterar:             |\n");
			printf("------------------------------------------------------------\n  ");
			
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("=============================================================\n");
		printf("| Dados do Livro                                            |\n");
		printf("|===========================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (12*(codigo-1))){
				printf("| Código:          %-40s |\n", strtok(line,"\n"));
			}
			if(i == (12*(codigo-1))+1){
				printf("| Nome:            %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+2){
				printf("| Edição:          %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+3){
				printf("| Páginas:         %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (1123*(codigo-1))+4){
				printf("| Valor de Compra: R$ %-37s |\n", strtok(line,"\n"));
			}
			
			if(i == (12*(codigo-1))+5){
				printf("| Valor de Venda:  R$ %-37s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+6){
				EditoraConsultarNome(atoi(strtok(line,"\n")));
			}
						
			if(i == (12*(codigo-1))+7){
				printf("| Idioma:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+8){
				printf("| Gênero:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+9){
				printf("| Autorª:          %-40s |\n", strtok(line,"\n"));
			}
						
			if(i == (12*(codigo-1))+10){
				printf("| ISBN:            %-40s |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("==============================================================================================================\n");
		fclose(f);
		int opcaoalteracao;
		printf("|  Digite o dado que deseja alterar                                                                          |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		printf("|  1 - Nome                                                                                                  |\n");
		printf("|  2 - Edição                                                                                                |\n");
		printf("|  3 - Páginas                                                                                               |\n");
		printf("|  4 - Valor de compra                                                                                       |\n");
		printf("|  5 - Valor de venda                                                                                        |\n");
		printf("|  6 - Editora                                                                                               |\n");
		printf("|  7 - Idioma                                                                                                |\n");
		printf("|  8 - Gênero                                                                                                |\n");
		printf("|  9 - Autorª                                                                                                |\n");
		printf("| 10 - ISBN                                                                                                  |\n");
		printf("==============================================================================================================\n  ");
		
		
		scanf("%d", &opcaoalteracao);
		char novodado[100];
		FILE *from = fopen("Livros.txt", "r");
		FILE *to = fopen("Livros2.txt", "w");
		i = 0;
		fflush(stdin);
		switch(opcaoalteracao){
			case 1:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Nome:                                                                                         |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+1){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 2:
				printf("===============================================================================================================\n");
				printf("| Digite a novo Edição:                                                                                       |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+2){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;
			case 3:
				printf("===============================================================================================================\n");
				printf("| Digite a nova Quantidade de Páginas:                                                                        |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				gets(novodado);
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+3){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;
			case 4:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Valor de Compra:                                                                              |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+4){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 5:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Valor de Venda:                                                                               |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+5){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 6:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Código da Editora:                                                                            |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				while(atoi(novodado) < 1 || atoi(novodado) > NumeroLinhas("Editoras.txt") / 7){
					printf("| Não existe uma Editora registrado com este código                                                          |\n");
					printf("| Digite o novo Código da Editora:                                                                           |\n");
					printf("|------------------------------------------------------------------------------------------------------------|\n  ");
					gets(novodado);
				}
				
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+6){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 7:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Idioma:                                                                                       |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+7){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 8:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Gênero:                                                                                       |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+8){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 9:
				printf("===============================================================================================================\n");
				printf("| Digite o novo Autorª:                                                                                       |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+9){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;			
			case 10:
				printf("===============================================================================================================\n");
				printf("| Digite o novo ISBN:                                                                                         |\n");
				printf("---------------------------------------------------------------------------------------------------------------\n  ");
				
				gets(novodado);
				
				while(fgets(line, sizeof(line), from)){
					if(i == (12*(codigo-1))+10){
						fprintf(to, "%s\n", novodado);
					}else{
						fprintf(to, "%s\n", strtok(line,"\n"));
					}
					i++;
				}
				fclose(from);
				fclose(to);
				remove("Livros.txt");
				rename("Livros2.txt", "Livros.txt");
				break;
			
		}
		printf("Deseja efetuar uma nova alteração?\n\n1 - Sim\n2 - Não\n");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void LivrosLista(){
	struct Livro{
		char codigo[6];
		char nome[71];
		char autor[51];
		char compra[8];
		char venda[8];
	};
	
	printf("| Lista de Livros                                                                                            |\n");
	printf("|============================================================================================================|\n");
	struct Livro LivroVar;
	if(NumeroLinhas("Livros.txt") == 0){
		printf("Não há Livros registrados.");
	}else{
		
		
		
		printf("| %6s     %-40s   %-20s   %-10s   %-9s        |\n", "CÓDIGO", "NOME", "AUTOR", "VL. COMPRA", "VL. VENDA");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(LivroVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(LivroVar.nome, strtok(line,"\n"));	
					break;
				case 9:
					strcpy(LivroVar.autor, strtok(line,"\n"));	
					break;
				case 4:
					strcpy(LivroVar.compra, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(LivroVar.venda, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 12){
				printf("| %6s     %-40s   %-20s   %10s   %9s        |\n", LivroVar.codigo, LivroVar.nome, LivroVar.autor, LivroVar.compra, LivroVar.venda);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");
	}
}

void LivrosRelatorio(){
	struct Livro{
		char codigo[6];
		char nome[71];
		char autor[51];
		char compra[8];
		char venda[8];
	};
	
	remove("LivrosRel.txt");
	FILE *rel = fopen("LivrosRel.txt", "w");
	fprintf(rel, "==============================================================================================================\n");
	fprintf(rel, "|                                                   Lista de Livros                                          |\n");
	fprintf(rel, "|============================================================================================================|\n");
	struct Livro LivroVar;
	if(NumeroLinhas("Livros.txt") == 0){
		fprintf(rel, "Não há Livros registrados.");
	}else{
		
		
		
		fprintf(rel, "| %6s     %-40s   %-20s   %-10s   %-9s        |\n", "CÓDIGO", "NOME", "AUTOR", "VL. COMPRA", "VL. VENDA");
		fprintf(rel, "|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(LivroVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(LivroVar.nome, strtok(line,"\n"));	
					break;
				case 9:
					strcpy(LivroVar.autor, strtok(line,"\n"));	
					break;
				case 4:
					strcpy(LivroVar.compra, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(LivroVar.venda, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 12){
				fprintf(rel, "| %6s     %-40s   %-20s   %10s   %9s        |\n", LivroVar.codigo, LivroVar.nome, LivroVar.autor, LivroVar.compra, LivroVar.venda);
				i = 0;
			}
		}
		fclose(f);
		fprintf(rel, "|============================================================================================================|\n");
	fclose(rel);
		
		printf("==============================================================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		getch();
		}
}

void Estoque(){
	struct Estoque{
		char codigo[6];
		char nome[71];
		char quantidade[10];
	};
	printf("====================================================================\n");
	printf("| Livros em estoque                                                |\n");
	printf("|==================================================================|\n");
	struct Estoque EstoqueVar;
	if(NumeroLinhas("Livros.txt") == 0){
		printf("Não há Livros registrados.");
	}else{
		printf("| %-6s     %-40s   %-10s |\n", "CÓDIGO", "NOME", "QUANTIDADE");
		printf("|------------------------------------------------------------------|\n");
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		int j = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(EstoqueVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(EstoqueVar.nome, strtok(line,"\n"));	
					break;
			}
			
			FILE *ff = fopen("Estoque.txt", "r");
			char codigo[5];
			char line2[100];
			int ii = 0;
			while(fgets(line2, sizeof(line2), ff)){
				switch(ii){
					case 0:
						strcpy(codigo, strtok(line2,"\n"));	
						break;
					case 1:
						if(strcmp(EstoqueVar.codigo, codigo) == 0){
							strcpy(EstoqueVar.quantidade, strtok(line2,"\n"));		
						}
						break;
				}
				ii++;
				if(ii == 3){
					ii = 0;
				}
			}
			i++;
			if(i == 12){
				if(atoi(EstoqueVar.quantidade) < 10){
					SetColor(15);
					printf("| ");
					SetColor(4);
				}else if(atoi(EstoqueVar.quantidade) < 20){
					SetColor(15);
					printf("| ");
					SetColor(14);
				}else{
					printf("| ");
				}
				printf("%6s     %-40s   %10s", EstoqueVar.codigo, EstoqueVar.nome, EstoqueVar.quantidade);
				SetColor(15);
				printf(" |\n");
				i = 0;
			}
		}
		fclose(f);
	}
	printf("|==================================================================|\n| ");
	SetColor(4);
	printf("* ");
	SetColor(15);
	  printf("Abaixo de 10                                                   |\n| ");
	SetColor(14);
	printf("* ");
	SetColor(15);
	  printf("Abaixo de 20                                                   |\n| ");
	printf("* ");
	  printf("Acima  de 20                                                   |\n");
	printf("| Escolha uma opção:                                               |\n");
	printf("|------------------------------------------------------------------|\n");
	printf("| 1 - Gerar Relatório                                              |\n");
	printf("| 3 - Voltar                                                       |\n");
	printf("--------------------------------------------------------------------\n  ");


	int relato = 0;
	scanf("%d", &relato);
	if(relato == 1){
		EstoqueRelatorio();
	}
}

void EstoqueRelatorio(){
	struct Estoque{
		char codigo[6];
		char nome[71];
		char quantidade[10];
	};
	
	remove("EstoqueRel.txt");
	FILE *rel = fopen("EstoqueRel.txt", "w");
	fprintf(rel, "====================================================================\n");
	fprintf(rel, "|                         Lista de estoque                         |\n");
	fprintf(rel, "|==================================================================|\n");
	
	struct Estoque EstoqueVar;

	if(NumeroLinhas("Livros.txt") == 0){
		printf("Não há Livros registrados.");
	}else{
		fprintf(rel, "| %-6s     %-40s   %-10s |\n", "CÓDIGO", "NOME", "QUANTIDADE");
		fprintf(rel, "|------------------------------------------------------------------|\n");
		FILE *f = fopen("Livros.txt", "r");
		char line[100];
		int i = 0;
		int j = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(EstoqueVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(EstoqueVar.nome, strtok(line,"\n"));	
					break;
			}
			
			FILE *ff = fopen("Estoque.txt", "r");
			char codigo[5];
			char line2[100];
			int ii = 0;
			while(fgets(line2, sizeof(line2), ff)){
				switch(ii){
					case 0:
						strcpy(codigo, strtok(line2,"\n"));	
						break;
					case 1:
						if(strcmp(EstoqueVar.codigo, codigo) == 0){
							strcpy(EstoqueVar.quantidade, strtok(line2,"\n"));		
						}
						break;
				}
				ii++;
				if(ii == 3){
					ii = 0;
				}
			}
			i++;
			if(i == 12){
				if(atoi(EstoqueVar.quantidade) < 10){
					SetColor(15);
					fprintf(rel, "| ");
					SetColor(4);
				}else if(atoi(EstoqueVar.quantidade) < 20){
					SetColor(15);
					fprintf(rel, "| ");
					SetColor(14);
				}
				fprintf(rel, "%6s     %-40s   %10s", EstoqueVar.codigo, EstoqueVar.nome, EstoqueVar.quantidade);
				SetColor(15);
				fprintf(rel, " |\n");
				i = 0;
			}
		}
		fclose(f);
	}
	fprintf(rel, "====================================================================\n");
	fclose(rel);
	
	printf("==============================================================================================================\n");
	printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
	getch();
}

void EditoraConsultarNome(int codigo){
	char nome[100];
	FILE *f = fopen("Editoras.txt", "r");
	char line[100];
	int i = 0;
	while(fgets(line, sizeof(line), f)){
		if(i == (8*(codigo-1))){
			printf("| Editora:         %d - %-36s |\n", codigo, strtok(line,"\n"));
		}
		i++;
	}
	fclose(f);
}

void EditoraListaNome(){
	FILE *f = fopen("Editoras.txt", "r");
	char line[100];
	int i = 0;
	int j = 1;
	while(fgets(line, sizeof(line), f)){
		
		if(i == 1){
			if(j == 1){
				printf("| ");
			}
			printf("%d - %-40s   ", j, strtok(line,"\n"));
			if(j%3 == 0){
				printf("|\n| ");
			}
			j++;
		}
		i++;
		if(i == 7){
			i = 0;
		}
	}
	
	
	
	if(j%3 == 0){
		printf("%c   %-40s   ", ' ', " ");
	}else if(j%2 == 0){
		printf("%c   %-40s   ", ' ', " ");
		printf("%c   %-40s   |\n", ' ', " ");
	}
	printf("|----------------------------------------------------------------------------------------------------------------------------------------------|\n");
	
	
	fclose(f);
}

void LivrosListaNome(int CodigoEditora, int *Codigos){
	FILE *f = fopen("Livros.txt", "r");
	char line[100];
	int i = 0;
	int j = 1;
	int codProd;
	char nomeProd[40];
	printf("| ");
	int codigos[NumeroLinhas("Livros.txt") / 7];
	while(fgets(line, sizeof(line), f)){
		
		if(i == 0){
			codProd = atoi(strtok(line,"\n"));
		}
		
		if(i == 1){
			strcpy(nomeProd, strtok(line,"\n"));
		}
		
		if(i == 6){
			if(atoi(strtok(line,"\n")) == CodigoEditora){
				if(j % 3 == 0){
					printf("\n| ");
				}
				printf("%d   %-40s   ", codProd, nomeProd);
				Codigos[j - 1] = codProd;
				j++;
			}
		}
		
		
		
		if(i == 11){
			i = -1;
		}
		
		i++;
	}
	
	if(j%3 == 0){
		printf("%c   %-40s   ", ' ', " ");
	}else if(j%2 == 0){
		printf("%c   %-40s   ", ' ', " ");
		printf("%c   %-40s   |\n", ' ', " ");
	}
	
	
	printf("\n|----------------------------------------------------------------------------------------------------------------------------------------------|\n");
		
	fclose(f);
}
 
void Vendas(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoConta;
		printf("==============================================================================================================\n");
		printf("| Vendas                                                                                                     |\n");
		printf("|============================================================================================================|\n");
		VendasLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Nova Venda                                                                                             |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Gerar Relatório                                                                                        |\n");
		printf("| 4 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");

		scanf("%d", &opcaoConta);
		while(opcaoConta < 1 || opcaoConta > 4){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoConta);
		}
		//Condição para entrar em uma função
		switch(opcaoConta){
			case 1:
				system("cls");
				VendasCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				//VendasConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				VendasRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}
 
void VendasCadastro(){
	//Struct para os dados do livro
	struct Livros{
		int codigo;
		int quantidade;
	};
	
	struct Livros LivrosVar[100];
	
	//Struct com os dados da venda
	struct Venda{
		char codFuncionario[11];
		char codCliente[11];
		char emissao[11];	
	};
	
	int continua = 1, i = 0, j = 0;
	
	struct Venda VendaVar;
	printf("==============================================================================================================\n");
	printf("| Cadastro de venda.                                                                                         |\n");
	printf("|============================================================================================================|\n");
	printf("| Digite o codigo do funcionario:                                                                            |\n"); 
	printf("|------------------------------------------------------------------------------------------------------------|\n");
 
 	FuncionariosLista();
	fflush(stdin);
	printf("  ");
	gets(VendaVar.codFuncionario);
	
	fflush(stdin);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Digite o codigo do cliente                                                                                 |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	
	ClientesLista();
	printf("  ");
	gets(VendaVar.codCliente);
	
	retornarData(VendaVar.emissao);
	
	while(continua == 1){
		
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| Digite o codigo do livro:                                                                                  |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		LivrosLista();
		printf("  ");	
		scanf("%d", &LivrosVar[i].codigo);
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| Digite a quantidade de livros:                                                                             |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		scanf("%d", &LivrosVar[i].quantidade);
		
		
 
 		while(LivrosVar[i].codigo < 1){
			printf("| Não existe um Livro registrado com o código %-4d                                                           |\n", LivrosVar[i].codigo);
			printf("| Digite o código do Livro:                                                                                  |\n");
			printf("|------------------------------------------------------------------------------------------------------------|\n  ");
			LivrosLista();
			scanf("%d", &LivrosVar[i].codigo);
			scanf("%d", &LivrosVar[i].quantidade);
		} 
		
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| Deseja adicionar mais livros:                                                                              |\n");
		printf("| 1 - Sim                                                                                                    |\n");
		printf("| 2 - Não                                                                                                    |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n  ");
		scanf("%d", &continua);
	
		i++;
		
	}
	
	
	
	int codigo = NumeroLinhas("Vendas.txt") / 5 + 1;
	FILE *f = fopen("Vendas.txt", "a");
	
	fprintf(f, "%d\n", codigo);	    
	fprintf(f, "%s\n", VendaVar.codFuncionario);
	fprintf(f, "%s\n", VendaVar.codCliente);
	fprintf(f, "%s\n", VendaVar.emissao);
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	f = fopen("LivrosVenda.txt", "a");
	while(i != 0){
		
		if(LivrosVar[j].codigo != 0){
			fprintf(f, "%d\n", codigo);	    
			fprintf(f, "%d\n", LivrosVar[j].codigo); 
			fprintf(f, "%d\n", LivrosVar[j].quantidade);
			fprintf(f, "-----------------------------------------------------------------\n");
			i--;
			j++;
		}
	}
	fclose(f);
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	printf("| Venda registrada com sucesso. Pressione qualquer tecla para continuar.                                     |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	getch();
	system("cls");
}

void VendasLista(){
	struct Venda{
		char codigo[11];
		int codCliente;
		char nomeCliente[41];
		int codFuncionario;
		char nomeFuncionario[41];
		char emissao[11];
	};
	
	printf("| Lista de Vendas                                                                                            |\n");
	printf("|============================================================================================================|\n");
	
	struct Venda VendaVar;
	
	if(NumeroLinhas("Vendas.txt") == 0){
	printf("| Não há vendas registradas.                                                                                 |\n");
	printf("|------------------------------------------------------------------------------------------------------------|\n");
	}else{
		printf("| %6s    %-40s   %-40s   %-10s |\n", "CÓDIGO", "FUNCIONARIO", "CLIENTE", "EMISSÃO");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Vendas.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(VendaVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					VendaVar.codFuncionario = atoi(strtok(line,"\n"));
					RetornarNomeFuncionario(VendaVar.codFuncionario, &VendaVar.nomeFuncionario);
					break;
				case 2:
					VendaVar.codCliente = atoi(strtok(line,"\n"));
					RetornarNomeCliente(VendaVar.codCliente, &VendaVar.nomeCliente);
					break;
				case 3:
					strcpy(VendaVar.emissao, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 5){
				printf("| %6s    %-40s   %-40s   %-10s |\n", VendaVar.codigo, VendaVar.nomeFuncionario, VendaVar.nomeCliente, VendaVar.emissao);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");

	}
}

void VendasRelatorio(){
	struct Venda{
		char codigo[11];
		int codCliente;
		char nomeCliente[41];
		int codFuncionario;
		char nomeFuncionario[41];
		char emissao[11];
	};
	remove("VendasRel.txt");
	FILE *rel = fopen("VendasRel.txt", "w");
    fprintf(rel, "==============================================================================================================\n");
    fprintf(rel, "|                                          Lista de Vendas                                                   |\n");
	fprintf(rel, "|============================================================================================================|\n");
	
	struct Venda VendaVar;
	
	if(NumeroLinhas("Vendas.txt") == 0){
	printf("Não há vendas registradas.                                                                                 |\n");
	}else{
		fprintf(rel, "| %6s    %-40s   %-40s   %-10s |\n", "CÓDIGO", "FUNCIONARIO", "CLIENTE", "EMISSÃO");
		fprintf(rel, "|------------------------------------------------------------------------------------------------------------|\n");
        FILE *f = fopen("Vendas.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(VendaVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					VendaVar.codFuncionario = atoi(strtok(line,"\n"));
					RetornarNomeFuncionario(VendaVar.codFuncionario, &VendaVar.nomeFuncionario);
					break;
				case 2:
					VendaVar.codCliente = atoi(strtok(line,"\n"));
					RetornarNomeCliente(VendaVar.codCliente, &VendaVar.nomeCliente);
					break;
				case 3:
					strcpy(VendaVar.emissao, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 5){
				fprintf(rel, "| %6s    %-40s   %-40s   %-10s |\n", VendaVar.codigo, VendaVar.nomeFuncionario, VendaVar.nomeCliente, VendaVar.emissao);
				i = 0;
			}
		}
		fclose(f);
	fprintf(rel, "==============================================================================================================\n");
		fclose(rel);
		
		printf("==============================================================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar                                         |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n");
		getch();
	}
}

void Contas(){
	int continua = 0;
	while(continua == 0){
		system("cls");
		int opcaoConta;
		
		printf("==============================================================================================================\n");
		printf("| Contas                                                                                                     |\n");
		printf("|============================================================================================================|\n");
		ContasLista();
		printf("| Escolha uma opção:                                                                                         |\n");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		printf("| 1 - Nova Conta                                                                                             |\n");
		printf("| 2 - Consultar                                                                                              |\n");
		printf("| 3 - Registrar Pagamento                                                                                    |\n");
		printf("| 4 - Gerar Relatório                                                                                        |\n");
		printf("| 5 - Voltar                                                                                                 |\n");
		printf("--------------------------------------------------------------------------------------------------------------\n  ");

		scanf("%d", &opcaoConta);
		while(opcaoConta < 1 || opcaoConta > 5){
			printf("\nDigite uma opção válida. (Valores de 1 a 5)\n");
			scanf("%d", &opcaoConta);
		}
		switch(opcaoConta){
			case 1:
				system("cls");
				ContasCadastro();
				continua = 0;
				break;
			case 2:
				system("cls");
				ContasConsulta();
				continua = 0;
				break;
			case 3:
				system("cls");
				ContasPagamento();
				continua = 0;
				break;
			case 4:
				system("cls");
				ContasRelatorio();
				continua = 0;
				break;
			default:
				continua = 1;
				break;
		}
	}
}

void ContasCadastro(){
	
	struct Conta{
		char destino[41];
		char numerodocumento[51];
		double valor;
		int parcelas;
		char emissao[11];
		char pagamento[11];
	};
	
	
	struct Conta ContaVar;
	
	printf("======================================================\n");
	printf("| Cadastro de Contas.                                |\n");
	printf("|====================================================|\n");
	printf("| Digite o destino da conta:                         |\n");
	printf("|----------------------------------------------------|\n  ");
	fflush(stdin);
	fgets(ContaVar.destino,41,stdin);
	fflush(stdin);
	printf("|----------------------------------------------------|\n");
	printf("| Digite o número do documento da conta:             |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(ContaVar.numerodocumento);
	printf("|----------------------------------------------------|\n");
	printf("| Digite o valor da conta:                           |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%lf", &ContaVar.valor);
	fflush(stdin);
	printf("|----------------------------------------------------|\n");
	printf("| Digite a quantidade de parcelas da conta:          |\n");
	printf("|----------------------------------------------------|\n  ");
	scanf("%d", &ContaVar.parcelas);
	fflush(stdin);
	printf("|----------------------------------------------------|\n");
	printf("| Digite a data de emissão da conta:                 |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(ContaVar.emissao);
	printf("|----------------------------------------------------|\n");
	printf("| Digite a data de pagamento da conta:               |\n");
	printf("| (Digite 0 caso a conta não tenha sido paga)        |\n");
	printf("|----------------------------------------------------|\n  ");
	gets(ContaVar.pagamento);
	
	int codigo = NumeroLinhas("Contas.txt") / 8 + 1;
	FILE *f = fopen("Contas.txt", "a");
	fprintf(f, "%d\n", codigo);	    
	
	if(strlen(ContaVar.destino) == 40){
		fprintf(f, "%s\n", ContaVar.destino);
	}else{
		fprintf(f	, "%s", ContaVar.destino);
	}
	fprintf(f, "%s\n", ContaVar.numerodocumento);
	fprintf(f, "%.2lf\n", ContaVar.valor);
	fprintf(f, "%d\n", ContaVar.parcelas);
	fprintf(f, "%s\n", ContaVar.emissao);
	if(strcmp(ContaVar.pagamento, "0") == 0){
		fprintf(f, "%s\n", "NÃO PAGA");      
	}else{	
		fprintf(f, "%s\n", ContaVar.pagamento);      
	}
	fprintf(f, "-----------------------------------------------------------------\n");
	fclose(f);
	printf("  Conta registrada com sucesso. Pressione qualquer tecla para continuar.");
	getch();
	system("cls");
}

void ContasConsulta(){
	int continua = 0;
	while(continua == 0){
		
		
		printf("============================================================\n");
		printf("| Consulta de Contas.                                      |\n");
		printf("|==========================================================|\n");
		printf("| Digite o código da Conta que deseja consultar:           |\n");
		printf("------------------------------------------------------------\n  ");

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Contas.txt") / 7){
			printf("------------------------------------------------------------\n");
			printf("| Não existe uma Conta registrado com o código %-6d |\n", codigo);
			printf("| Digite o código da Conta que deseja consultar:           |\n");
			printf("------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *f = fopen("Contas.txt", "r");
		char line[100];
		int i = 0;
		system("cls");
		printf("================================================================\n");
		printf("| Dados da Conta                                               |\n");
		printf("|==============================================================|\n");
		while(fgets(line, sizeof(line), f)){
			if(i == (7*(codigo-1))){
				printf("| Código:             %-40s |\n", strtok(line,"\n"));
			}
			if(i == (7*(codigo-1))+1){
				printf("| Destino:            %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+2){
				printf("| Num. do documento:  %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+3){
				printf("| Valor:              R$ %-37s |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+4){
				printf("| Parcelas:           %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+5){
				printf("| Data de Emissão:    %-40s |\n", strtok(line,"\n"));
			}
			
			if(i == (7*(codigo-1))+6){
				printf("| Data de Pagamento:  %-40s |\n", strtok(line,"\n"));
			}
			i++;
		}
		printf("|--------------------------------------------------------------|\n");
		fclose(f);
		printf("| Deseja efetuar uma nova consulta?                            |\n");
		printf("| 1 - Sim                                                      |\n");
		printf("| 2 - Não                                                      |\n");          
		printf("----------------------------------------------------------------\n  ");
		scanf("%d", &continua);
		continua--;
		system("cls");
	}
}

void ContasPagamento(){
		
		printf("============================================================\n");
		printf("| Registrar Pagamento.                                     |\n");
		printf("|==========================================================|\n");
		printf("| Digite o código da Conta que deseja registrar:           |\n");
		printf("------------------------------------------------------------\n  ");

		int codigo = 0;
		scanf("%d", &codigo);
		
		while(codigo < 1 || codigo > NumeroLinhas("Contas.txt") / 7){
			printf("------------------------------------------------------------\n");
			printf("| Não existe uma Conta registrada com o código %-6d |\n", codigo);
			printf("| Digite o código da Conta que deseja registrar:           |\n");
			printf("------------------------------------------------------------\n  ");
			scanf("%d", &codigo);
		}
	
		FILE *from = fopen("Contas.txt", "r");
		FILE *to = fopen("Contas2.txt", "w");
		fflush(stdin);
		char line[100];
		int i = 0;
		char novodado[11];
		retornarData(novodado);
		while(fgets(line, sizeof(line), from)){
			if(i == (7*(codigo-1))+6){
				fprintf(to, "%s\n", novodado);
			}else{
				fprintf(to, "%s\n", strtok(line,"\n"));
			}
			i++;
		}
		fclose(from);
		fclose(to);
		remove("Contas.txt");
		rename("Contas2.txt", "Contas.txt");
		printf("------------------------------------------------------\n");
		printf("| Pagamento registrado.                              |\n");
		printf("| Digite qualquer tecla para continuar               |\n");
		printf("------------------------------------------------------\n");
		getch();
}

void ContasLista(){
	struct Conta{
		char codigo[6];
		char destino[41];
		char valor[10];
		char emissao[11];
		char pagamento[11];
	};
	
	
		printf("| Lista de Contas                                                                                            |\n");
		printf("|============================================================================================================|\n");
	struct Conta ContaVar;
	if(NumeroLinhas("Contas.txt") == 0){
		printf("Não há Contas registrados.");
	}else{
		printf("| %6s     %-40s   %-12s   %-14s   %-20s |\n", "CÓDIGO", "DESTINO", "VALOR", "EMISSÃO", "PAGAMENTO");
		printf("|------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Contas.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(ContaVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(ContaVar.destino, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(ContaVar.valor, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(ContaVar.emissao, strtok(line,"\n"));	
					break;
				case 6:
					strcpy(ContaVar.pagamento, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 7){
				printf("| %6s     %-40s   %-12s   %-14s   %-20s |\n", ContaVar.codigo, ContaVar.destino, ContaVar.valor, ContaVar.emissao, ContaVar.pagamento);
				i = 0;
			}
		}
		fclose(f);
		printf("|============================================================================================================|\n");

	}
}

void ContasRelatorio(){
	struct Conta{
		char codigo[6];
		char destino[41];
		char valor[10];
		char emissao[11];
		char pagamento[11];
	};
	remove("ContasRel.txt");
	FILE *rel = fopen("ContasRel.txt", "w");
	fprintf(rel, "===============================================================================================================\n");
	fprintf(rel, "|                                            Lista de Contas                                                  |\n");
	fprintf(rel, "|=============================================================================================================|\n");
	struct Conta ContaVar;
	if(NumeroLinhas("Contas.txt") == 0){
		printf("Não há Contas registrados.");
	}else{
		fprintf(rel, "| %6s     %-40s   %-12s   %-14s   %-20s  |\n", "CÓDIGO", "DESTINO", "VALOR", "EMISSÃO", "PAGAMENTO");
		fprintf(rel, "|-------------------------------------------------------------------------------------------------------------|\n");
		FILE *f = fopen("Contas.txt", "r");
		char line[100];
		int i = 0;
		while(fgets(line, sizeof(line), f)){
			switch(i){
				case 0:
					strcpy(ContaVar.codigo, strtok(line,"\n"));	
					break;
				case 1:
					strcpy(ContaVar.destino, strtok(line,"\n"));	
					break;
				case 3:
					strcpy(ContaVar.valor, strtok(line,"\n"));	
					break;
				case 5:
					strcpy(ContaVar.emissao, strtok(line,"\n"));	
					break;
				case 6:
					strcpy(ContaVar.pagamento, strtok(line,"\n"));	
					break;
			}
			i++;
			if(i == 7){
				fprintf(rel, "| %6s     %-40s   %-12s   %-14s   %-20s  |\n", ContaVar.codigo, ContaVar.destino, ContaVar.valor, ContaVar.emissao, ContaVar.pagamento);
				i = 0;
			}
		}
		fclose(f);
		fprintf(rel, "===============================================================================================================\n");
		fclose(rel);
		
		printf("======================================================================\n");
		printf("| Relatório gerado com sucesso. Digite qualquer tecla para continuar |\n");
		printf("----------------------------------------------------------------------\n");
		getch();
	}
}

void RetornarNomeFuncionario(int codFuncionario, char *nomeFuncionario){
	FILE *f = fopen("Funcionários.txt", "r");
	char line[100];
	int i = 0;
	int achou = 0;
	while(fgets(line, sizeof(line), f) && achou == 0){

		if(i == (9*(codFuncionario-1))+1){
				strcpy(nomeFuncionario, strtok(line,"\n"));
				achou = 1;
		}
		i++;
	}
	fclose(f);
}

void RetornarNomeCliente(int codCliente, char *nomeCliente){
	FILE *f = fopen("Clientes.txt", "r");
	char line[100];
	int i = 0;
	int achou = 0;
	while(fgets(line, sizeof(line), f) && achou == 0){

		if(i == (8*(codCliente-1))+1){
				strcpy(nomeCliente, strtok(line,"\n"));
				achou = 1;
		}
		i++;
	}
	fclose(f);
}

int NumeroLinhas(char path[100]){
	FILE *f = fopen(path, "r");
	char line[100];
	int i = 0;
	while(fgets(line, sizeof(line), f)){
		i++;
	}
	fclose(f);
	return i;
}
	
int ValidarEmail(char email[]) {
	int tam=strlen(email);
	int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;	
	for (i = 0; i < tam; i++) {
		char c = email[i];
		if(c == '@') {
			if (arroba)
				break; // não pode ter uma segunda @
				arroba = 1;
			if (i < 3)
				break; // se @ vier antes de 3 caracteres, erro
		}
		else if (arroba) { // se já encontrou @
			if (ponto) { // se já encontrou . depois de @
		    	depoisPonto++;
		  	}
		  	else if(c == '.') {
		    	ponto = 1;
		    	if (antesPonto < 3) {
		     		break; // se . depois de @ vier antes de 3 caracteres, erro
		    	}
		  	}
		  	else {
		    	antesPonto++;
		  	}
		}
	} // for
	
	if (i == tam && depoisPonto > 1)
		return 1;
	else
		return 0;
}

void retornarData(char *data){
	char aux[4];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	itoa(tm.tm_mday, aux, 10);
	strcat(data, aux);
	strcat(data, "/");
	itoa(tm.tm_mon+1, aux, 10);
	strcat(data, aux);
	strcat(data, "/");
	itoa(tm.tm_year+1900, aux, 10);
	strcat(data, aux);
}

void SetColor(int ForgC){
 WORD wColor;
  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}


