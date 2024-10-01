#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // Para função sleep

// Variáveis globais
double saldo_reais = 0, saldo_bitcoin = 0, saldo_ethereum = 0, saldo_ripple = 0;
double BTC = 500, ETH = 200, XRP = 100;
double variacao_bitcoin, variacao_ripple, variacao_ethereum;
char extrato[1000] = "";
char Nome[] = "Luca Juraski";
char login[12], senha[12];

// Funções auxiliares
void clear_screen() { system("clear || cls"); }

void ocultar_senha(char *senha) {
  printf("Senha: ");
  int i = 0;
  char ch;
  while ((ch = getchar()) != '\n' && i < 6) {
    if (ch == 127 || ch == '\b') { // Backspace
      if (i > 0) {
        i--;
        printf("\b \b");
      }
    } else {
      senha[i++] = ch;
      printf("*");
    }
  }
  senha[i] = '\0';
  printf("\n");
}
 
int exibir_menu() {
  int opcao;
  printf("\nBem-Vindo ao projeto!\n\n");
  printf("Escolha uma opção:\n");
  printf("[1] Cadastrar novo usuário\n");
  printf("[2] Fazer Login\n");
  printf("[3] Sair\n");
  printf("Digite sua opção: ");
  scanf("%d", &opcao);
  return opcao;
}

// Função para validar CPF (11 dígitos e apenas números)
int validar_cpf(char *cpf) {
  if (strlen(cpf) != 11) {
    printf("CPF deve ter 11 dígitos. Tente novamente!\n");
    return 0;
  }
  for (int i = 0; i < 11; i++) {
    if (!isdigit(cpf[i])) {
      printf("CPF deve conter apenas números. Tente novamente!\n");
      return 0;
    }
  }
  return 1;
}

void fazer_login(char *login, char *senha) {
  int cpf_valido = 0;

  // Validar CPF
  while (!cpf_valido) {
    printf("CPF: ");
    scanf("%s", login);
    cpf_valido = validar_cpf(login);
  }

  // Limpar o buffer antes de pedir a senha
  while (getchar() != '\n')
    ; // Limpa o buffer do stdin

  // Validar senha
  while (1) {
    int senha_valida = 1;

    printf("Senha: ");
    scanf("%s",
          senha); // Removido ocultar_senha para facilitar a leitura do exemplo

    if (strlen(senha) < 6) {
      printf("Senha deve conter no mínimo 6 dígitos. Tente novamente!\n");
      senha_valida = 0;
    } else {
      // Verificar se todos os caracteres são numéricos
      for (int i = 0; i < strlen(senha); i++) {
        if (!isdigit(senha[i])) {
          senha_valida = 0;
          printf("A senha deve conter apenas caracteres numéricos. Tente "
                 "novamente!\n");
          break;
        }
      }
    }

    if (senha_valida) {
      break;
    }
  }
}





































int main(void) {
  return 0;
}