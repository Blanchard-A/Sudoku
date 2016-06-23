/*
** check_error_solvable.c for c_e_s in /rendu/sem_2/prog_elem/sudoki-bi/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Feb 27 06:21:37 2016 axel brunel
** Last update Sat Feb 27 12:19:31 2016 Alexandre Blanchard
*/

#include "sudoku.h"

int	check_error_solvable(int **map)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
        {
          if (map[i][j] != 0)
            {
              k = map[i][j];
              map[i][j] = 0;
              if (verif_line(k, i, map) != 0 ||
                  verif_column(k, j, map) != 0 ||
                  verif_square(k, i, j, map) != 0)
                return (-1);
              map[i][j] = k;
            }
          j++;
        }
      i++;
    }
  return (0);
}

void	show_X()
{
  printf("|------------------|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("| X X X X X X X X X|\n| X X X X X X X X X|\n");
  printf("|------------------|\n");
}

int	check_exactly(char *str, int repeat)
{
  int	i;

  i = 0;
  while (repeat > 0)
    {
      if ((check_char_by_char(str, (i * 220), "|------------------|")) == -1)
        return (-1);
      if ((check_char_by_char(str, ((i * 220) + 200),
                              "|------------------|")) == -1)
        return (-1);
      if ((check_if_number(str, ((i * 220) + 20))) == -1)
        return (-1);
      if ((check_spaces(str, ((i * 220) + 20))) == -1)
        return (-1);
      if ((check_bordure(str, ((i * 220) + 20))) == -1)
        return (-1);
      i++;
      repeat--;
    }
  return (0);
}

void	show_map(int **map)
{
  int	i;
  int	j;

  i = 0;
  printf("|------------------|\n");
  while (i < 9)
    {
      j = 0;
      printf("|");
      while (j < 9)
        {
          printf(" %d", map[i][j]);
          j++;
        }
      i++;
      printf("|\n");
    }
  printf("|------------------|\n");
}

void	free_tabs(int *order_priority, int **map)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      free(map[i]);
      i++;
    }
  free(map);
  free(order_priority);
}
