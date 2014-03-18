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

int	create_baguette(pthread_mutex_t *baguette)
{
  int	ret;

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
