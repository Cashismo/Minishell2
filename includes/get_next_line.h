/*
** get_next_line.h for get_next_line.h in /home/gassem_a/CPE_2015_getnextline
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Jan 12 10:36:17 2016 aurelien gassemann
** Last update Mon Apr  4 11:42:57 2016 aurelien gassemann
*/

#ifndef READ_SIZE
# define READ_SIZE (1)
#endif /* !READ_SIZE */

#ifndef MY_GNL_H
# define MY_GNL_H_

# define	SIZE_OF_LINE 4095

typedef struct	s_vars
{
  int		i;
  int		j;
  int		length;
}		t_vars;

int	my_strlen(char *str);
int	fill_buff_with_lines(char *string, char *buff);
char	*get_next_line(const int fd);

#endif /* !MY_GNL_H_ */
