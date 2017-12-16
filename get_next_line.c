/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: xamartin <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:56:12 by xamartin     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/16 16:53:11 by xamartin    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char	*next(const int fd, char *str, int *ret)
{
	char	tmp[BUFF_SIZE + 1];
	char	*tmp3;

	*ret = read(fd, tmp, BUFF_SIZE);
	tmp[*ret] = '\0';
	tmp3 = str;
	str = ft_strjoin(str, tmp);
	ft_strdel(&tmp3);
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char		*str = "";
	int				ret;
	char			*buf;

	ret = 1;
	if (!line || fd < 0 || (str[0] == '\0' && (!(str = ft_strnew(0)))))
		return (-1);
	while (ret > 0)
	{
		if ((buf = ft_strchr(str, '\n')) != NULL)
		{
			*buf = '\0';
			*line = ft_strdup(str);
			ft_memmove(str, buf + 1, ft_strlen(buf + 1) + 1);
			return (1);
		}
		str = next(fd, str, &ret);
	}
	if (ret == 0 && ft_strlen(str))
	{
		*line = ft_strdup(str);
		ret = *line ? 1 : -1;
		ft_bzero(str, ft_strlen(str));
	}
	return (ret);
}
