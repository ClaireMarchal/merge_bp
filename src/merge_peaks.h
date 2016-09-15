#ifndef	MERGE_PEAKS_H
#define	MERGE_PEAKS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

typedef struct  s_list
{
  char          *chr;
  int           start;
  int		end;
  char          *name;
  struct s_list *prev;
  struct s_list *next;
}               t_list;

void    ft_licence(void);
void    ft_help(void);
int     ft_strcmp(const char *s1, const char *s2);
void    ft_freetab(char **tab);
char    **ft_strsplit(char *str, char c);
int     ft_merge(FILE *fd1, FILE *fd_out, char *file2);
void    ft_dellistbyend(t_list *list);
t_list  *ft_newchr(char *chr1, char *file2);

#endif
