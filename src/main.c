/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#include "philo.h"

int	init_philo(t_philosophe *ph, pthread_mutex_t *right,
               pthread_mutex_t *left)
{
  int	ret;

  if ((ret = pthread_create(&(ph->thread), NULL, &philosophe, ph)))
    {
      errno = ret;
      perror("pthread_create");
      return (1);
    }
  ph->right_baguette = right;
  ph->left_baguette = left;
  ph->state = REST;
  return (0);
}

int	destroy_philo(t_philosophe *ph)
{
  int	ret;

  if ((ret = pthread_join(ph->thread, NULL)))
    {
      errno = ret;
      perror("pthread_join");
      return (1);
    }
  return (0);
}

int			main()
{
  t_philosophe		philo[PHILOSOPHES];
  pthread_mutex_t	baguette[PHILOSOPHES];
  int		i;

  i = 0;
  while (i < PHILOSOPHES)
    {
      if (create_baguette(&(baguette[i])))
        return (3);
      i++;
    }
  i = 0;
  while (i < PHILOSOPHES)
    {
      if (init_philo(&(philo[i]), &(baguette[i]),
                     &(baguette[(i + 1) % PHILOSOPHES])))
        return (1);
      i++;
    }
  i = 0;
  while (i < PHILOSOPHES)
    {
      if (destroy_philo(&(philo[i])))
        return (2);
      i++;
    }
  i = 0;
  while (i < PHILOSOPHES)
    {
      if (destroy_baguette(&(baguette[i])))
        return (3);
      i++;
    }
  return (0);
}

