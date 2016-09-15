/******************************************************************************/
/*                                                                            */
/*    Copyright 2015                                                          */
/*                                                                            */
/*    This program is free software: you can redistribute it and/or modify    */
/*    it under the terms of the GNU General Public License as published by    */
/*    the Free Software Foundation, either version 3 of the License, or       */
/*    (at your option) any later version.                                     */
/*                                                                            */
/*    This program is distributed in the hope that it will be useful,         */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the            */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with this program. If not, see <http://www.gnu.org/licenses/>.    */
/*                                                                            */
/******************************************************************************/

#include "merge_peaks.h"


static	void	ft_putinlist(t_list **list, char **split)
{
  char	*chr2;
  char	*name2;
  long	start2;
  long	end2;

  chr2 = (char *)malloc(20 * sizeof(char));
  name2 = (char *)malloc(100 * sizeof(char));
  if (chr2 == NULL || name2 == NULL)
    return;
  strcpy(chr2, split[0]);
  start2 = atoi(split[1]);
  end2 = atoi(split[2]);
  strcpy(name2, split[3]);
  (*list)->chr = chr2;
  (*list)->start = start2;
  (*list)->end = end2;
  (*list)->name = name2;
}

t_list  *ft_newchr(char *chr1, char *file2)
{
  FILE		*fd2;
  t_list	*list;
  t_list	*tmp;
  char		*line;
  size_t	buffer;
  char		**split;

  list = NULL;
  tmp = NULL;
  buffer = 200;
  line = (char *)malloc(buffer * sizeof(char));
  if (line == NULL)
    return (NULL);
  fd2 = fopen(file2, "r");
  if (fd2 == NULL)
    {
      fprintf(stderr, "\nError: %s\n", strerror(errno));
      return (NULL);
    }
  getline(&line, &buffer, fd2);
  split = ft_strsplit(line, '\t');
  while (ft_strcmp(chr1, split[0]) != 0)
    {
      ft_freetab(split);
      split = NULL;
      getline(&line, &buffer, fd2);
      split = ft_strsplit(line, '\t');
    }
  if (ft_strcmp(chr1, split[0]) == 0)
    {
      list = (t_list *)malloc(sizeof(t_list));
      if (list == NULL)
	return (NULL);
      ft_putinlist(&list, split);
      list->prev = NULL;
      list->next = NULL;
      ft_freetab(split);
      getline(&line, &buffer, fd2);
      split = ft_strsplit(line, '\t');
    }
  while (ft_strcmp(chr1, split[0]) == 0)
    {
      tmp = list;
      list = (t_list *)malloc(sizeof(t_list));
      if (list == NULL)
	return (NULL);
      ft_putinlist(&list, split);
      list->prev = tmp;
      list->next = NULL;
      list->prev->next = list;
      ft_freetab(split);
      split = NULL;
      if (getline(&line, &buffer, fd2) <= 0)
	  break;
      split = ft_strsplit(line, '\t');
    }
  if (split)
    ft_freetab(split);
  free(line);
  line = NULL;
  fclose(fd2);
  while (list && list->prev)
    list = list->prev;
  return (list);
}
