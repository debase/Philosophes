/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Thu Mar 20 22:11:23 2014 Etienne
*/

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

void			philo_sleep(t_philosophe *ph)
{
  ph->state = REST;
  ph->energy = ((ph->energy + 5) > 100 ? 100 : ph->energy + 5);
  printf("%sphilo #%d is sleeping : energy = %d%s\n",
	 ph->color, ph->id, ph->energy, RESET_COLOR);
  usleep(rand() % MAX_TIME + 1);
}

void			philo_eat(t_philosophe *ph)
{
  ph->state = EAT;
  printf("%sphilo #%d is eating : energy = %d%s\n",
	 ph->color, ph->id, ph->energy, RESET_COLOR);
  usleep(rand() % MAX_TIME + 1);
  pthread_mutex_unlock(&ph->baguette);
  pthread_mutex_unlock(&ph->next->baguette);
  philo_sleep(ph);
}

void			philo_think(t_philosophe *ph, int left)
{
  ph->state = THINK;
  ph->energy = ((ph->energy - 20) < 0 ? 0 : ph->energy - 20);
  printf("%sphilo #%d is thinking : energy = %d%s\n",
	 ph->color, ph->id, ph->energy, RESET_COLOR);
  /* if (ph->energy == 0) */
  /*   { */
  /*     if (!left) */
  /* 	pthread_mutex_unlock(&ph->baguette); */
  /*     else */
  /* 	pthread_mutex_unlock(&ph->next->baguette); */
  /*     return ; */
  /*   } */
  usleep(rand() % MAX_TIME + 1);
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
  philo_sleep(ph);
  while (ph->energy > 0)
    {
      left = pthread_mutex_trylock(&ph->baguette);
      right = pthread_mutex_trylock(&ph->next->baguette);
      if (!left && !right && (ph->state != EAT))
	philo_eat(ph);
      else if ((!left || !right) && (ph->state != THINK))
	philo_think(ph, left);
      else if (ph->state != REST)
	philo_sleep(ph);
      else
	{
	  /* printf ("usllep de le fuck\n"); */
	  usleep(500);
	}
      printf ("ph #%d : energy = %d\n", ph->id, ph->energy);
    }
  pthread_mutex_unlock(&ph->baguette);
  pthread_mutex_unlock(&ph->next->baguette);
  printf("Philosopher #%d doesn't have any ressources left !\n", ph->id);
  return (NULL);
}
