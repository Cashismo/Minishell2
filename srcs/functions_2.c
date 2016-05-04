/*
** functions_2.c for functions in /home/gassem_a/PSU/PSU_2015_minishell2/srcs
**
** Made by Aurélien Gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Tue Apr 12 13:48:42 2016 Aurélien Gassemann
** Last update Tue Apr 12 13:48:43 2016 Aurélien Gassemann
*/

int	my_put_nbr(int nb)
{
  {
    if (nb < 0)
      {
	my_putchar('-');
	nb = nb * (-1);
      }
    if (nb >= 10)
      {
	my_put_nbr(nb / 10);
	my_put_nbr(nb % 10);
      }
    else
      my_putchar(48 + nb);
  }
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && (s1[i] != 0 || s2[i] != 0))
    {
      if (s1[i] != s2[i])
	return (1);
      i += 1;
    }
  if (i == n)
    return (0);
  return (1);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i = i + 1;
  return (i);
}
