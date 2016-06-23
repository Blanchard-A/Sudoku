/*
** sudoku.h for sudo in /home/brunel_d/rendu/sem_2/prog_elem/sudoki-bi/include
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Fri Feb 26 20:49:20 2016 axel brunel
** Last update Sat Feb 27 07:03:11 2016 axel brunel
*/

#ifndef SUDOKU_H_
# define SUDOKU_H_
# define UNUSED __attribute__((__unused__))

#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	check_error_solvable(int **);
void	show_X();
int	check_exactly(char *, int);
void	free_tabs(int *, int **);
int	check_bordure(char *, int);
int	check_spaces(char *, int);
int	check_if_number(char *, int);
int	check_char_by_char(char *, int, char *);
int	check_error_format(char *, int);
void	put_nbr_in_map_to_2d(char *, int **, int);
int	**mllc_map(int **);
int	replace_all_zero(int **, int, int *);
void	show_map(int **);
void	resolve_sudo(char *, int);
int	verif_line(int, int, int **);
int	verif_column(int, int, int **);
int	verif_square(int, int, int, int **);
int	verif_possibility(int **, int, int);
void	put_priority_in_map(int **);
int	get_priority_zero(int **);
int	put_order_to_resolve(int *, int **, int, int);
void	get_order_to_resolve(int *, int **);

#endif /* !SUDOKU_H_ */
