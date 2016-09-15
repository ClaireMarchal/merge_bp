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

void    ft_dellistbyend(t_list *list)
{
  if (list == NULL)
    return;
  while (list->next)
    list = list->next;
  while (list->prev)
    {
      free(list->chr);
      list->chr = NULL;
      free(list->name);
      list->name = NULL;
      list->next = NULL;
      list = list->prev;
      list->next->prev = NULL;
    }
  free(list->chr);
  list->chr = NULL;
  free(list->name);
  list->name = NULL;
  list->next = NULL;
  list->prev = NULL;
  free(list);
  list = NULL;
}
