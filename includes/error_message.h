/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapedr2 < joapedr2@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:31:52 by joapedr2          #+#    #+#             */
/*   Updated: 2023/01/15 13:29:53 by joapedr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MESSAGE_H
# define ERROR_MESSAGE_H

# define ENC_MALLOC		"encoder: Erro ao alocar memória"
# define ENC_ALO_NODE	"encoder: Erro ao alocar memória para a lista"
# define ENC_ALO_TREE	"encoder: Erro ao alocar memória para a árvore"
# define ENC_SHM		"encoder: Erro ao alocar memória compartilhada"
# define ENC_SHM_KEY	"encoder: Erro ao definir um key"
# define ENC_SHM_NEW	"encoder: Um arquivo com esse nome já foi comprimido"
# define ENC_SHM_CLOSE	"encoder: Erro ao finalizar uma memória compartilhada"
# define ENC_ARG		"encoder: Erro de argumento"
# define ENC_FILE		"encoder: Não é um arquivo .txt"
# define ENC_FOPEN		"encoder: Arquivo não encontrado"
# define ENC_FOPEN_NEW	"encoder: Erro ao tentar criar novo arquivo"
# define ENC_EMPTY_FILE	"encoder: O arquivo .txt está vazio"
# define ENC_UNEXPECTED	"encoder: Erro inesperado"

# define DEC_MALLOC		"decoder: Erro ao alocar memória"
# define DEC_SHM_ACC	"decoder: Erro ao acessar memória compartilhada"
# define DEC_SHM_CLOSE	"decoder: Erro ao finalizar uma memória compartilhada"
# define DEC_FOPEN		"decoder: Arquivo não encontrado"
# define DEC_FILE		"decoder: Não é um arquivo .dat"
# define DEC_ARG		"decoder: Erro de argumento"
# define DEC_UNEXPECTED	"decoder: Erro inesperado"

#endif //ERROR_MESSAGE_H
