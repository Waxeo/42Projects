/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:42:23 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/02/16 22:01:08 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pile
{
	int				index;
	int				content;
	struct s_pile	*next;
}	t_pile;

/*push_algo*/

int				get_max(t_pile *pile_a);
int				get_max_place(t_pile *pile_a, int max);
int				get_min_place(t_pile *pile_a, int index);
int				get_min(t_pile **pile);
int				ft_sort_or_nah(t_pile *pile_a);
void			verify_pileb(t_pile **pile_b);
void			sort_five(t_pile **pile_a, t_pile **pile_b, int i);
void			mini_algo(t_pile **pile_a);
void			middle_algo(t_pile **pile_a, t_pile **pile_b);
void			fat_boi(t_pile **pile_a, t_pile **pile_b);

/*push_instructions*/

void			ft_push_pile(t_pile **pile_a, t_pile **pile_b);
void			ft_pp(t_pile **pile_a, t_pile **pile_b, int toggle);
void			ft_rev_rotate_pile(t_pile **pile);
void			ft_rra(t_pile **pile_a);
void			ft_rrb(t_pile **pile_b);
void			ft_rrr(t_pile **pile_a, t_pile **pile_b);
void			ft_rotate_pile(t_pile **pile);
void			ft_ra(t_pile **pile_a);
void			ft_rb(t_pile **pile_b);
void			ft_rr(t_pile **pile_a, t_pile **pile_b);
void			ft_swap_pile(t_pile **pile);
void			ft_sa(t_pile *pile_a);
void			ft_sb(t_pile *pile_b);
void			ft_ss(t_pile *pile_a, t_pile *pile_b);

/*push_utils_libft*/

char			*ft_itoa(int n);
char			**ft_split(const char *s, char c);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
long long int	atoi_ft(const char *str);
void			ft_lstadd_back(t_pile **lst, t_pile *new);
t_pile			*ft_lstlast(t_pile *lst);
t_pile			*ft_lstnew(int nbr);
t_pile			*ft_pile_init(int argc, char **argv);
t_pile			*ft_create_pile(int argc, char **argv, int i, int ref);

/*push_utils_reste*/

int				check_chunk(t_pile **pile, int chunk_size);
int				chose_chunks(int size);
int				find_top_chunknbr(t_pile **pile, int chunk_size);
int				find_else(t_pile **pile, int chunk_size);
void			we_in_the_a(t_pile **pile_a, t_pile **pile_b);
int				ft_tablen(char **tab);
void			ft_put_index(t_pile *pile_a, int *tab, int size);
void			ft_sort_int_tab(int *tab, int size);
int				ft_lstsize(t_pile *lst);
void			ft_indexage(t_pile *pile_a);
void			killer(t_pile *pile_a, char **tab, int ref);
void			killer2(void);
void			free_arg_tab(char **tab);
void			free_lst(t_pile **pile);

/*main*/

int				ft_check_doubles(char **tab, int type);
int				ft_check_args(char **tab, int type);

#endif