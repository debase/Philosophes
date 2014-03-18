/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Tue Mar 18 18:02:30 2014 Etienne
*/

#include "philo.h"

int			main()
{
  t_philosophe		philo[PHILOSOPHES];
  pthread_mutex_t	baguette[PHILOSOPHES];
  int			i;

  i = 0;
  if (init_data(philo, baguette))
    return (1);
  while (i < PHILOSOPHES)
    {
      if (destroy_baguette(&(baguette[i])))
        return (1);
      i++;
    }
  return (0);
}
