#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_mem
{
	int		size;
	long	*sorted;
	char	name;
}	t_mem;

typedef struct s_list
{
	t_mem	a;
	t_mem	b;
}	t_list;

//Prototypes//
/* utils_libft */

int		ft_isdigit(int c);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);

/* utils_libft_2 */
int		ft_count(const char *s, char c);
int		ft_str_size(char const *s, char c, size_t n);
int		ft_trim_size(char const *s, char c, size_t n);
char	*ft_cpy(char const *s, char *str, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);


/* algo_stacks*/

void	a_to_b(t_mem *a, t_mem *b, int chunk_start, int chunk_done);
void	b_to_a(t_mem *a, t_mem *b);
void	algo_algo(t_mem *a, t_mem *b);

#endif
