/*
** command_unsetenv.c for unsetenv in /home/gassem_a/PSU/PSU_2015_minishell2
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 21:31:31 2016 Aurélien Gassemann
** Last update Tue Apr 12 21:31:32 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

char	**delete(char **environment, char *name, int i)
{
  if (environment[i + 1] == 0)
    {
      environment[i] = 0;
      return (environment);
    }
  while (environment[i + 1] != 0)
    {
      environment[i] = environment[i + 1];
      i += 1;
    }
  environment[i] = 0;
  return (environment);
}

char	**my_unsetenv(char **environment, char *name)
{
  int	i;

  i = 0;
  if (name == 0)
    {
      my_putstr_error("unsetenv: Too few arguments.");
      my_putchar('\n');
      return (environment);
    }
  while (environment[i] != 0)
    {
      if (my_strncmp(environment[i], name, my_strlen(name)) == 0)
	return (delete(environment, name, i));
      i += 1;
    }
  return (environment);
}
