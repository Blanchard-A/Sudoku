/*
** bootstrap.c for fdp in /home/brunel_d/rendu/get_next_line/bootstrap_gnl
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Tue Jan  5 13:28:12 2016 axel brunel
** Last update Sat Feb 27 07:33:57 2016 axel brunel
*/

#include "get_next_line.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*tmp;

  j = 0;
  i = 0;
  while (dest[i++]);
  while (src[j] != '\0' && src[j++] != '\n');
  if ((tmp = malloc(sizeof(char) * (i + j))) == NULL)
    return (NULL);
  i = -1;
  j = 0;
  while (dest[++i])
    {
      tmp[i] = dest[i];
    }
  while (src[j] != '\0' && src[j] != '\n')
    {
      tmp[i] = src[j];
      i++;
      j++;
    }
  tmp[i] = '\0';
  return (tmp);
}

int	check(char *buffer)
{
  int	i;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

char	*check_ret(char *ret, char *buffer)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (buffer[i] != '\0' && buffer[i++] != '\n');
  while (buffer[i] != '\0' && buffer[i] != '\n')
    {
      ret[j] = buffer[i];
      i++;
      j++;
    }
  ret[j] = '\0';
  return (ret);
}

char	*check_buffer(char *buffer)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (buffer[j] != '\0' && buffer[j++] != '\n');
  while (buffer[j] != '\0')
    {
      buffer[i] = buffer[j];
      j++;
      i++;
    }
  buffer[i] = '\0';
  buffer[i + 1] = '\0';
  return (buffer);
}

char	*get_next_line(int fd)
{
  static char	buffer[READ_SIZE] = {0};
  char		*ret;
  int		len;

  if ((ret = malloc(sizeof(char) * (READ_SIZE + 1))) == NULL)
    return (NULL);
  if ((fd == 0) && (check_buffer(buffer)))
    ret = check_ret(ret, buffer);
  else if ((fd != 0) && (ret = check_ret(ret, buffer)))
    check_buffer(buffer);
  if ((check(buffer) == 1))
    return (ret);
  if (((len = read(fd, buffer, READ_SIZE)) == -1) || (len == 0))
    return (NULL);
  while (len > 0)
    {
      ret = my_strcat(ret, buffer);
      if ((check(buffer) == 1))
	  return (ret);
      if (((len = read(fd, buffer, READ_SIZE)) == -1) || (len == 0))
	return (NULL);
    }
  return (NULL);
}
