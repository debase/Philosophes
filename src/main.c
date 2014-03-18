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

int		main()
{
  pthread_t	thread[PHILOSOPHES];
  int		i;

  i = 0;
  while (i < PHILOSOPHES)
    {
      if (!pthread_create(&(thread[i]), NULL, &philosophe, NULL))
        {
          perror("pthread_create");
          return (1);
        }
      i++;
    }
  i = 0;
  while (i < PHILOSOPHES)
    {
      if (!pthread_join(thread[i], NULL))
        {
          perror("pthread_join");
          return (2);
        }
      i++;
    }
  return (0);
}
