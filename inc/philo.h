/*
** FILE for FILE in /home/moriss_h/projet
**
** Made by hugues morisset
** Login   <moriss_h@epitech.net>
**
** Started on  Mon Oct  8 09:34:29 2012 hugues morisset
** Last update Mon Oct  8 16:20:21 2012 hugues morisset
*/

#ifndef PHILO_H_INCLUDED
# define PHILO_H_INCLUDED

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <pthread.h>

# define PHILOSOPHES 7

void	*philosophe(void *arg);

#endif // PHILO_H_INCLUDED
