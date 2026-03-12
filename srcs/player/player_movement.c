/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:18:05 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:18:06 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_game *game)
{
	t_move	move;

	init_move(&move, game, game->ply->dir_x, game->ply->dir_y);
	check_horizontal(&move, game, game->ply->dir_x);
	check_vertical(&move, game, game->ply->dir_y);
}

void	move_backwards(t_game *game)
{
	t_move	move;

	init_move(&move, game, -game->ply->dir_x, -game->ply->dir_y);
	check_horizontal(&move, game, -game->ply->dir_x);
	check_vertical(&move, game, -game->ply->dir_y);
}

void	move_left(t_game *game)
{
	t_move	move;

	init_move(&move, game, game->ply->dir_y, -game->ply->dir_x);
	check_horizontal(&move, game, game->ply->dir_y);
	check_vertical(&move, game, -game->ply->dir_x);
}

void	move_right(t_game *game)
{
	t_move	move;

	init_move(&move, game, -game->ply->dir_y, game->ply->dir_x);
	check_horizontal(&move, game, -game->ply->dir_y);
	check_vertical(&move, game, game->ply->dir_x);
}
