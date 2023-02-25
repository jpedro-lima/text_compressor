/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:08:10 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:31:46 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECODER_H
# define DECODER_H

# include "libft.h"
# include "error_message.h"

# include <stdio.h>			// perror
# include <errno.h>			// var errno
# include <wchar.h>			// struct wchar_t
# include <locale.h>		// setlocale
# include <sys/types.h>		// macro key_t
# include <sys/ipc.h>		// interprocess communication structure
# include <sys/shm.h>		// shared memory functions
# include <time.h>			// for clock()

# define BUFFER 32

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
wchar_t	*concatc(wchar_t *str, wchar_t c);

//read_dat_file.c
t_data	read_dat_file(FILE *fp, key_t key);

//response.c
void	response(t_data *data, int shmid, char *path);
#endif //DECODER_H
