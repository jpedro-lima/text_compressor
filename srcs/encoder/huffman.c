/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:09:34 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/14 17:43:48 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/**
 * @brief Esta função lê a lista de caracteres e devolve
 * o ponteiro do node com a menor frequência
 * 
 * @param list 
 * @return t_tree* 
 */
static t_tree	*lowest_frequency(const t_list *list)
{
	t_tree	*aux;
	int		low_freq;

	low_freq = FT_INT_MAX;
	aux = list->begin;
	while (aux)
	{
		if (aux->freq < low_freq)
			low_freq = aux->freq;
		aux = aux->next;
	}
	aux = list->begin;
	while (aux->freq > low_freq)
		aux = aux->next;
	return (aux);
}

/**
 * @brief Esta função remove o node com a menor
 * frequência da lista e retorna seu ponteiro
 * 
 * @param list 
 * @return t_tree* 
 */
static t_tree	*least_frequent_node(t_list *list)
{
	t_tree	*prev;
	t_tree	*node;

	node = lowest_frequency(list);
	if (node == list->begin)
		list->begin = node->next;
	else
	{
		prev = list->begin;
		while (prev && prev->next != node)
			prev = prev->next;
		prev->next = node->next;
	}
	node->next = NULL;
	return (node);
}

static t_list	clone_list(t_list *list)
{
	t_list	clone;
	t_tree	*aux;
	t_tree	*c_aux;

	clone.begin = NULL;
	clone.size = 0;
	aux = list->begin;
	while (aux != NULL)
	{
		if (!new_node_list(aux->c, &clone))
			terminate(ENC_ALO_NODE);
		c_aux = clone.begin;
		while (c_aux->next != NULL)
			c_aux = c_aux->next;
		c_aux->freq = aux->freq;
		aux = aux->next;
	}
	return (clone);
}

/**
 * @brief Monta a árvore de huffman usando uma lista clonada
 * 
 * @param list 
 * @return t_list 
 */
t_list	make_huffman_tree(t_list *list)
{
	t_list	tree;
	t_tree	*right;
	t_tree	*left;
	t_tree	*new;
	t_tree	*aux;

	tree = clone_list(list);
	while (tree.size > 1)
	{
		left = least_frequent_node(&tree);
		right = least_frequent_node(&tree);
		new = new_node_tree(left, right);
		if (!new)
			terminate(ENC_ALO_TREE);
		if (tree.begin != NULL)
		{
			aux = tree.begin;
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = new;
		}
		else
			tree.begin = new;
		tree.size--;
	}	
	return (tree);
}

/**
 * @brief Cria uma lista com os caracteres e sua frequência
 * 
 * @param fp 
 * @return t_list 
 */
t_list	create_character_list(FILE *fp)
{
	t_list	list;
	wchar_t	character;
	t_tree	*aux;

	list.begin = NULL;
	list.size = 0;
	while ((character = fgetwc(fp)) != EOF)
	{
		aux = list.begin;
		while (aux && aux->c != character)
			aux = aux->next;
		if (!aux)
		{
			if (!new_node_list(character, &list))
				terminate(ENC_ALO_NODE);
		}
		else
			aux->freq++;
	}
	if (list.begin == NULL)
		terminate(ENC_EMPTY_FILE);
	return (list);
}
