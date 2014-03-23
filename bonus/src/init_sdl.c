/*
** init_sdl.c for init in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Sun Mar 23 12:24:16 2014 Etienne
** Last update Sun Mar 23 13:01:04 2014 Etienne
*/

#include "sdl_philo.h"

int		init_sdl(t_arg_thread *sdl)
{
  if (load_texture(sdl->sdl) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Error init SDL : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  if ((sdl->sdl->ptr_win = SDL_SetVideoMode(sdl->sdl->background->w,
                           sdl->sdl->background->h + 200,
                           32, SDL_HWSURFACE)) == NULL)
    {
      fprintf(stderr, "Error creation SDL window : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  SDL_WM_SetCaption("Le diner des philosophes", NULL);
  init_music(sdl->sdl);
  pthread_create(&(sdl->sdl->thread), NULL, &thread_sdl, sdl);
  return (EXIT_SUCCESS);
}

int		sdl_kill(t_sdl_philo *sdl)
{
  int		i;

  i = 0;
  SDL_FreeSurface(sdl->background);
  while (i < 3)
    {
      SDL_FreeSurface(sdl->sprite_state[i].sprite);
      i++;
    }
  return (0);
}
