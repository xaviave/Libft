/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_gnl.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 18:20:25 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/14 13:23:41 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sending(char **save, char *endl, char **line)
{
	char *tmp;

	if (!(*line = ft_strsub(*save, 0, endl - *save)))
		return (-1);
	tmp = *save;
	if (!(*save = ft_strdup(endl + 1)))
		return (-1);
	free(tmp);
	return (1);
}

static int		ft_reading(char **line, t_fd *current, t_var *mem)
{
	while ((mem->r_state = read(current->fd, mem->buffer, BUFF_SIZE)) > 0)
	{
		mem->buffer[mem->r_state] = '\0';
		mem->tmp = current->save;
		if (!(current->save = ft_strjoin(current->save, mem->buffer)))
			return (-1);
		free(mem->tmp);
		if (ft_strchr(current->save, '\n'))
			return (1);
		*line = current->save;
		mem->i = 1;
	}
	return (0);
}

static int		ft_readloop(char **line, t_fd *current)
{
	t_var	mem;
	int		ret;

	mem.i = 0;
	if (current->fd < 0 || !line)
		return (-1);
	if ((mem.endl = ft_strchr(current->save, '\n')))
		return (ft_sending(&current->save, mem.endl, line));
	if ((ret = ft_reading(line, current, &mem)) == -1)
		return (-1);
	if (ret == 1)
		return (ft_readloop(line, current));
	if (mem.r_state == -1)
		return (-1);
	if (mem.r_state == 0 && ft_strlen(current->save) > 0 && mem.endl == NULL)
	{
		ft_sending(&current->save, ft_strchr(current->save, '\0'), line);
		current->eof = 1;
		return (1);
	}
	return (mem.i ? 1 : 0);
}

static t_fd	*ft_fdinit(int fd)
{
	t_fd *current;

	current = (t_fd *)malloc(sizeof(t_fd));
	current->save = ft_memalloc(1);
	current->fd = fd;
	current->next = NULL;
	current->eof = 0;
	return (current);
}

int		ft_gnl(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*current;

	if ((!list))
		list = ft_fdinit(fd);
	current = list;
	while (current->next != NULL && current->fd != fd)
		current = current->next;
	if (current->fd == fd)
	{
		if (current->eof == 1)
			return (0);
		return (ft_readloop(line, current));
	}
	else
	{
		current->next = ft_fdinit(fd);
		current = current->next;
	}
	if (current->eof == 1)
		return (0);
	return (ft_readloop(line, current));
}
