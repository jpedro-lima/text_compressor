/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:08:34 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:41:59 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

int	main(int argc, char **argv)
{
	t_data	data;
	FILE	*fp;
	key_t	key;
	int		shmid;

	errno = 0;
	if (argc == 2)
	{
		setlocale(LC_CTYPE, "");
		if (!ft_strnstr(argv[1], ".dat", ft_strlen(argv[1])))
			terminate(DEC_FILE);
		fp = fopen(argv[1], "r");
		if (!fp)
			terminate(DEC_FOPEN);
		fread(&key, sizeof(key_t), 1, fp);
		shmid = shmget(key, 0, 0);
		if (shmid == -1)
			terminate(DEC_SHM_ACC);
		data = read_dat_file(fp, shmid);
		response(&data, shmid, argv[1]);
	}
	else
		terminate(DEC_ARG);
}
