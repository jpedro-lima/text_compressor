/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:07:02 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:32:20 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENCODER_H
# define ENCODER_H

# include "libft.h"
# include "error_message.h"
# include <stdio.h>			// perror() e printf()
# include <errno.h>			// var errno
# include <wchar.h>			// struct wchar_t
# include <locale.h>		// setlocale
# include <sys/types.h>		// macro key_t
# include <sys/ipc.h>		// interprocess communication structure
# include <sys/shm.h>		// shared memory functions
# include <sys/types.h>		// waitpid()
# include <sys/wait.h>		// waitpid()

# define BUFFER 32

typedef struct s_tree
{
	wchar_t			c;
	int				freq;
	struct s_tree	*next;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_list
{
	t_tree	*begin;
	int		size;
}	t_list;

typedef struct s_dictionary
{
	wchar_t	c;
	char	bin[BUFFER];
}	t_dict;

typedef struct s_data
{
	double	time;
	wchar_t	*msg;
	int		unziped;
	int		ziped;
}	t_data;

// utils.c
void	terminate(char	*str);
t_tree	*new_node_tree(t_tree *right, t_tree *left);
int		new_node_list(wchar_t c, t_list *list);
void	clear_tree(t_tree *root);
void	clear_list(t_list *list);

// huffman.c
t_list	create_character_list(FILE *fp);
t_list	make_huffman_tree(t_list *list);

// shared_memory.c
key_t	make_dictionary(t_list *tree, t_list *list, char *path);

//dat_file.c
int		make_compressed_file(key_t key, char *path, FILE *fp);

// decoder_run.c
void	decoder_run(char *path, int size);

#endif //ENCODER_H
