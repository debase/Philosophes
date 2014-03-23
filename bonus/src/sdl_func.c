/*
** sdl_func.c for sdl_funct in /home/debas_e/Project/System_Unix/PSU_2013_philo/bonus
**
** Made by Etienne
** Login   <debas_e@epitech.net>
**
** Started on  Fri Mar 21 15:00:35 2014 Etienne
** Last update Sun Mar 23 14:48:49 2014 Etienne
*/

#include "sdl_philo.h"

int		thread_loop(t_sdl_philo *sdl, t_philosophe *philo)
{
  SDL_Event	event;

  while (SDL_PollEvent(&event))
    if (event.type == SDL_QUIT || ((event.type == SDL_KEYDOWN)
				   && event.key.keysym.sym == SDLK_ESCAPE))
      {
	SDL_Quit();
	return (1);
      }
  update_aff(philo, sdl);
  if (SDL_Flip(sdl->ptr_win) == -1)
    {
      fprintf(stderr, "Error during SDL_Flip : %s\n", SDL_GetError());
      return (1);
    }
  SDL_Delay(30);
  return (0);
}

void		*thread_sdl(void *data)
{
  t_sdl_philo	*sdl;
  t_philosophe	*philo;

  sdl = ((t_arg_thread *)(data))->sdl;
  philo = ((t_arg_thread *)(data))->philo;
  if (display_background(sdl) == EXIT_FAILURE)
    return (NULL);
  if (sdl->music != NULL)
    {
      Mix_HaltMusic();
      Mix_PlayMusic(sdl->music, -1);
    }
  while (1)
    {
      if (thread_loop(sdl, philo) == 1)
	return (NULL);
    }
  return (NULL);
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

void		init_music(t_sdl_philo *sdl)
{
  sdl->music = NULL;
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096))
    {
      fprintf(stderr, "Error initializing audio : %s", Mix_GetError());
      return ;
    }
  sdl->music = Mix_LoadMUS(MUSIC_PATH);
  if (sdl->music == NULL)
    {
      fprintf(stderr, "Error while loading music [%s] : %s\n",
	      MUSIC_PATH, SDL_GetError());
    }
}
