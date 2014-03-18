/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Mar 18 18:00:42 2014 Etienne
*/

#ifndef PHILO_H_INCLUDED
# define PHILO_H_INCLUDED

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>

# define PHILOSOPHES 7

typedef enum
{
  REST,
  EAT,
  THINK
}	e_pstate;

typedef struct		s_philosophe
{
  pthread_t		thread;
  pthread_mutex_t	*right_baguette;
  pthread_mutex_t	*left_baguette;
  e_pstate		state;
}			t_philosophe;

int	init_data(t_philosophe *philo, pthread_mutex_t *baguette);
void	*philosophe(void *arg);
int	destroy_baguette(pthread_mutex_t *baguette);

#endif // PHILO_H_INCLUDED
