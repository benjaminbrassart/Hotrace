/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:54:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 02:01:04 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFFER_SIZE 2048

typedef struct s_btree	t_btree;
typedef struct s_list	t_list;
typedef unsigned long	t_hash;

struct s_btree
{
	t_hash	key;
	char	*value;
	t_btree	*left;
	t_btree	*right;
};

struct s_list
{
	t_hash	key;
	char	*value;
	t_list	*next;
};

int				get_next_line(int fd, char **line);

void			*ft_memmove(void *dst, void const *src, unsigned int n);

void			*ft_memset(void *dst, int c, unsigned int n);

char			*ft_strdup(char const *s)
				__attribute__((nonnull(1), malloc));

unsigned int	ft_strlen(char const *s)
				__attribute__((nonnull(1)));

unsigned int	hash(char const *s);

/* create a single node with left and right to nil */
t_btree			*btree_create(char const *key, char *value)
				__attribute__((nonnull(1), malloc));

/* recursively destroy a tree */
void			btree_destroy(t_btree *root);

/* search for a specific hash in a tree */
t_btree			*btree_search(t_btree *root, t_hash hash);

/* insert a new node in a tree */
t_btree			*btree_insert(t_btree **root, t_btree *node)
				__attribute__((nonnull(1, 2)));

t_list			*list_create(t_hash key, char *value);

void			list_destroy(t_list **root);

t_list			*list_search(t_list *root, t_hash key);

t_list			*list_insert(t_list **root, t_list *list);

#endif
