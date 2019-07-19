#include <stdio.h>

int mdc(int n1, int n2) {
  FILE *nc = fopen("mdc.txt", "ab+");
  fprintf(nc, "\n");
  int div = 0, real = 0;
  for (div = 1; (div <= n1) && (div <= n2); div++) {
    if ((n1 % div == 0) && (n2 % div == 0)) {
      real = div;
      fprintf(nc, "%d\n", real);
    }
  }
  return real;
}

int main() {
  FILE *nc = fopen("mdc.txt", "ab+");
  if (nc == NULL) {
    nc = fopen("mdc.txt", "wb+");
  } else {
    int n = 0, valor = 0, cont = 0, num = 0;
    fprintf(nc, "\n------------------------TURMA UNIDA "
                "CORP.------------------------\n");

    printf("Quantos numeros deseja digitar? ");
    scanf("%d", &n);

    printf("1o. numero da sequencia: ");
    scanf("%d", &valor);
    fprintf(nc, "%d ", valor);
    getchar();
    for (cont = 1; cont < n; cont++) {
      printf("%do. numero da sequencia: ", cont + 1);
      scanf("%d", &num);
      fprintf(nc, "%d ", num);
      getchar();

      valor = mdc(valor, num);
    }
    printf("VALOR FINAL DO MDC %d \n", valor);
    fprintf(nc, "\nVALOR FINAL DO MDC %d \n", valor);
    fclose(nc);
    return 0;
  }
  return 0;
}
