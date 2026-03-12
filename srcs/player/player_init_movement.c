/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init_movement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astoll <astoll@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:17:59 by astoll            #+#    #+#             */
/*   Updated: 2025/01/16 09:18:00 by astoll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_move(t_move *move, t_game *game, double dir_x, double dir_y)
{
	move->next_x = game->ply->pos_x + dir_x
		* (game->ply->move_speed + COLLISION_BUFFER);
	move->next_y = game->ply->pos_y + dir_y
		* (game->ply->move_speed + COLLISION_BUFFER);
	move->map_height = ft_count_index(game->map->map);
}

void	check_horizontal(t_move *move, t_game *game, double dir_x)
{
	move->check_y = (int)floor(game->ply->pos_y);
	move->check_x = (int)floor(move->next_x);
	if (move->check_y >= 0 && move->check_y < move->map_height
		&& game->map->map[move->check_y] != NULL)
	{
		move->row_length = (int)ft_strlen(game->map->map[move->check_y]);
		if (move->check_x >= 0 && move->check_x < move->row_length
			&& game->map->map[move->check_y][move->check_x] != '1')
			game->ply->pos_x += dir_x * game->ply->move_speed;
	}
}

void	check_vertical(t_move *move, t_game *game, double dir_y)
{
	move->check_x = (int)floor(game->ply->pos_x);
	move->check_y = (int)floor(move->next_y);
	if (move->check_y >= 0 && move->check_y < move->map_height
		&& game->map->map[move->check_y] != NULL)
	{
		move->row_length = (int)ft_strlen(game->map->map[move->check_y]);
		if (move->check_x >= 0 && move->check_x < move->row_length
			&& game->map->map[move->check_y][move->check_x] != '1')
			game->ply->pos_y += dir_y * game->ply->move_speed;
	}
}
