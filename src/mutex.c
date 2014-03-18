/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Mar 18 18:02:59 2014 Etienne
*/

#include "philo.h"

static int	create_baguette(pthread_mutex_t *baguette)
{
  int		ret;

  if ((ret = pthread_mutex_init(baguette, NULL)))
    {
      errno = ret;
      perror("pthread_mutex_init");
      return (1);
    }
  return (0);
}

int	destroy_baguette(pthread_mutex_t *baguette)
{
  int	ret;

  if ((ret = pthread_mutex_destroy(baguette)))
    {
      errno = ret;
      perror("pthread_mutex_destroy");
      return (1);
    }
  return (0);
}

static int	init_philo(t_philosophe *ph, pthread_mutex_t *right,
		   pthread_mutex_t *left)
{
  int		ret;

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

static int	destroy_philo(t_philosophe *ph)
{
  int		ret;

  if ((ret = pthread_join(ph->thread, NULL)))
    {
      errno = ret;
      perror("pthread_join");
      return (1);
    }
  return (0);
}

int	init_data(t_philosophe *philo, pthread_mutex_t *baguette)
{
  int	i;

  i = 0;
  while (i < PHILOSOPHES)
    {
      if (create_baguette(&(baguette[i])))
        return (1);
      i++;
    }
  i = 0;
  while (i < PHILOSOPHES)
    {
      if (init_philo(&(philo[i]), &(baguette[i]),
                     &(baguette[(i + 1) % PHILOSOPHES]))
	  || (destroy_philo(&(philo[i]))))
        return (1);
      i++;
    }
  return (0);
}
