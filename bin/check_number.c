/*
** check_number.c for check_nbr in /home/brunel_d/rendu/sem_2/prog_elem/
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Feb 27 00:47:01 2016 axel brunel
** Last update Sat Feb 27 06:35:16 2016 axel brunel
*/

#include "sudoku.h"

int	verif_possibility(int **map, int i, int j)
{
  int	k;
  int	count;

  count = 0;
  k = 1;
  while (k < 10)
    {
      if (verif_line(k, i, map) == 0 && verif_column(k, j, map) == 0 &&
	  verif_square(k, i, j, map) == 0)
	{
	  count++;
	}
      k++;
    }
  count = -count;
  return (count);
}

void	put_priority_in_map(int **map)
{
  int	i;
  int	j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (map[i][j] == 0)
	    {
	      map[i][j] = verif_possibility(map, i, j);
	    }
	  j++;
	}
      i++;
    }
}

int	get_priority_zero(int **map)
{
  int	i;
  int	j;
  int	count;

  count = 0;
  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (map[i][j] > 0)
	    count++;
	  j++;
	}
      i++;
    }
  return (count);
}

int	put_order_to_resolve(int *order_priority, int **map, int prio,
			     int pos)
{
  int	i;
  int	j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (map[i][j] == prio)
	    {
	      order_priority[pos++] = (i * 9) + j;
	    }
	  j++;
	}
      i++;
    }
  return (pos);
}

void	get_order_to_resolve(int *order_priority, int **map)
{
  int	i;
  int	pos;
  int	prio;

  pos = 0;
  prio = -1;
  i = get_priority_zero(map);
  while (i >= 0)
    {
      order_priority[pos] = 0;
      pos++;
      i--;
    }
  while (prio > -10)
    {
      pos += (put_order_to_resolve(order_priority, map, prio, pos) - pos);
      prio--;
    }
}
