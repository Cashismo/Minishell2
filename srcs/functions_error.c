/*
** error.c for errors in /home/gassem_a/Minishell/Minishell1/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Fri Apr  1 11:57:55 2016 aurelien gassemann
** Last update Tue Apr 12 15:39:38 2016 Aurélien Gassemann
*/

#include <stdlib.h>

void	malloc_fail()
{
  my_putstr_error("Malloc failed\n");
  exit(-1);
}

void	fork_fail()
{
  my_putstr_error("Fork failed\n");
  exit(-1);
}

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

int	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	{
	  my_putchar_error(str[i]);
	  i = i + 1;
	}
    }
}
