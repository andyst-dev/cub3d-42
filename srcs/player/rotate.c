/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:18:10 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:18:10 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	rotate_right(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(game->ply->rotate_speed)
		- game->ply->dir_y * sin(game->ply->rotate_speed);
	game->ply->dir_y = old_dir_x * sin(game->ply->rotate_speed)
		+ game->ply->dir_y * cos(game->ply->rotate_speed);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(game->ply->rotate_speed)
		- game->ply->plane_y * sin(game->ply->rotate_speed);
	game->ply->plane_y = old_plane_x * sin(game->ply->rotate_speed)
		+ game->ply->plane_y * cos(game->ply->rotate_speed);
}

void	rotate_left(t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(-game->ply->rotate_speed)
		- game->ply->dir_y * sin(-game->ply->rotate_speed);
	game->ply->dir_y = old_dir_x * sin(-game->ply->rotate_speed)
		+ game->ply->dir_y * cos(-game->ply->rotate_speed);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(-game->ply->rotate_speed)
		- game->ply->plane_y * sin(-game->ply->rotate_speed);
	game->ply->plane_y = old_plane_x * sin(-game->ply->rotate_speed)
		+ game->ply->plane_y * cos(-game->ply->rotate_speed);
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ply->dir_x;
	game->ply->dir_x = game->ply->dir_x * cos(angle)
		- game->ply->dir_y * sin(angle);
	game->ply->dir_y = old_dir_x * sin(angle) + game->ply->dir_y * cos(angle);
	old_plane_x = game->ply->plane_x;
	game->ply->plane_x = game->ply->plane_x * cos(angle)
		- game->ply->plane_y * sin(angle);
	game->ply->plane_y = old_plane_x * sin(angle)
		+ game->ply->plane_y * cos(angle);
}
