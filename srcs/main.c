/*
** main.c for main in /home/gassem_a/Minishell/PSU_2015_minishell2/srcs
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sat Apr  2 20:18:35 2016 aurelien gassemann
** Last update Tue Apr 12 20:51:13 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"
#include "../includes/get_next_line.h"

void	detect_the_signal(int signal)
{
  t_var	var;

  if (signal == SIGINT)
    {
      my_putchar('\n');
      my_putstr("$> ");
    }
}

int	signals()
{
  signal(SIGINT, detect_the_signal);
  signal(SIGQUIT, detect_the_signal);
  signal(SIGTSTP, detect_the_signal);
}

int	detect_signal_child(pid_t pid)
{
  if (WIFSIGNALED(pid))
    {
      if (WTERMSIG(pid) == SIGSEGV)
	my_putstr_error("Segmentation fault\n");
      return (1);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_var	var;

  if (env[0] == NULL && (env = malloc(sizeof(char **) * (1000))) == NULL)
    malloc_fail();
  signals();
  while (7)
    {
      my_putstr("$> ");
      var.i = -1;
      if ((var.args2 = str_to_word_tab(var.str = get_next_line(0), ' '))
	  == NULL)
	exit(write(2, "exit\n", 5));
      var.args42 = str_for_semicolons(var.str, ';');
      while (var.args42[++var.i] != NULL)
	{
	  var.args2 = str_to_word_tab(var.args42[var.i], ' ');
	  if (var.args2[0] == 0);
	  else if (detect_builtins(var) == 1)
	    env = builtins(env, var);
	  else
	    var.pid = check_redirection(var, env);
	  wait(&var.pid);
	  detect_signal_child(var.pid);
	}
    }
}
