/*
** main.c for main in /home/brunel_d/rendu/sem_2/prog_elem/sudoki-bi/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Fri Feb 26 20:50:37 2016 axel brunel
** Last update Sat Feb 27 12:39:04 2016 Alexandre Blanchard
*/

#include "sudoku.h"

void	put_nbr_in_map_to_2d(char *str, int **map, int num)
{
  int	i;
  int	j;
  int	pos;
  int	retenu;

  j = 0;
  i = 0;
  pos = num + 22;
  retenu = num + 22;
  while (retenu < (num + 220))
    {
      if (str[retenu] != ' ' && j < 9 && i < 9)
	map[i][j++] = str[retenu] - 48;
      else if (str[retenu] == ' ' && j < 9 && i < 9)
	map[i][j++] = 0;
      else
	{
	  pos += 20;
	  retenu = pos - 2;
	  i++;
	  j = 0;
	}
      retenu += 2;
    }
}

int	**mllc_map(int **map)
{
  int	i;

  i = 0;
  if ((map = malloc(sizeof(int *) * 9)) == NULL)
    return (NULL);
  while (i < 9)
    {
      if ((map[i] = malloc(sizeof(int) * 9)) == NULL)
	return (NULL);
      i++;
    }
  return (map);
}

int	replace_all_zero(int **map, int pos, int *order_priority)
{
  int	i;
  int	j;
  int	k;

  if (pos == 82)
    return (0);
  k = 1;
  i = order_priority[pos] / 9;
  j = order_priority[pos] % 9;
  if (map[i][j] > 0)
    return (replace_all_zero(map, pos + 1, order_priority));
  while (k < 10)
    {
      if (verif_line(k, i, map) == 0 && verif_column(k, j, map) == 0 &&
	  verif_square(k, i, j, map) == 0)
	{
	  map[i][j] = k;
	  if (replace_all_zero(map, pos + 1, order_priority) == 0)
	    return (0);
	}
      k++;
    }
  map[i][j] = 0;
  return (-1);
}

void	resolve_sudo(char *str, int num)
{
  int	**map;
  int	*order_priority;

  if (num > 0)
    printf("####################\n");
  if ((order_priority = malloc(sizeof(int) * (81))) == NULL)
    return ;
  map = NULL;
  map = mllc_map(map);
  put_nbr_in_map_to_2d(str, map, num);
  if ((check_error_solvable(map)) == -1)
    {
      show_X();
      return ;
    }
  put_priority_in_map(map);
  get_order_to_resolve(order_priority, map);
  replace_all_zero(map, 0, order_priority);
  if ((check_error_solvable(map)) == -1)
    {
      show_X();
      return ;
    }
  show_map(map);
  free_tabs(order_priority, map);
}

int	without_arg()
{
  char	*s;
  char	*get;
  int	i;
  int	repeat;

  if ((s = malloc(sizeof(char) * (1))) == NULL)
    return (-1);
  s[0] = '\0';
  while ((get = get_next_line(0)) != NULL)
    {
      s = my_strcat(s, get);
      free(get);
    }
  i = 0;
  repeat = strlen(s) / 220;
  if (check_error_format(s, repeat) == -1)
    return (-1);
  while (repeat > 0)
    {
      resolve_sudo(s, (220 * i));
      i++;
      repeat--;
    }
  free(s);
  return (0);
}
