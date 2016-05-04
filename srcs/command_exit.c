/*
** command_exit.c for exit in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 13:44:02 2016 Aurélien Gassemann
** Last update Tue Apr 12 13:44:03 2016 Aurélien Gassemann
*/

#include <stdlib.h>

void	my_exit(char *str)
{
  my_putstr_error("exit\n");
  if (str != NULL)
    exit(my_atoi(str));
  else
    exit(0);
}
