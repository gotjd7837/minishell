/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeseong <haeseong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:03:25 by jho               #+#    #+#             */
/*   Updated: 2024/06/13 18:52:01 by haeseong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/msh.h"

int		g_exit_status = 0;

t_pipeline	*msh_return_pipeline(char *input, t_env *env)
{
	t_pipeline	*pipelines;
	char		*expanded;

	// 환경 변수 확장
	expanded = msh_expand(input, env);
	if (expanded != NULL && *expanded == '\0')
	{
		if (input != NULL)
			free(input);
		return (NULL);
	}
	// 확장된 입력을 렉싱하여 파이프라인 구조 생성
	pipelines = msh_lex(expanded);
	if (pipelines == NULL)
	{
		write(2, "lex err\n", 8);
		g_exit_status = 258;
	}
	free(expanded);
	free(input);
	return (pipelines);
}

int	msh_check_input(char *s)
{
	if (*s == '\0')
	{
		free(s);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[], char *envp[])
{
	char		*input;
	t_env		*env;
	t_pipeline	*pipelines;

	(void) argc;
	(void) argv;
	// 환경변수 리스트 초기화
	env = msh_env_new_list(envp);
	while (1)
	{
		// 쉘 시그널 핸들러 설정
		msh_set_signal();
		input = readline("msh$> ");
		if (input == NULL)
			msh_handler_ctrl_d(0);
		if (!msh_check_input(input))
			continue ;
		add_history(input);
		// 입력 파싱하고 확장 및 렉싱을 수행해 파이프라인 리스트로 반환
		pipelines = msh_return_pipeline(input, env);
		if (pipelines == NULL)
			continue ;
		else
			msh_execute(pipelines, env);
		msh_pipeline_free_list(pipelines);
	}
	return (0);
}
