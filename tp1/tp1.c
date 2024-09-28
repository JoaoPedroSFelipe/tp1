/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo do programa principal, que usa o TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"


/* programa principal */
int main ()
{
  srand (0); /* use assim, com zero */

  long n, max, i;
  
  struct racional r1, r2, soma, subt, mult, divs;

  scanf("%ld%ld", &n, &max);

  for (i = 1; i <= n; i++)
    {
      printf("%ld: ", i);

      r1 = sorteia_r(max, max);
      r2 = sorteia_r(max, max);

      imprime_r(r1);
      printf(" ");
      imprime_r(r2);
      printf(" ");

      if ((valido_r(r1) == 0) || (valido_r(r2) == 0))
        {
          printf("NUMERO INVALIDO\n");
	  
	  return (1);
	}

      soma = soma_r(r1, r2);
      subt = subtrai_r(r1, r2);
      mult = multiplica_r(r1, r2);
      divs = divide_r(r1, r2);

      if (valido_r(divs) == 0)
        {
          printf("DIVISAO INVALIDA\n");

	  return(1);
	}

      imprime_r(soma);
      printf(" ");

      imprime_r(subt);
      printf(" ");
      
      imprime_r(mult);
      printf(" ");

      imprime_r(divs);
      printf("\n");
    
    }

  return (0) ;
}
