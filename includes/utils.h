/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:30:35 by anloisea          #+#    #+#             */
/*   Updated: 2023/01/12 12:45:17 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(char *str);
void	ft_putstr_fd(char *str, int fd);

//CHECK ERRORS
int		check_for_errors(char *argv[]);
int		search_for_alpha(char *argv[]);
int		check_for_invalid_values(char *argv[]);

//SMALL UTILS
int		is_even(int nb);
int		is_alpha(char c);

#endif