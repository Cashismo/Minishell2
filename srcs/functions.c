/*
** functions.c for functions in /home/gassem_a/Minishell/Minishell1/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Fri Apr  1 11:58:15 2016 aurelien gassemann
** Last update Fri Apr  1 15:46:28 2016 aurelien gassemann
*/

#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	{
	  my_putchar(str[i]);
	  i += 1;
	}
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i])
    i += 1;
  return (s1[i] - s2[i]);
}

int	my_atoi(char *str)
{
  int	i;
  int	j;
  int	idx;

  i = 0;
  j = 0;
  idx = 0;
  if (str[0] == '-')
    {
      idx = 1;
      i = 1;
    }
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  if (idx == 1)
    j = j - 1;
  return (j);
}
