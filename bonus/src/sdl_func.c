/*
** sdl_func.c for sdl_funct in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 21 15:00:35 2014 Etienne
** Last update Fri Mar 21 19:56:44 2014 Etienne
*/

#include "sdl_philo.h"

int		update_aff(t_philosophe *philo, t_sdl_philo *sdl)
{
  int		i;
  t_st_sprite	surf;

  i = 0;
  while (i < 7)
    {
      surf = sdl->sprite_state[philo[i].state];
      surf.pos.y = 50;
      surf.pos.x = 20 + (i * 140);
      if (SDL_BlitSurface(surf.sprite, NULL, sdl->ptr_win, &surf.pos) == -1)
	{
	  fprintf(stderr, "Error while displaying menu sprite [%s] : %s\n",
		  BACKROUND, SDL_GetError);
	  return (EXIT_FAILURE);
	}
      i++;
    }
}

int		display_background(t_sdl_philo *sdl)
{
  SDL_Rect      pos;

  pos.x = 0;
  pos.y = 200;
  if (SDL_BlitSurface(sdl->background, NULL, sdl->ptr_win, &pos) == -1)
    {
      fprintf(stderr, "Error while displaying menu sprite [%s] : %s\n",
              BACKROUND, SDL_GetError);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int		thread_sdl(void *data)
{
  t_sdl_philo	*sdl;
  t_philosophe	*philo;

  sdl = ((t_arg_thread *)(data))->sdl;
  philo = ((t_arg_thread *)(data))->philo;
  if (display_background(sdl) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while (1)
    {
      update_aff(philo, sdl);
      if (SDL_Flip(sdl->ptr_win) == -1)
	{
	  fprintf(stderr, "Error during SDL_Flip : %s\n", SDL_GetError());
	  return (EXIT_FAILURE);
	}
      SDL_Delay(100);
    }
  return (EXIT_SUCCESS);
}

int		load_texture(t_sdl_philo *sdl)
{
  char		*sprite[3];
  int		i;

  i = 0;
  sprite[0] = SLEEP_SPRITE;
  sprite[1] = EAT_SPRITE;
  sprite[2] = THINK_SPRITE;
  if ((sdl->background = IMG_Load(BACKROUND)) == NULL)
    {
      fprintf(stderr, "Error while loading %s : %s\n",
	      BACKROUND, SDL_GetError());
      return (EXIT_FAILURE);
    }
  while (i < 3)
    {
      if ((sdl->sprite_state[i].sprite = IMG_Load(sprite[i])) == NULL)
	{
	  fprintf(stderr, "Error while loading %s : %s\n",
		  sprite[i], SDL_GetError());
	  return (EXIT_FAILURE);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

int		init_sdl(t_sdl_philo *sdl, t_philosophe *philo)
{
  t_arg_thread	arg;

  arg.sdl = sdl;
  arg.philo = philo;
  if (load_texture(sdl) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Error init SDL : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  if ((sdl->ptr_win = SDL_SetVideoMode(sdl->background->w,
				       sdl->background->h + 200,
				       32, SDL_HWSURFACE)) == NULL)
    {
      fprintf(stderr, "Error creation SDL window : %s\n", SDL_GetError());
      return (EXIT_FAILURE);
    }
  sdl->thread = SDL_CreateThread(thread_sdl, &arg);
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
