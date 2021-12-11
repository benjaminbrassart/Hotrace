/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:54:14 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/11 12:11:55 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# define BUFFER_SIZE 2048
# define HASH_SEED 1125899906842597ULL

typedef struct s_btree		t_btree;
typedef struct s_list		t_list;
typedef unsigned long long	t_hash;

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

int				ft_putstr(char const *s);

int				get_next_line(int fd, char **line);

t_hash			hash(char const *s);

/* create a single node with left and right to nil */
t_btree			*btree_create(t_hash key, char *value)
				__attribute__((malloc));

/* recursively destroy a tree */
void			btree_destroy(t_btree *root);

/* search for a specific hash in a tree */
t_btree			*btree_search(t_btree *root, t_hash hash);

/* insert a new node in a tree */
void			btree_insert(t_btree **root, t_btree *node)
				__attribute__((nonnull(1, 2)));

int				btree_height(t_btree *node);

int				btree_balance_factor(t_btree *node);

t_btree			*btree_llrotate(t_btree *node);

t_btree			*btree_lrrotate(t_btree *node);

t_btree			*btree_rlrotate(t_btree *node);

t_btree			*btree_rrrotate(t_btree *node);

t_btree			*btree_balance(t_btree *node);

#endif
