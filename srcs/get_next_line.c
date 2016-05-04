/*
** final.c for get_next_line in /home/gassem_a/CPE_2015_getnextline
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Sat Jan 16 18:12:27 2016 aurelien gassemann
** Last update Mon Apr  4 13:40:20 2016 aurelien gassemann
*/

#include <stdlib.h>
#include "../includes/get_next_line.h"

int	fill_buff_with_lines(char *string, char *buff)
{
  t_vars	vars;

  vars.i = my_strlen(string);
  vars.j = 0;
  while (buff[vars.j] != '\0')
    {
      string[vars.i] = 0;
      if (buff[vars.j] == '\n')
	{
	  vars.j = vars.j + 1;
	  return (1);
	}
      string[vars.i] = buff[vars.j];
      vars.i = vars.i + 1;
      vars.j = vars.j + 1;
    }
  string[vars.i] = 0;
  return (0);
}

char		*get_next_line(const int fd)
{
  t_vars	vars;
  char		*buff;
  char		*string;

  if ((string = malloc(sizeof(char) * SIZE_OF_LINE)) == NULL)
    return (NULL);
  if ((buff = malloc(sizeof(char *) * SIZE_OF_LINE)) == NULL)
    return (NULL);
  string[0] = 0;
  while ((vars.length = read(fd, buff, READ_SIZE)) && vars.length > 0)
    {
      if (fill_buff_with_lines(string, buff) == 1)
	return (string);
    }
  if (read(fd, buff, READ_SIZE) == -1)
    return (NULL);
  free (string);
  free (buff);
  return (0);
}
