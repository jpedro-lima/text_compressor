/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:08:37 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/14 17:45:27 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

int	main(int argc, char **argv)
{
	t_list	list;
	t_list	tree;
	FILE	*fp;
	key_t	key;
	int		size;

	errno = 0;
	if (argc == 2)
	{
		setlocale(LC_CTYPE, "");
		if (ft_strnstr(argv[1], ".txt", ft_strlen(argv[1])) == NULL)
			terminate(ENC_FILE);
		fp = fopen(argv[1], "r");
		if (fp == NULL)
			terminate(ENC_FOPEN);
		list = create_character_list(fp);
		tree = make_huffman_tree(&list);
		key = make_dictionary(&tree, &list, argv[1]);
		size = make_compressed_file(key, argv[1], fp);
		decoder_run(argv[1], size);
	}
	else
		terminate(ENC_ARG);
	return (0);
}
