/*
** my_cd.c for cd in /home/gassem_a/Minishell/PSU_2015_minishell2/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sat Apr  2 20:25:43 2016 aurelien gassemann
** Last update Wed Apr 13 11:18:39 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

int		my_cd(t_var var, char **env)
{
  char		*destination;
  char		**origin;

  if ((origin = malloc(3)) == NULL || (origin[2] = malloc(1000)) == NULL)
    malloc_fail();
  origin[0] = "setenv";
  origin[1] = "OLDPWD";
  origin[2] = getcwd(origin[2], 1000);
  if (var.args2[1] == 0 || var.args2[1] == NULL
      || my_strcmp(var.args2[1], "~") == 0)
    destination = search(env, "HOME=");
  else if (my_strcmp(var.args2[1], "-") == 0)
    destination = search(env, "OLDPWD=");
  else
    destination = var.args2[1];
  if (chdir(destination) != -1)
    my_setenv(env, origin);
  else if (access(destination, F_OK) == -1)
    {
      my_putstr_error(var.args2[1]);
      my_putstr_error(": No such file or directory.\n");
    }
  else if (access(destination, X_OK) == -1)
    my_putstr_error("Check the rights in the folder\n");
  return (0);
}
