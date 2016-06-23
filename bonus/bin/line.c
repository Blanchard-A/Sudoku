/*
** line.c for line in /home/blanch_p/Semestre2/Prog_elem/test/sudoku/bonus/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sat Feb 27 10:50:09 2016 Alexandre Blanchard
** Last update Sat Feb 27 12:37:49 2016 Alexandre Blanchard
*/

#include "sudoku.h"

int	check_good_line(int line)
{
  if (line < 1 || line > 9)
    {
      printf("Bad line:\nMust be between 1 and 9\n");
      return (-1);
    }
  else
    printf("The line n°%i is :\n\n", line);
  return (0);
}

void	print_the_line(int **map, int line)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      if (i == 0)
	printf("|");
      printf("%i", map[line][i]);
      if (i == 8)
	printf("|\n");
      else
	printf(" ");
      i++;
    }
}

int	show_line(int **map, int line)
{
  int	j;

  j = -1;
  if (check_good_line(line) != 0)
    return (-1);
  printf("|-----------------|\n");
  while (++j < 9)
    {
      if (j == line - 1)
	{
	  print_the_line(map, line - 1);
	}
      else
	printf("|X X X X X X X X X|\n");
    }
  printf("|-----------------|\n");
  printf("\n");
  return (0);
}

void	resolve_sudo_line(char *str, int num, int line)
{
  int	**map;
  int	*order_priority;

  if ((order_priority = malloc(sizeof(int) * (81))) == NULL)
    return ;
  map = NULL;
  map = mllc_map(map);
  put_nbr_in_map_to_2d(str, map, num);
  if ((check_error_solvable(map)) == -1)
    {
      show_X_options();
      return ;
    }
  put_priority_in_map(map);
  get_order_to_resolve(order_priority, map);
  replace_all_zero(map, 0, order_priority);
  if ((check_error_solvable(map)) == -1)
    {
      show_X_options();
      return ;
    }
  show_line(map, line);
  free_tabs(order_priority, map);
}

int	get_line(int line)
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
  while (repeat-- > 0)
    {
      printf("Sudoku n°%i:\n", i + 1);
      resolve_sudo_line(s, (220 * i), line);
      i++;
    }
  free(s);
  return (0);
}
