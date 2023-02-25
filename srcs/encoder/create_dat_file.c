/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dat_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:54:21 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:45:08 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/**
 * @brief Esta função irá receber uma string com a fita binária
 * e preencher o arquivo .dat byte à byte 
 * 
 * @param binary 
 * @param fp 
 */
static void	send_binary_to_file(char *binary, FILE *fp)
{
	char	*byte;
	int		pos;

	while (*binary != '\0')
	{
		pos = 8;
		byte = 0;
		while (*binary && --pos > 0)
		{
			if (*binary == '1')
				byte += (1 << pos);
			binary++;
		}
		fwrite(&byte, sizeof(char), 1, fp);
	}
}

/**
 * @brief Está função irá criar uma string com a fita binária
 * do texto recebido
 * 
 * @param key 
 * @param text 
 * @return char* 
 */
static char	*create_binary(key_t key, wchar_t *text)
{
	char	*bin;
	char	*temp;
	int		shmid;
	t_dict	*node;
	int		i;

	i = -1;
	shmid = shmget(key, 0, 0);
	bin = ft_strdup("");
	while (text[++i] != '\0')
	{
		node = (t_dict *)shmat(shmid, (void *)0, 0);
		while (node->c != text[i])
			node = node + 1;
		temp = bin;
		bin = ft_strjoin(bin, node->bin);
		if (!bin)
			terminate(ENC_MALLOC);
		free(temp);
	}
	return (bin);
}

/**
 * @brief Está função cria um arquivo .dat que receberá
 * uma string da fita binária
 * 
 * @param path 
 * @return FILE* 
 */
static FILE	*open_compressed_file(char *path)
{
	char	*file;
	FILE	*new;

	file = ft_strdup(path);
	if (!file)
		terminate(ENC_MALLOC);
	ft_memmove(ft_memchr(file, '.', ft_strlen(file)), ".dat", 4);
	new = fopen(file, "wb+");
	if (!new)
		terminate(ENC_FOPEN_NEW);
	free(file);
	return (new);
}

/**
 * @brief Está função irá criar o arquivo .dat e uma 
 * fita binária para preencher o arquivo .dat
 * 
 * @param key 
 * @param path 
 * @param fp 
 * @return int
 */
int	make_compressed_file(key_t key, char *path, FILE *fp)
{
	wchar_t	*text;
	wchar_t	character;
	char	*binary;
	FILE	*new;
	int		size;
	int		i;

	i = -1;
	size = ftell(fp);
	text = (wchar_t *)malloc((size + 2) * sizeof(wchar_t));
	fseek(fp, 0, SEEK_SET);
	while ((character = fgetwc(fp)) != EOF)
		text[++i] = character;
	text[++i] = '\0';
	new = open_compressed_file(path);
	binary = create_binary(key, text);
	if (!(*binary))
		terminate(ENC_UNEXPECTED);
	fwrite(&key, sizeof(key_t), 1, new);
	send_binary_to_file(binary, new);
	free(text);
	free(binary);
	fclose(fp);
	fclose(new);
	return (size);
}
