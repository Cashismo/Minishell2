/*
** my_str_to_wordtab.c for str_to_wordtab in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 12:52:38 2016 Aurélien Gassemann
** Last update Tue Apr 12 14:23:31 2016 Aurélien Gassemann
*/

#include "../includes/minishell.h"

t_var	init()
{
  t_var	var;

  var.i = 0;
  var.j = 0;
  return (var);
}

char	**str_to_word_tab(char *str, char c)
{
  t_var	var;

  if (str == NULL)
    return (NULL);
  var = init();
  if ((var.tab = malloc(sizeof(char **) * my_strlen(str) * 2)) == NULL)
    malloc_fail();
  while (var.i != my_strlen(str))
    if ((var.tab[var.i++] = malloc(sizeof(char *) * my_strlen(str) * 2))
	== NULL)
      malloc_fail();
  var.i = 0;
  while (str[var.i] != 0)
    {
      var.k = 0;
      while ((str[var.i] == '	' || str[var.i] == ' ') && str[var.i] != 0)
	var.i += 1;
      while (str[var.i] != '	' && str[var.i] != ' ' && str[var.i] != 0)
	var.tab[var.j][var.k++] = str[var.i++];
      while ((str[var.i] == '	' || str[var.i] == ' ') && str[var.i] != 0)
	var.i += 1;
      var.j += 1;
    }
  var.tab[var.j] = 0;
  return (var.tab);
}
