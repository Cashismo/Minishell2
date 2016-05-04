/*
** minishell.c for minishell in /home/gassem_a/Minishell/Minishell1/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Fri Apr  1 15:12:38 2016 aurelien gassemann
** Last update Tue Apr 12 16:02:38 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

char	*get_path(char **env, t_var var)
{
  while (env[var.i] != 0)
    {
      if (my_strncmp(env[var.i], "PATH=", 5) == 0)
	{
	  var.j = 5;
	  if ((var.path = malloc(sizeof(char *) * (my_strlen(env[var.i]) * 2)))
	      == NULL)
	    malloc_fail();
	  while (env[var.i][var.j] != 0)
	    {
	      var.path[var.k] = env[var.i][var.j++];
	      if (var.path[var.k]  == ':')
		{
		  var.path[var.k++] = '/';
		  var.path[var.k] = ' ';
		}
	      var.k = var.k + 1;
	    }
	  var.path[var.k++] = '/';
	  var.path[var.k] = 0;
	  return (var.path);
	}
      var.i = var.i + 1;
    }
  return (NULL);
}

char	*get_file(char *path, char *args)
{
  t_var	var;

  var.i = 0;
  var.j = 0;
  while (path[var.i] != 0)
    var.i = var.i + 1;
  while (args[var.j] != 0)
    {
      path[var.i] = args[var.j];
      var.i = var.i + 1;
      var.j = var.j + 1;
    }
  path[var.i] = 0;
  return (path);
}
