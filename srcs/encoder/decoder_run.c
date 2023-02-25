/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 05:04:38 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:38:26 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/**
 * @brief Está função executa o ./decoder em um processo filho,
 * e depois imprime na tela os dados recebidos pelo decoder
 * 
 * @param path 
 * @param size 
 */
void	decoder_run(char *path, int size)
{
	int		pid;
	int		shmid;
	int		shmid_msg;
	key_t	key;
	t_data	*data;

	ft_memmove(ft_memchr(path, '.', ft_strlen(path)), ".dat", 4);
	key = ftok(path, 'x');
	shmid = shmget(key, sizeof(t_data), IPC_CREAT | IPC_EXCL
			| SHM_R | SHM_W);
	shmid_msg = shmget(key + 1, sizeof(wchar_t) * (size + 1),
			IPC_CREAT | IPC_EXCL | SHM_R | SHM_W);
	if (shmid == -1 || shmid_msg == -1)
		terminate(ENC_SHM_NEW);
	pid = fork();
	if (pid != 0)
	{
		waitpid(pid, NULL, 0);
		data = (t_data *)shmat(shmid, (void *)0, 0);
		data->msg = (wchar_t *)shmat(shmid_msg, (void *)0, 0);
		printf("\n==================================\n");
		printf("%ls", data->msg);
		printf("\n==================================\n");
		printf("time: %fs\n", data->time);
		printf("ziped: %d bytes\n", data->ziped);
		printf("unziped: %d bytes\n", data->unziped);
		if ((shmctl(shmid, IPC_RMID, NULL)) == -1
			|| shmctl(shmid_msg, IPC_RMID, NULL) == -1)
			terminate(ENC_SHM_CLOSE);
	}
	else
		execl("./decoder", "decoder", path, NULL);
}
