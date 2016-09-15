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

static	int	ft_strlen(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

static	int	ft_count_occur(char *str, char sep)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i])
    {
      if (str[i] == sep)
	n++;
      i++;
    }
  return (n);
}

char		**ft_strsplit(char *line, char sep)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  if (line == NULL)
    return (NULL);
  if (ft_count_occur(line, '\t') != 3)
    {
      fprintf(stderr, "Bad line format!\nThis line has been suppressed: %s", line);
      return (NULL);
    }
  tab = (char **)malloc(4 * sizeof(char *));
  if (tab == NULL)
    return (NULL);
  i = 0;
  while (i < 4)
    {
      tab[i] = (char *)malloc(ft_strlen(line) * sizeof(char));
      if (tab[i] == NULL)
	return (NULL);
      i++;
    }
  i = 0;
  j = 0;
  k = 0;
  while (line[i])
  {
    while ((line[i] == sep || line[i] == '\n') && line[i])
	{
	  tab[j][k] = '\0';
	  j++;
	  k = 0;
	  i++;
	}
    while (line[i] != sep && line[i] != '\n'  && line[i])
	{
	  if (line[i] != '\n')
	    {
	      tab[j][k] = line[i];
	      k++;
	    }
	  i++;
	}
  }
  return (tab);
}
