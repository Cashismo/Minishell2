/*
** my_setenv.c for setenv in /home/gassem_a/Minishell/PSU_2015_minishell2/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Mon Apr  4 10:46:07 2016 aurelien gassemann
** Last update Mon Apr 11 17:50:45 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

char	**add(char **environment, char **args)
{
  char	**new_env;
  int	i;

  i = 0;
  if ((new_env = malloc(sizeof(char **) * (my_tablen(environment) * 2)))
      == NULL)
    malloc_fail();
  while (environment[i] != 0)
    {
      if ((new_env[i] = malloc(sizeof(char *)
			       * (my_strlen(environment[i]) * 2)))
	  == NULL)
	malloc_fail();
      new_env[i] = environment[i];
      i += 1;
    }
  new_env[i] = get_file(args[1], "=");
  if (args[2] != NULL)
    new_env[i] = get_file(new_env[i], args[2]);
  return (new_env);
}

char	**edit(char **environment, char **args, int i)
{
  t_var	var;

  var.j = 0;
  var.k = 0;
  var.str = environment[i];
  var.len = my_strlen(var.str);
  if ((environment[i] = malloc(sizeof(char *) * (var.len + my_strlen(args[1]))
			       * 2)) == NULL)
    malloc_fail();
  while (var.str[var.j - 1] != '=')
    {
      environment[i][var.j] = var.str[var.j];
      var.j += 1;
    }
  while (args[2][var.k] != 0)
    {
      environment[i][var.j] = args[2][var.k++];
      var.j += 1;
    }
  return (environment);
}

char	**my_setenv(char **environment, char **args)
{
  int	i;

  i = 0;
  if (args[1] == 0)
    {
      my_putstr_error("error: too few arguments\n");
      return (environment);
    }
  if (args[1][0] <= 'A' || (args[1][0] >= 91 && args[1][0] <= 96)
      || args[1][0] >= 123)
    {
      my_putstr_error("setenv: Variable name must begin with a letter.\n");
      return (environment);
    }
  while (environment[i] != 0)
    {
      if (my_strncmp(environment[i++], args[1], my_strlen(args[1])) == 0)
	return (edit(environment, args, i - 1));
    }
  return (add(environment, args));
}
