/*
** search.c for search in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Mon Apr 11 18:41:15 2016 Aurélien Gassemann
** Last update Mon Apr 11 18:41:16 2016 Aurélien Gassemann
*/

#include <stdlib.h>

char	*get_value(char *str)
{
  int	i;
  int	j;
  char	*result;

  i = 0;
  j = 0;
  if ((result = malloc(sizeof(char *) * (my_strlen(str)))) == NULL)
    malloc_fail();
  while (str[i - 1] != '=')
    i += 1;
  while (str[i] != 0)
    result[j++] = str[i++];
  return (result);
}

char	*search(char **env, char *str)
{
  int	i;
  int	len;

  i = 0;
  if ((len = my_strlen(str)) == 0)
    return (NULL);
  if (env[0] == NULL)
    return (NULL);
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], str, len) == 0)
	return (get_value(env[i]));
      i += 1;
    }
  return (NULL);
}
