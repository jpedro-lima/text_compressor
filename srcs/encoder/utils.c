/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:20:51 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/14 16:57:58 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "encoder.h"

/**
 * @brief Função para verificar os erros do errno,
 * imprimir na tela o erro encontrado e encerrar o programa
 * 
 * @param str 
 */
void	terminate(char	*str)
{
	if (errno < 0)
		perror(str);
	else
		ft_putendl_fd(str, 2);
	exit(1);
}

/**
 * @brief Função para criar um novo "galho" da árvore de Huffman
 * 
 * @param left 
 * @param right 
 * @return t_tree* 
 */
t_tree	*new_node_tree(t_tree *left, t_tree *right)
{
	t_tree	*new;

	new = (t_tree *)malloc(sizeof(t_tree));
	if (!new)
		return (NULL);
	new->c = 0;
	new->freq = right->freq + left->freq;
	new->next = NULL;
	new->right = right;
	new->left = left;
	return (new);
}

/**
 * @brief Função para criar um novo nó no final da lista encadeada
 * 
 * @param c 
 * @param list 
 * @return int 
 */
int	new_node_list(wchar_t c, t_list *list)
{
	t_tree	*new;
	t_tree	*aux;

	aux = list->begin;
	new = (t_tree *)malloc(sizeof(t_tree));
	if (!new)
		return (FALSE);
	new->freq = 1;
	new->c = c;
	new->next = NULL;
	new->right = NULL;
	new->left = NULL;
	if (aux)
	{
		while (aux->next != NULL)
			aux = aux->next;
		aux->next = new;
	}
	else
		list->begin = new;
	list->size++;
	return (TRUE);
}

/**
 * @brief Função recursiva que libera a memória da árvore de Huffman
 * 
 * @param root 
 */
void	clear_tree(t_tree *root)
{
	if (root->left != NULL || root->right != NULL)
	{
		clear_tree(root->left);
		clear_tree(root->right);
	}
	free(root);
	root = NULL;
}

/**
 * @brief Função para liberar a memória da lista encadeada simples
 * 
 * @param list 
 */
void	clear_list(t_list *list)
{
	t_tree	*aux;
	t_tree	*temp;

	aux = list->begin;
	while (aux)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
	}
}
