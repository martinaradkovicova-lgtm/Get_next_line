/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradkovi <mradkovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:18:17 by mradkovi          #+#    #+#             */
/*   Updated: 2026/09/05 17:18:19 by mradkovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <unistd.h> //+read +ssize_t
# include <stdlib.h> //+malloc, +free, +size_t +NULL
# include <fcntl.h> //+open
# include <limits.h> //+OPEN_MAX

char		*get_next_line(int fd);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
