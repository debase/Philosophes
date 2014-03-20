/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Mar 20 19:17:45 2014 Etienne
*/

#include "philo.h"
#include <unistd.h>

void			philo_sleep(t_philosophe *ph)
{
  printf("philo #%d is sleeping.\n", ph->id);
  sleep(2);
}

void			philo_eat(t_philosophe *ph)
{
  printf("philo #%d is eating.\n", ph->id);
  sleep(2);
  pthread_mutex_unlock(&ph->baguette);
  pthread_mutex_unlock(&ph->next->baguette);
  philo_sleep(ph);
}

void			philo_think(t_philosophe *ph, int left)
{
  printf("philo #%d is thinking.\n", ph->id);
  sleep(2);
  if (!left)
    pthread_mutex_lock(&ph->next->baguette);
  else
    pthread_mutex_lock(&ph->baguette);
  philo_eat(ph);
}

void			*philosophe(void *arg)
{
  t_philosophe		*ph;
  int			left;
  int			right;

  ph = arg;
  while (1)
    {
      left = pthread_mutex_trylock(&ph->baguette);
      right = pthread_mutex_trylock(&ph->next->baguette);
      if (!left && !right)
	philo_eat(ph);
      else if (!left || !right)
	philo_think(ph, left);
      else
	philo_sleep(ph);
    }
  return (NULL);
}
