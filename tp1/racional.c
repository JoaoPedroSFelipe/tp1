/* 
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 16/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
*/

/* coloque aqui seus includes (primeiro os <...>, depois os "...") */
#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*
 * Implemente aqui as funcoes definidas no racionais.h; caso precise,
 * pode definir aqui funcoes auxiliares adicionais, que devem ser usadas
 * somente neste arquivo.
*/


/* Troca os sinais do denominador e numerador de um racional se ambos forem negativos. */
struct racional troca_sinal (struct racional r)
{

  if ((r.num < 0) && (r.den < 0))
    {

      r.num *= -1;
      r.den *= -1;

    }
  
  
  return (r);
}

/* Move o sinal do denominador para o numerador. */
struct racional migra_sinal (struct racional r)
{

  if ((0 < r.num) && (r.den < 0))
    {
      r.num *= -1;
      r.den *= -1;
    }
 
  return (r);
}

/* retorna um número aleatório entre min e max, inclusive. */
long aleat (long min, long max)
{
  
  long x;

  x = rand() % (max + 1);

  min = rand() % 2;

  if (min == 0)
    x = -x;
  
  return (x);
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc (long a, long b)
{
  
  if (a < 0)
    a *= -1; 

  while (a != b)
    {
      if (a > b)
        a -= b;
      else
        b -= a;
    }

  return (b);
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc (long a, long b)
{
  long minimo;

  minimo = (a * b) / mdc (a, b);

  return (minimo);

}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r (struct racional r)
{
  long aux;

  aux = r.num;

  if (valido_r(r) == 1)
    {
   
      r = troca_sinal(r);
      r = migra_sinal(r);
      
      r.num /= mdc(aux, r.den);
      r.den /= mdc(aux, r.den);
  
    }


  return (r);
}


/* Verifica se o racional é valido. */
int valido_r (struct racional r)
{

  if (r.den == 0)
    return (0);
  
  return (1);
}


/* Cria um racional com o numerador e denominador indicados. */
struct racional cria_r (long numerador, long denominador)
{

  struct racional num_racional;

  num_racional.num = numerador;
  num_racional.den = denominador;

  return (num_racional);
}

/* Cria um racional sorteando seu numerador e denominador aleatoriamente. */
struct racional sorteia_r (long min, long max)
{

  struct racional racional_sorteado;

  racional_sorteado.num = aleat (min, max);
  racional_sorteado.den = aleat (min, max);

  return (racional_sorteado);
}

/* Imprime um racional depois de simplificar. */
void imprime_r (struct racional r)
{

  r =  simplifica_r (r);
 
  int i;

  i = 0;

  if (r.den == 0)
    {
      printf("INVALIDO");
      i = 1;
    }

  if (r.num == 0)
    {
      printf("0");
      i = 1;
    }

  if (r.den == 1)
    {
      printf("%ld", r.num);
      i = 1;
    }

  if ((r.num * -1) == r.den)
    {
      printf("-1");
      i = 1;
    }

  if (r.num == r.den)
    {
      printf("1");
      i = 1;
    }

  if (i == 0)
      printf("%ld/%ld", r.num, r.den);

}

/* Retorna a soma de dois racionais. */
struct racional soma_r (struct racional r1, struct racional r2)
{
  struct racional r3;

  r1.num *= mmc(r1.den, r2.den) / r1.den;
  r2.num *= mmc(r1.den, r2.den) / r2.den;

  r3.den = mmc(r1.den, r2.den);
  r3.num = r1.num + r2.num;

  return (r3);  
}

/* Retorna a subtração de dois racionais. */
struct racional subtrai_r (struct racional r1, struct racional r2)
{
  struct racional r3;

  r1.num *= mmc(r1.den, r2.den) / r1.den;
  r2.num *= mmc(r1.den, r2.den) / r2.den;

  r3.den = mmc(r1.den, r2.den);
  r3.num = r1.num - r2.num;

  return (r3);
}

/* Retorna a multiplicação de dois racionais. */
struct racional multiplica_r (struct racional r1, struct racional r2)
{
  struct racional r3;

  r3.num = r1.num * r2.num;
  r3.den = r1.den * r2.den;

  return (r3);
}

/* Retorna a divisão de dois racionais. */
struct racional divide_r (struct racional r1, struct racional r2)
{
  struct racional r3;

  r3.num = r1.num * r2.den;
  r3.den = r1.den * r2.num;

  return (r3);
}
