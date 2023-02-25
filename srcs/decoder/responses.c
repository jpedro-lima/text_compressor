/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   responses.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 04:13:11 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 05:06:39 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

/**
 * @brief Está função irá verificar se o encoder iniciou
 * uma memória compartilhada para receber os dados da descompressão se a memória
 * não foi iniciada, ele imprime os dados da descompressão para o usuário
 * 
 * @param data 
 * @param shmid 
 * @param path 
 */
void	response(t_data *data, int shmid, char *path)
{
	int		shmid_response;
	int		shmid_msg;
	key_t	key_msg;
	t_data	*shm;

	key_msg = ftok(path, 'x');
	shmid_response = shmget(key_msg, 0, 0);
	if (shmid_response == -1)
	{
		printf("==================================\n");
		printf("%ls\n", data->msg);
		printf("==================================\n");
		printf("time: %fs\n", data->time);
		printf("ziped: %d bytes\n", data->ziped);
		printf("unziped: %d bytes\n", data->unziped);
		if ((shmctl(shmid, IPC_RMID, NULL)) == -1)
			terminate("Erro shmctl()");
	}
	else
	{
		shm = (t_data *)shmat(shmid_response, (void *)0, 0);
		shmid_msg = shmget(key_msg + 1, 0, 0);
		if (shmid_msg == -1)
			terminate(DEC_SHM_ACC);
		shm->msg = (wchar_t *)shmat(shmid_msg, (void *)0, 0);
		wcscpy(shm->msg, data->msg);
		shm->time = data->time;
		shm->ziped = data->ziped;
		shm->unziped = data->unziped;
	}
	free(data->msg);
}
