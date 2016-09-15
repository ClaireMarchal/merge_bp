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


int	main(int argc, char **argv)
{
  FILE		*fd1;
  FILE		*fd_out;

  ft_licence();
  ft_help();
  if (argc == 4)
    {
      if (ft_strcmp(argv[1], argv[3]) == 0 || ft_strcmp(argv[2], argv[3]) == 0)
	{
	  fprintf(stderr, "Error: bad output file\n");
	  return (0);
	}
      fd1 = fopen(argv[1], "r");
      fd_out = fopen(argv[3], "a");
      if (fd1 == NULL || fd_out == NULL)
	{
	  fprintf(stderr, "\nError: %s\n", strerror(errno));
	  return (0);
	}
      fprintf(stderr, "Please wait...\n");
      ft_merge(fd1, fd_out, argv[2]);
      fclose(fd_out);
      fprintf(stderr, "Job done.\n\n");
    }
  else
    fprintf(stderr, "Wrong argument number!\n");
  return (0);
}
