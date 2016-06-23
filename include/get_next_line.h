/*
** get_next_line.h for gnl
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Mon Jan 11 17:47:55 2016 axel brunel
** Last update Tue Jan 19 16:55:39 2016 axel brunel
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char		*my_strcat(char *, char *);
char		*get_next_line(int);
char		*check_buffer(char *);
char		*check_ret(char *, char *);
int		check(char *);

#endif /* !GET_NEXT_LINE_H_ */
