/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haekang <haekang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2023/11/21 14:39:53 by jho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int	main(int argc, char *argv[], char *envp[])
{
	(void) argc;
	(void) argv;

	t_env *env = msh_env_new_list(envp);
	//char *infile = "infile";
	char *ls = "ls";
	char *l = "-l";
	char *cat = "cat";
	char *e = "-e";
	char *cat_2 = "cat";
	char *e_2 = "-e";
	//char *outfile = "outfile";
	
	t_pipeline *pipeline0 = malloc(sizeof(t_pipeline));
	t_pipeline *pipeline1 = malloc(sizeof(t_pipeline));
	t_pipeline *pipeline2 = malloc(sizeof(t_pipeline));

	//t_token *token_infile = msh_token_malloc_symval(REDIR, infile);
	t_token *token_ls = msh_token_malloc_symval(WORD, ls);
	t_token *token_l = msh_token_malloc_symval(WORD, l);
	t_token *token_cat = msh_token_malloc_symval(WORD, cat);
	t_token *token_e = msh_token_malloc_symval(WORD, e);
	t_token *token_cat_2 = msh_token_malloc_symval(WORD, cat_2);
	t_token *token_e_2 = msh_token_malloc_symval(WORD, e_2);
	//t_token *token_outfile = msh_token_malloc_symval(REDIR, outfile);

	//msh_pipeline_add_token(pipeline0, token_infile);
	msh_pipeline_add_token(pipeline0, token_ls);
	msh_pipeline_add_token(pipeline0, token_l);
	msh_pipeline_add_token(pipeline1, token_cat);
	msh_pipeline_add_token(pipeline1, token_e);
	msh_pipeline_add_token(pipeline2, token_cat_2);
	msh_pipeline_add_token(pipeline2, token_e_2);
	//msh_pipeline_add_token(pipeline1, token_outfile);

	pipeline0->next = pipeline1;
	pipeline1->next = pipeline2;
	pipeline2->next = NULL;

	msh_execute(pipeline0, env);
	return (0);
}
