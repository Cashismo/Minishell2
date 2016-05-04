/*
** builtins.c for builtins in /home/gassem_a/Minishell/Minishell1
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Thu Mar 31 15:22:09 2016 aurelien gassemann
** Last update Tue Apr 12 17:11:47 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

char	**builtins(char **environment, t_var var)
{
  char	*str;
  char	**env;

  if (my_strcmp(var.args2[0], "cd") == 0)
    my_cd(var, environment);
  else if (my_strcmp(var.args2[0], "exit") == 0)
    my_exit(var.args2[1]);
  else if (my_strcmp(var.args2[0], "unsetenv") == 0)
    return (my_unsetenv(environment, var.args2[1]));
  else if (my_strcmp(var.args2[0], "setenv") == 0)
    return (my_setenv(environment, var.args2));
  else if (my_strcmp(var.args2[0], "env") == 0)
    display_environment(environment);
  return (environment);
}

int	detect_builtins(t_var var)
{
  if (my_strcmp(var.args2[0], "cd") == 0 ||
      my_strcmp(var.args2[0], "exit") == 0 ||
      my_strcmp(var.args2[0], "unsetenv") == 0 ||
      my_strcmp(var.args2[0], "setenv") == 0 ||
      my_strcmp(var.args2[0], "env") == 0)
    return (1);
  return (0);
}
