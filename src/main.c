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

int	init_philo(t_philosophe *ph)
{
  int	ret;

  if ((ret = pthread_mutex_init(&(ph->right_baguette), NULL)))
    {
      errno = ret;
      perror("pthread_mutex_init");
      return (1);
    }
  if ((ret = pthread_mutex_init(&(ph->left_baguette), NULL)))
    {
      errno = ret;
      perror("pthread_mutex_init");
      return (1);
    }
  if ((ret = pthread_create(&(ph->thread), NULL, &philosophe, ph)))
    {
      errno = ret;
      perror("pthread_create");
      return (1);
    }
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
  if ((ret = pthread_mutex_destroy(&(ph->right_baguette))))
    {
      errno = ret;
      perror("pthread_mutex_destroy");
      return (1);
    }
  if ((ret = pthread_mutex_destroy(&(ph->left_baguette))))
    {
      errno = ret;
      perror("pthread_mutex_destroy");
      return (1);
    }
  return (0);
}

int		main()
{
  t_philosophe	philo[PHILOSOPHES];
  int		i;

  i = 0;
  while (i < PHILOSOPHES)
    {
      if (init_philo(&(philo[i])))
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
  return (0);
}

