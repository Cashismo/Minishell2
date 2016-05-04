/*
** my_exec.c for my_exec in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 12:56:03 2016 Aurélien Gassemann
** Last update Tue Apr 12 15:31:10 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

int	command_not_found(char *str)
{
  my_putstr_error(str);
  my_putstr_error(" : command not found\n");
  return (1);
}

int	exec(t_var var, char **env)
{
  var.i = 0;
  var.k = 0;
  var.path_tab = str_to_word_tab(get_path(env, var), ' ');
  if (var.path_tab == NULL)
    return (command_not_found(var.args2[0]));
  if ((var.pid = fork()) == -1)
    fork_fail();
  while (var.path_tab[var.i] != 0)
    {
      if (var.pid == 0 && my_strncmp(var.args2[0], "./", 2) == 0)
	execve(var.args2[0], var.args2, env);
      else if  (var.pid == 0 && my_strncmp(var.args2[0], "/", 1) != 0)
	{
	  var.path = get_file(var.path_tab[var.i], var.args2[0]);
	  execve(var.path, var.args2, env);
	}
      else if (var.pid == 0)
	execve(var.args2[0], var.args2, env);
      else
	return (1);
      var.i += 1;
    }
  my_putstr_error(var.args2[0]);
  my_putstr_error(" : command not found\n");
  exit(0);
}
