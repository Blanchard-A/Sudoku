/*
** individual_basics_test.c for ibt in /rendu/sem_2/prog_elem/sudoki-bi/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Feb 27 06:23:51 2016 axel brunel
** Last update Sat Feb 27 06:36:05 2016 axel brunel
*/

#include "sudoku.h"

int	check_bordure(char *str, int pos)
{
  int	max;

  max = pos + 180;
  while (pos < max)
    {
      if (pos % 20 == 0 || pos % 20 == 19)
        {
          if (str[pos] != '|')
            return (-1);
        }
      pos++;
    }
  return (0);
}

int	check_spaces(char *str, int pos)
{
  int	max;

  max = pos + 180;
  while (pos < max)
    {
      if (pos % 20 == 1 || pos % 20 == 3 || pos % 20 == 5 || pos % 20 == 7 ||
          pos % 20 == 9 || pos % 20 == 11 || pos % 20 == 13 ||
          pos % 20 == 15 || pos % 20 == 17)
        {
          if (str[pos] != ' ')
            return (-1);
        }
      pos++;
    }
  return (0);
}

int	check_if_number(char *str, int pos)
{
  int	max;

  max = pos + 180;
  while (pos < max)
    {
      if (pos % 20 == 2 || pos % 20 == 4 || pos % 20 == 6 || pos % 20 == 8 ||
          pos % 20 == 10 || pos % 20 == 12 || pos % 20 == 14 ||
          pos % 20 == 16 || pos % 20 == 18)
        {
          if ((str[pos] < 48 || str[pos] > 57) && str[pos] != ' ')
            return (-1);
        }
      pos++;
    }
  return (0);
}

int	check_char_by_char(char *str, int pos, char *to_compare)
{
  int	j;

  j = 0;
  while (to_compare[j])
    {
      if (to_compare[j] != str[pos])
        return (-1);
      j++;
      pos++;
    }
  return (0);
}

int	check_error_format(char *str, int repeat)
{
  int	i;

  if ((strlen(str) % 220) != 0)
    {
      printf("MAP ERROR\n\n");
      return (-1);
    }
  i = 0;
  while (str[i])
    {
      if (str[i] != '-' && str[i] != '|' && str[i] != ' ' &&
          (str[i] < 48 || str[i] > 57))
        {
          printf("MAP ERROR\n\n");
          return (-1);
        }
      i++;
    }
  if ((check_exactly(str, repeat)) == -1)
    {
      printf("MAP ERROR\n\n");
      return (-1);
    }
  return (0);
}
