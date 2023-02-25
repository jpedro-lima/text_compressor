/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dat_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:22:25 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:39:47 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "decoder.h"

/**
 * @brief Função que lê o byte do arquivo e interpreta
 * bit à bit criando uma fita binária em uma string
 * 
 * @param fp 
 * @param size 
 * @return char* 
 */
static char	*binary_tape(FILE *fp, int size)
{
	char	byte;
	char	*bin;
	int		pos;
	int		i;

	i = -1;
	bin = (char *)calloc((size * 8), sizeof(char));
	while (fread(&byte, sizeof(char), 1, fp))
	{
		pos = 8;
		while (--pos > 0)
		{
			if (byte & (1 << pos))
				bin[++i] = '1';
			else
				bin[++i] = '0';
		}
	}
	return (bin);
}

/**
 * @brief Está função irá receber a string da fita binária,
 * acessar a memória compartilhada com a tabela de tradução
 * e devolver uma string com o texto traduzido
 * 
 * @param shmid 
 * @param text 
 * @return wchar_t* 
 */
static wchar_t	*unzip_dat_file(int shmid, char *binary)
{
	int		i;
	char	bin[BUFFER];
	wchar_t	*msg;
	wchar_t	*temp;
	t_dict	*node;

	i = -1;
	ft_memset(bin, '\0', BUFFER);
	msg = wcsdup((wchar_t *)"");
	wmemset(msg, 0, 1);
	while (*binary != '\0')
	{
		bin[++i] = *binary;
		node = (t_dict *)shmat(shmid, (void *)0, 0);
		while (node->c && ft_strncmp(node->bin, bin, BUFFER) != 0)
			node = node + 1;
		if (node->c)
		{
			temp = msg;
			msg = concatc(msg, node->c);
			free(temp);
			ft_memset(bin, '\0', BUFFER);
			i = -1;
		}
		binary++;
	}
	return (msg);
}

/**
 * @brief Está função irá receber a string da fita binária
 * traduzi-la para os caracteres originais e devolver os
 * dados recolhidos da descompressão
 * 
 * @param fp 
 * @param shmid 
 * @return t_data 
 */
t_data	read_dat_file(FILE *fp, int shmid)
{
	t_data	data;
	char	*binary;
	int		size;
	clock_t	begin;
	clock_t	end;

	begin = clock();
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, sizeof(key_t), SEEK_SET);
	binary = binary_tape(fp, size - sizeof(key_t));
	data.msg = unzip_dat_file(shmid, binary);
	if (!(*data.msg))
		terminate(DEC_UNEXPECTED);
	end = clock();
	data.time = (double)(end - begin) / CLOCKS_PER_SEC;
	data.ziped = size;
	data.unziped = wcslen(data.msg);
	free(binary);
	fclose(fp);
	return (data);
}
