/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:04:53 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/14 17:45:59 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <encoder.h>
#include <string.h>

/**
 * @brief Função para preencher a tabela de tradução com o
 * binário relativo da árvore
 * 
 * @param aux 
 * @param path 
 * @param shmid 
 */
static void	shared_bin_path(t_tree *aux, char *path, int shmid)
{
	t_dict	*node;
	char	left[BUFFER];
	char	right[BUFFER];

	node = (t_dict *)shmat(shmid, (void *)0, 0);
	if (aux->left == NULL && aux->right == NULL)
	{
		if (*path)
		{
			while (node->c && node->c != aux->c)
				node = node + 1;
			ft_memcpy(node->bin, path, BUFFER);
		}
		else
			ft_memcpy(node->bin, "0", 1);
	}
	else
	{
		strcat(ft_memcpy(left, path, BUFFER), "0");
		strcat(ft_memcpy(right, path, BUFFER), "1");
		shared_bin_path(aux->left, left, shmid);
		shared_bin_path(aux->right, right, shmid);
	}
}

/**
 * @brief Função para preencher a tabela com os caracteres,
 * finalizando o último nó com um caractere nulo
 * 
 * @param list 
 * @param shmid 
 */
static void	shared_character(t_list *list, int shmid)
{
	t_dict	*node;
	t_tree	*aux;

	aux = list->begin;
	node = (t_dict *)shmat(shmid, (void *)0, 0);
	while (aux)
	{
		node->c = aux->c;
		aux = aux->next;
		node = node + 1;
	}
	node->c = 0;
}

/**
 * @brief Esta função cria uma repartição de memória compartilhada
 * e a preenche com uma tabela de tradução
 * 
 * @param tree 
 * @param list 
 * @param path 
 * @return key_t 
 */
key_t	make_dictionary(t_list *tree, t_list *list, char *path)
{
	int		shmid;
	key_t	key;

	key = ftok(path, 'x');
	if (!key)
		terminate(ENC_SHM_KEY);
	shmid = shmget(key, sizeof(t_dict) * list->size + 1,
			IPC_CREAT | IPC_EXCL | SHM_R | SHM_W);
	if (shmid == -1)
		terminate(ENC_SHM_NEW);
	shared_character(list, shmid);
	shared_bin_path(tree->begin, "0", shmid);
	clear_tree(tree->begin);
	clear_list(list);
	return (key);
}
