/*
** display_sdl.c for display in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 23 12:31:54 2014 Etienne
** Last update Sun Mar 23 12:53:00 2014 Etienne
*/

#include "sdl_philo.h"

int		update_aff(t_philosophe *philo, t_sdl_philo *sdl)
{
  int		i;
  t_st_sprite	surf;
  int		state;

  i = 0;
  while (i < PHILOSOPHES)
    {
      state = philo[i].state;
      surf = sdl->sprite_state[state];
      surf.pos.y = 50;
      surf.pos.x = 20 + (i * 140);
      if (SDL_BlitSurface(surf.sprite, NULL, sdl->ptr_win, &surf.pos) == -1)
        {
          fprintf(stderr, "Error while displaying sprite : %s\n",
                  Mix_GetError());
          return (EXIT_FAILURE);
        }
      i++;
    }
  return (EXIT_SUCCESS);
}

int		display_background(t_sdl_philo *sdl)
{
  SDL_Rect      pos;

  pos.x = 0;
  pos.y = 200;
  if (SDL_BlitSurface(sdl->background, NULL, sdl->ptr_win, &pos) == -1)
    {
      fprintf(stderr, "Error while displaying menu sprite [%s] : %s\n",
              BACKROUND, SDL_GetError());
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
