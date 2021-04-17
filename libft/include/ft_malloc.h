#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/resource.h>
# include <sys/mman.h>


/*
** for 4096B pages
** tiny malloc have 1 page of meta for 1 page of data
** small malloc have 4 page of meta for 64 page of data
** large malloc have 2 pages of meta for 511 to inf pages of data
*/
# define TINY_SIZE		64
# define MEM_ELEM_TINY	64
# define MAX_ELEM_TINY	510

# define SMAL_SIZE		4096
# define MEM_ELEM_SMAL	64
# define MAX_ELEM_SMAL	2046

# define MAX_ELEM_LARG	511

typedef struct	s_ma_bloc
{
	unsigned	off;
	unsigned	len;
}				t_ma_bloc;

typedef struct	s_ma_tiny
{
	unsigned char		mem[MEM_ELEM_TINY * TINY_SIZE];

	t_ma_bloc			meta[MAX_ELEM_TINY];
	unsigned			mem_free;
	unsigned			n_elem;
	struct	s_ma_tiny	*next;
}				t_ma_tiny;

typedef struct	s_ma_smal
{
	char				mem[MEM_ELEM_SMAL * SMAL_SIZE];

	t_ma_bloc			meta[MAX_ELEM_SMAL];
	unsigned			mem_free;
	unsigned			n_elem;
	struct	s_ma_smal	*next;
}				t_ma_smal;

typedef struct	s_ma_larg
{
	void				*mem[MAX_ELEM_LARG];
	size_t				len[MAX_ELEM_LARG];
	
	struct	s_ma_larg	*next;
	unsigned			n_elem;
	int					pad[1];
}				t_ma_larg;

/*
** page size is ignored in this implementation, all mallocs will stay aligned
** with page sizes from 1 to 8192, and up to 16384 for small mallocs
*/
typedef struct	s_malloc
{
	size_t			ps;
	t_ma_tiny		*tiny;
	t_ma_smal		*smal;
	t_ma_larg		*larg;
}				t_malloc;

void			ft_free(void *ptr);
void			*ft_malloc(size_t size);
void			*ft_realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

void			*malloc_alloc(size_t size);
t_malloc		*malloc_data(void);

void			*tiny_malloc(t_malloc *d, unsigned size);
void			*small_malloc(t_malloc *d, unsigned size);
void			*large_malloc(t_malloc *d, size_t size);
int				large_free(t_malloc *d, void *ptr);
int				small_free(t_malloc *d, void *ptr);
void			tiny_free(t_malloc *d, void *ptr);

#endif
