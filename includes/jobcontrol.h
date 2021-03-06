/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobcontrol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frossiny <frossiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 14:08:11 by lubenard          #+#    #+#             */
/*   Updated: 2020/01/23 15:45:46 by frossiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOBCONTROL_H
# define JOBCONTROL_H

# include "structs.h"

enum	e_job_state
{
	JOB_COMPLETED,
	JOB_SUSPENDED,
	JOB_RUNNING,
	JOB_CONTINUED
};

static const char	*g_jobs_status[] =
{
	"Done",
	"Stopped",
	"Running",
	"Running"
};

/*
** If needed, you can remove shell var from proto and use global instead
*/

t_jobs_lst	*job_new(t_cmd *cmd, int pid);
t_jobs_lst	*job_new_pipe(t_pipel *pline);
void		job_free(t_jobs_lst *job);
void		job_delete(t_shell *shell, int pid);
void		jobs_destroy_all(t_shell *shell, int kill);
void		job_check_status(void);
t_jobs_lst	*job_search(t_shell *shell, int job_number);
t_jobs_lst	*job_search_pid(t_shell *shell, int pid);
char		*job_get_command(t_cmd *cmd);
char		*job_get_pipe_command(t_pipel *pline);
int			job_can_exit(void);
void		job_catch_sigchld(int signal);
void		job_catch_sigtstp(int signal);

/*
** Useful jobcontrol functions
*/

int			job_is_stopped(t_jobs_lst *jobs);
int			job_is_completed(t_jobs_lst *jobs);

#endif
