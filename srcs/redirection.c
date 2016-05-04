/*
** redirection.c for redirection in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 14:00:19 2016 Aurélien Gassemann
** Last update Tue Apr 12 19:51:18 2016 Aurélien Gassemann
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../includes/minishell.h"

int	redirection_fonc(t_var var, char **env)
{
  int	tmp;
  int	fd;
  char	**myarg;

  if ((tmp = open(var.args2[2], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR
		  | S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
    {
      my_putstr("Error open\n");
      exit(1);
    }
  dup2(tmp, 1);
  var.args2[1] = var.args2[2];
  var.args2[1] = NULL;
  exec(var, env);
  close(tmp);
  dup2(0, 1);
}

int	check_redirection(t_var var, char **env)
{
  int	i;
  char	**arg;

  i = 0;
  while (var.str[i])
    {
      if (var.str[i] == '>' && var.str[i + 1] != '>')
	{
	  var.args2 = str_to_word_tab(var.str, ' ');
	  return (redirection_fonc(var, env));
	}
      i++;
    }
  exec(var, env);
  return (1);
}
