/*
** minishell.h for minishell in /home/gassem_a/Minishell/Minishell1/include
**
** Made by aurelien gassemann
** Login   <gassem_a@epitech.net>
**
** Started on  Thu Mar 31 15:26:41 2016 aurelien gassemann
** Last update Tue Apr 12 19:44:50 2016 Aurélien Gassemann
*/

#ifndef		MINISHELL_H_
# define	MINISHELL_H_

/*
** Includes
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/*
** Defines
*/
#define		PATH_DEFAUT	"PATH="

/*
** Structures
*/
typedef struct	s_var
{
  char		**tab;
  char		**args2;
  char		**path_tab;
  char		**new_env;
  char		*args1;
  char		*path;
  char		*prompt;
  char		*buf;
  char		*home;
  char		*name;
  char		*value;
  char		*str;
  int		i;
  int		j;
  int		k;
  int		idx;
  int		len;
  int		overwrite;
  char		**origin;
  char		*dest;
  pid_t		pid;
  char		**ftab;
  char		**args42;
}		t_var;

/*
** Prototypes
*/

/* Function(s) in file builtins.c */
char	**builtins(char **environment, t_var var);
int	detect_builtins(t_var var);

/* Function(s) in file command_cd.c */
int	my_cd(t_var var, char **env);

/* Function(s) in file command_env.c */
int	display_environment(char **env);

/* Function(s) in file command_exit.c */
void	my_exit(char *str);

/* Function(s) in file command_setenv.c */
char	**add(char **environment, char **args);
char	**edit(char **environment, char **args, int i);
char	**my_setenv(char **environment, char **args);

/* Function(s) in file command_setenv.c */
char	**delete(char **environment, char *name, int i);
char	**my_unsetenv(char **environment, char *name);

/* Function(s) in file functions_2.c */
int	my_put_nbr(int nb);
int	my_strncmp(char *s1, char *s2, int n);
int	my_tablen(char **tab);

/* Function(s) in file functions.c */
void	my_putchar(char c);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_atoi(char *str);

/* Function(s) in file functions_error.c */
void	malloc_fail();
void	fork_fail();
void	my_putchar_error(char c);
int	my_putstr_error(char *str);

/* Function(s) in file main.c */
void	detect_the_signal(int signal);
int	detect_signal_child(pid_t pid);
int	main(int ac, char **av, char **env);

/* Function(s) in file minishell */
char	*get_path(char **environment, t_var var);
char	*get_file(char *path, char *args);

/* Function(s) in file my_exec.c */
int	command_not_found(char *str);
int	exec(t_var var, char **env);

/* Function(s) in file my_str_to_wordtab.c */
t_var	init();
char	**str_to_word_tab(char *str, char c);

/* Function(s) in file redirection.c */
//char	**first_pars(char *buffer);
int	redirection_fonc(t_var var, char **env);
int	check_redirection(t_var var, char **env);

/* Function(s) in file search.c */
char	*get_value(char *str);
char	*search(char **env, char *str);

/* Function(s) in file semicolons.c */
t_var	init2();
char	**str_for_semicolons(char *str, char c);
int	exec_semicolons(t_var var, char **env);

#endif /* !MINISHELL_H_ */
