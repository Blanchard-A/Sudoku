/*
** main2.c for main in /home/blanch_p/rendu/Semestre2/Prog_elem/sudoku/
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sat Feb 27 12:38:33 2016 Alexandre Blanchard
** Last update Sat Feb 27 14:24:09 2016 Alexandre Blanchard
*/

#include "sudoku.h"

int	main(int ac, char **av)
{
  if (ac == 1)
    without_arg();
  else if (ac % 2 != 1 && ac != 3)
    {
      printf("Bad usage: ./sudoki-bi -option number\n\n");
      printf("Possible options:\n\t-l: have line\n\t-c:have column\n\n");
      printf("Number must be from 1 to 9\n\n");
    }
  else
    {
      if (av[1][0] == '-' && av[1][1] == 'l')
        get_line(atoi(av[2]));
      else if (av[1][0] == '-' && av[1][1] == 'c')
        get_column(atoi(av[2]));
      else
	{
	  printf("Bad option !\n");
	  printf("Possible options:\n\t-l: have line\n\t-c:have column\n\n");
	  printf("Number must be from 1 to 9\n\n");
	}
    }
  return (0);
}
