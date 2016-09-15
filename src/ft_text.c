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

void    ft_licence(void)
{
  fprintf(stderr, "\
\n\
**********************************************************************************\n\
*    Copyright 2015 Marchal at University Paris Diderot                          *\n\
*                                                                                *\n\
*    This program is free software: you can redistribute it and/or modify        *\n\
*    it under the terms of the GNU General Public License as published by        *\n\
*    the Free Software Foundation, either version 3 of the License, or           *\n\
*    (at your option) any later version.                                         *\n\
*                                                                                *\n\
*    This program is distributed in the hope that it will be useful,             *\n\
*    but WITHOUT ANY WARRANTY; without even the implied warranty of              *\n\
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                *\n\
*    GNU General Public License for more details.                                *\n\
*                                                                                *\n\
*    You should have received a copy of the GNU General Public License           *\n\
*    along with this program. If not, see <http://www.gnu.org/licenses/>.        *\n\
*                                                                                *\n\
**********************************************************************************\n\
\n\
");
}

void    ft_help(void)
{
  fprintf(stderr, "\
merge_bp\n\
\n\
           *****************************************\n\
The aim of this tool is to merge two genomic coordinates files to obtain shared \n\
localizations at the base pair level. Files must be formated as following,\n\
with tab used as a separator: \n\
\n\
chromosome_name\tstart\tstop\tpeak_name\n\
\n\
Nomenclature for chromosome must be identical for both coordinates files.\n\
Files must be sorted by chromosome and positions.\n\
           *****************************************\n\
\n\
usage: merge_bp file1 file2 output\n\
\n\
");
}
