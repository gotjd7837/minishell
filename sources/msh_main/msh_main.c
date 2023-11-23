/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/23 16:38:51 by haekang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_env *env = msh_env_new_list(envp);
	char *infile = "infile";
	char *ls = "ls";
	char *cat = "cat";
	char *outfile = "outfile";
	
	t_pipeline *pipeline0 = malloc(sizeof(t_pipeline));
	t_pipeline *pipeline1 = malloc(sizeof(t_pipeline));

	t_token *token_infile = msh_token_malloc_symval(REDIR, infile);
	t_token *token_ls = msh_token_malloc_symval(WORD, ls);
	t_token *token_cat = msh_token_malloc_symval(WORD, cat);
	t_token *token_outfile = msh_token_malloc_symval(REDIR, outfile);

	msh_pipeline_add_token(pipeline0, token_infile);
	msh_pipeline_add_token(pipeline0, token_ls);
	msh_pipeline_add_token(pipeline1, token_cat);
	msh_pipeline_add_token(pipeline1, token_outfile);

	pipeline0->next = pipeline1;

	msh_execute(pipeline0, env);
	return (0);
}
