/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Fri Mar 21 23:54:42 2014 Etienne
*/

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

void			philo_sleep(t_philosophe *ph)
{
  if (ph->state == REST)
    return ;
  ph->state = REST;
  printf("%sphilo #%d is sleeping%s\n",
	 ph->color, ph->id, RESET_COLOR);
  usleep(rand() % MAX_TIME + 1);
}

void			philo_eat(t_philosophe *ph)
{
  ph->state = EAT;
  ph->food--;
  printf("%sphilo #%d is eating%s\n",
	 ph->color, ph->id, RESET_COLOR);
  usleep(rand() % MAX_TIME + 1);
  pthread_mutex_unlock(&ph->baguette);
  pthread_mutex_unlock(&ph->next->baguette);
  philo_sleep(ph);
}

void			philo_think(t_philosophe *ph, int left)
{
  int			ret;

  ph->state = THINK;
  printf("%sphilo #%d is thinking%s\n",
	 ph->color, ph->id, RESET_COLOR);
  usleep(rand() % MAX_TIME + 1);
  while (ph->state == THINK)
    {
      ret = (!left ? (pthread_mutex_lock(&ph->next->baguette)) :
	     pthread_mutex_lock(&ph->baguette));
      if (!ret)
	philo_eat(ph);
      else
	(!left ? (pthread_mutex_unlock(&ph->next->baguette)) :
	 pthread_mutex_unlock(&ph->baguette));
    }
}

void			*philosophe(void *arg)
{
  t_philosophe		*ph;
  int			left;
  int			right;

  ph = arg;
  while (ph->food > 0)
    {
      left = pthread_mutex_trylock(&ph->baguette);
      right = pthread_mutex_trylock(&ph->next->baguette);
      if (!left && !right && (ph->state != EAT))
  	philo_eat(ph);
      else if ((!left || !right) && (ph->state != THINK))
  	philo_think(ph, left);
      else
  	philo_sleep(ph);
    }
  return (NULL);
}
