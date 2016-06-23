/*
** column.c for column in /home/blanch_p/Semestre2/Prog_elem/test/sudoku/
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sat Feb 27 11:11:58 2016 Alexandre Blanchard
** Last update Sat Feb 27 12:37:39 2016 Alexandre Blanchard
*/

#include "sudoku.h"

int	check_good_column(int column)
{
  if (column < 1 || column > 9)
    {
      printf("Bad column:\nMust be between 1 and 9\n");
      return (-1);
    }
  else
    printf("The column n°%i is :\n\n", column);
  return (0);
}

void	print_the_column(int **map, int column)
{
  int	i;
  int	j;

  j = -1;
  i = -1;
  while (++j < 9)
    {
      printf("|");
      i = -1;
      while (++i < 9)
  	{
  	  if (i == column - 1)
  	    printf("%i", map[j][column - 1]);
	  else
	    printf("X");
  	  if (i != 8)
  	    printf(" ");
  	}
      printf("|\n");
    }
}

int	show_column(int **map, int column)
{
  if (check_good_column(column) != 0)
    return (-1);
  printf("|-----------------|\n");
  print_the_column(map, column);
  printf("|-----------------|\n");
  printf("\n");
  return (0);
}

void	resolve_sudo_column(char *str, int num, int column)
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
  show_column(map, column);
  free_tabs(order_priority, map);
}

int	get_column(int column)
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
      resolve_sudo_column(s, (220 * i), column);
      i++;
    }
  free(s);
  return (0);
}
