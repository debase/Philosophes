/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Mar 20 21:49:35 2014 Etienne
*/

#ifndef PHILO_H_INCLUDED
# define PHILO_H_INCLUDED

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>

# define PHILOSOPHES	7
# define RESET_COLOR	"\x1b[0m"
# define MAX_TIME	500

typedef enum
{
  REST,
  EAT,
  THINK
}	e_pstate;

typedef struct				s_philosophe
{
  pthread_t				thread;
  pthread_mutex_t			baguette;
  struct s_philosophe			*next;
  struct s_philosophe			*previous;
  int					id;
  e_pstate				state;
  char					color[20];
  int					energy;
}					t_philosophe;

int	create_baguette(pthread_mutex_t *baguette);
int	init_philo(t_philosophe *ph, t_philosophe *previous,
		   t_philosophe *next, int id);
void	*philosophe(void *arg);
int	destroy_baguette(pthread_mutex_t *baguette);
int	destroy_philo(t_philosophe *ph);

#endif // PHILO_H_INCLUDED
