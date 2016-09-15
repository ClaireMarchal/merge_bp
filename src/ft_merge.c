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


int	     ft_merge(FILE *fd1, FILE *fd_out, char *file2)
{
  size_t        buffer1;
  char          *line1;
  char          *chr1;
  int		start1;
  int           end1;
  t_list        *list;
  FILE		*fd;
  char		**split;

  buffer1 = 200;
  line1 = (char *)malloc(buffer1 * sizeof(char));
  if (line1 == NULL)
    return (-1);
  list = NULL;
  fd = fd_out;
  fd_out = fd;
  chr1 = (char *)malloc(200 * sizeof(char));
  if (chr1 == NULL)
    return (0);
  while (getline(&line1, &buffer1, fd1) > 0)
    {
      split = ft_strsplit(line1, '\t');
      while (split == NULL && getline(&line1, &buffer1, fd1))
	  split = ft_strsplit(line1, '\t');
      start1 = atoi(split[1]);
      end1 = atoi(split[2]);
      if (ft_strcmp(chr1, split[0]) != 0)
	{
	  strcpy(chr1, split[0]);
	  fprintf(stderr, "	Processing %s\n", split[0]);
          ft_dellistbyend(list);
          list = ft_newchr(chr1, file2);
	  if (list == NULL)
	    {
	      ft_freetab(split);
	      free(chr1);
	      chr1 = NULL;
	      free(line1);
	      fclose(fd1);
	      return (0);
	    }
	}
      while (list->prev && list->end > start1)
	  list = list->prev;
      while (list->next && start1 > list->end)
	  list = list->next;
      while (end1 >= list->start && start1 <= list->end)
        {
          fprintf(fd_out, "%s\t%d\t%d\t%s\t%s\n", chr1,			\
		  max(start1, list->start), min(end1, list->end),	\
		  split[3], list->name); 
          if (list->next)
	      list = list->next;
	  else
	      break;
	}
      ft_freetab(split);
    }
  ft_dellistbyend(list);
  free(chr1);
  chr1 = NULL;
  free(line1);
  fclose(fd1);
  return (0);
}
