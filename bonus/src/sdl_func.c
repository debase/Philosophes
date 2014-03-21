/*
** sdl_func.c for sdl_funct in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 21 15:00:35 2014 Etienne
** Last update Fri Mar 21 15:22:59 2014 Etienne
*/

#include "sdl_philo.h"

int		thread_sdl(void *data)
{
  while (1)
    {
      printf("SDL !\n");
      SDL_Delay(500);
    }
}

int		init_sdl(t_sdl_philo *sdl, t_philosophe *philo)
{
  SDL_Thread	*thread;

  thread = SDL_CreateThread(thread_sdl, philo);
  return (0);
}
