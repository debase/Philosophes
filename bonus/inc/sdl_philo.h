/*
** sdl_philo.h for sdl_philo in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 21 15:14:45 2014 Etienne
** Last update Fri Mar 21 15:21:01 2014 Etienne
*/

#ifndef SDL_PHILO_H_
# define SDL_PHILO_H_

#include "SDL.h"
#include "SDL_thread.h"
#include "SDL_timer.h"

typedef struct	s_philosophe t_philosophe;

typedef struct	s_sdl_philo
{

}		t_sdl_philo;

int		init_sdl(t_sdl_philo *sdl, t_philosophe *philo);

#endif /* !SDL_PHILO_H_ */
