/*
** disp_env.c for env in /home/gassem_a/Minishell/Minishell1/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Fri Apr  1 11:57:33 2016 aurelien gassemann
** Last update Mon Apr 11 17:52:41 2016 Aurélien Gassemann
*/

#include <stdlib.h>
#include "../includes/minishell.h"

int	display_environment(char **env)
{
  int	i;

  i = 0;
  if (env == NULL)
    {
      my_putstr_error("The environnement is empty\n");
      return (0);
    }
  while (env[i] != 0)
    {
      my_putstr(env[i++]);
      my_putchar('\n');
    }
}
