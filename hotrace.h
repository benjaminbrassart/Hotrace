/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:54:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 00:25:28 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFFER_SIZE 2048

typedef struct s_btree	t_btree;
typedef unsigned long	t_hash;

struct s_btree
{
	t_hash	key;
	char	*value;
	t_btree	*left;
	t_btree	*right;
};

int				get_next_line(int fd, char **line);

void			*ft_memmove(void *dst, void const *src, unsigned int n);

void			*ft_memset(void *dst, int c, unsigned int n);

char			*ft_strdup(char const *s);

unsigned int	ft_strlen(char const *s);

t_hash			hash_str(char const *s);

/* create a single node with left and right to nil */
t_btree			*btree_create(char const *key, char *value);

/* recursively destroy a tree */
void			btree_destroy(t_btree *root);

t_btree			*btree_search(t_btree *root, t_hash hash);

#endif
