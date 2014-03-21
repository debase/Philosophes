/*
** sdl_philo.h for sdl_philo in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 21 15:14:45 2014 Etienne
** Last update Fri Mar 21 18:28:05 2014 Etienne
*/

#ifndef SDL_PHILO_H_
# define SDL_PHILO_H_

#include <stdio.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_thread.h"
#include "SDL_timer.h"

# define SLEEP_SPRITE	"./sprite/sleep.png"
# define THINK_SPRITE	"./sprite/think.png"
# define EAT_SPRITE	"./sprite/eat.png"
# define BACKROUND	"./sprite/nain.png"

typedef struct	s_philosophe t_philosophe;

typedef struct	s_st_sprite
{
  SDL_Surface	*sprite;
  int		posx;
  int		posy;
}		t_st_sprite;

typedef struct	s_sdl_philo
{
  SDL_Thread	*thread;
  SDL_Surface   *background;
  SDL_Surface	*ptr_win;
  t_st_sprite	sprite_state[3];
}		t_sdl_philo;

typedef struct	s_arg_thread
{
  t_sdl_philo	*sdl;
  t_philosophe	*philo;
}		t_arg_thread;

int		init_sdl(t_sdl_philo *sdl, t_philosophe *philo);
int		sdl_kill(t_sdl_philo *sdl);

#endif /* !SDL_PHILO_H_ */
