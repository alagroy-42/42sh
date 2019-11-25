/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lubenard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 10:48:31 by lubenard          #+#    #+#             */
/*   Updated: 2019/11/25 18:28:46 by lubenard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
# include <stdio.h>

void		init_jobs_struct(void)
{
	t_jobs	*jobs;

	if (!(jobs = malloc(sizeof(t_jobs))))
		return ;
	jobs->is_jobs = 0;
	jobs->index = 1;
	jobs->lst = NULL;
	g_shell.jobs = jobs;
}

void		jobs_insert(t_jobs_lst *job)
{
	t_jobs_lst	*curr;

	curr = g_shell.jobs->lst;
	if (!curr)
		g_shell.jobs->lst = job;
	else
	{
		while (curr->next)
			curr = curr->next;
		job->prev = curr;
		job->next = NULL;
		curr->next = job;
	}
	if (g_shell.jobs->index > 3)
		g_shell.jobs->last_job->prev->current = ' ';
	if (g_shell.jobs->index > 2)
	{
		g_shell.jobs->minus = g_shell.jobs->last_job;
		g_shell.jobs->last_job->current = '-';
	}
	g_shell.jobs->last_job = job;
	g_shell.jobs->plus = job;
}

t_jobs_lst	*job_new(void)

{
	t_jobs_lst *new_elem;

	if (!g_shell.jobs)
		init_jobs_struct();
	if (!(new_elem = malloc(sizeof(t_jobs_lst))))
		return (NULL);
	new_elem->command = NULL;
	new_elem->job_number = g_shell.jobs->index++;
	new_elem->pid = 0;
	new_elem->current = '+';
	new_elem->state = NULL;
	new_elem->prev = NULL;
	new_elem->next = NULL;
	jobs_insert(new_elem);
	return (new_elem);
}
