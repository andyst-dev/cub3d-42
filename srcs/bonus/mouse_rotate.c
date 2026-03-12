/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:17:15 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:17:15 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_move(int x, int y, void *param)
{
	t_game	*game;
	int		deltax;
	double	angle;

	(void)y;
	game = (t_game *)param;
	deltax = x - game->mid_x;
	if (deltax != 0)
	{
		angle = deltax * game->ply->sensitivity;
		rotate_player(game, angle);
		mlx_mouse_move(game->p_mlx_window, game->mid_x, game->mid_y);
	}
	return (0);
}
