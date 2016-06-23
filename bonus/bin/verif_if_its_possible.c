/*
** verif_if_its_possible.c for viip in /rendu/sem_2/prog_elem/sudoki-bi/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Feb 27 06:33:47 2016 axel brunel
** Last update Sat Feb 27 06:34:44 2016 axel brunel
*/

#include "sudoku.h"

int	verif_line(int nb, int line, int **map)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      if (map[line][i] == nb)
        return (-1);
      i++;
    }
  return (0);
}

int	verif_column(int nb, int column, int **map)
{
  int	i;

  i = 0;
  while (i < 9)
    {
      if (map[i][column] == nb)
        return (-1);
      i++;
    }
  return (0);
}

int	verif_square(int nb, int line, int column, int **map)
{
  int	a;
  int	b;
  int	stock;
  int	stock_bis;

  a = 3 * (line / 3);
  b = 3 * (column / 3);
  stock = a;
  stock_bis = b;
  while (stock < (a + 3))
    {
      while (stock_bis < (b + 3))
        {
          if (map[stock][stock_bis] == nb)
            return (-1);
          stock_bis++;
        }
      stock_bis -= 3;
      stock++;
    }
  return (0);
}
