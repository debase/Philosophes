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

int	init_philo(t_philosophe *ph, t_philosophe *previous,
               t_philosophe *next)
{
  if (create_baguette(&(ph->baguette)))
    return (1);
  ph->state = REST;
  ph->next = next;
  ph->previous = previous;
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

int	start_philo(t_philosophe philo[PHILOSOPHES])
{
  int	i;
  int	ret;

  i = -1;
  while (++i < PHILOSOPHES)
    if (init_philo(&(philo[i]), &(philo[(i - 1 + PHILOSOPHES) % PHILOSOPHES]),
                   &(philo[(i + 1) % PHILOSOPHES])))
      return (1);
  i = -1;
  while (++i < PHILOSOPHES)
    if ((ret = pthread_create(&(philo[i].thread), NULL,
                              &philosophe, &(philo[i]))))
      {
        errno = ret;
        perror("pthread_create");
        return (1);
      }
  return (0);
}

int	end_philo(t_philosophe philo[PHILOSOPHES])
{
  int	i;

  i = -1;
  while (++i < PHILOSOPHES)
    if (destroy_philo(&(philo[i])))
      return (2);
  i = -1;
  while (++i < PHILOSOPHES)
    if (destroy_baguette(&(philo[i].baguette)))
      return (3);
  return (0);
}

int			main()
{
  t_philosophe		philo[PHILOSOPHES];

  if (start_philo(philo))
    return (1);
  if (end_philo(philo))
    return (1);
  return (0);
}
