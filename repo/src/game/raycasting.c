#include "cub3d.h"

int32_t	get_wall_color(char pos, t_direction wall_dir, int side)
{
	// int32_t alpha = side == 1 ? 128 : 255;
	(void)side;
	if (pos == '1')
	{
		if (wall_dir == N)
			return (get_rgba(255, 0, 0, 255));
		if (wall_dir == S)
			return (get_rgba(0, 255, 0, 255));
		if (wall_dir == W)
			return (get_rgba(0, 0, 255, 255));
		if (wall_dir == E)
			return (get_rgba(128, 128, 128, 255));
	}
	return (get_rgba(0, 0, 0, 255));
}


void raycasting(t_game *game)
{
	t_player	*player = game->p;
	double posX = player->pos[X], posY = player->pos[Y]; // x and y start position;
	double dirX = player->curr_dir[X], dirY = player->curr_dir[Y];	   // initial direction vector;
	double planeX = player->plane[X], planeY = player->plane[Y];

	int x = 0;

	ft_memset(game->image->pixels, 255, game->image->width * game->image->height * sizeof(int32_t));
	while (x < SCREEN_W)
	{
		// Calcular la posicion y direccion del rayo
		double cameraX = 2 * x / (double)SCREEN_W - 1; // x-coordinate in camera space
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		// En que casilla del mapa estamos
		int mapX = (int)posX;
		int mapY = (int)posY;

		// Tamaño del rayo desde la posicion actual hasta el siguiente lado x o y
		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		// En que direccion  x o y avanzamos (+1 o -1)
		int stepX;
		int stepY;

		int hit = 0; // Chocamos un muro?
		int side;	 // Fue un lateral o en la direccion Y (+1 o -1)

		// Calcular stepX/Y y sideDistx/Y inicial
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1 - posY) * deltaDistY;
		}

		// DDA
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (mapX < 0 || mapX >= game->map_cols || mapY < 0 || mapY >= game->map_rows)
				break;
			if (game->map[mapY][mapX] == '1')
				hit = 1;
		}

		// Sdes qye direccion choca el rayo
		t_direction	wall_dir;
		if (side == 0)
		{
			if (rayDirX > 0)
				wall_dir = E;
			else
				wall_dir = W;
		}
		else
		{
			if (rayDirY > 0)
				wall_dir = S;
			else
				wall_dir = N;
		}

		// Calcular la distanci proyectada a la direccion de la camara (La distancia Euclidea causaria efecto ojo de pescado);
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		// Tamaño de la linea que tenemos que dibujar en pantalla
		int lineHeight = (int)(SCREEN_H / (perpWallDist));

		int drawStart = -lineHeight / 2 + SCREEN_H / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if (drawEnd >= SCREEN_H)
			drawEnd = SCREEN_H - 1;

		int32_t color = get_wall_color(game->map[mapY][mapX], wall_dir, side);

		// else if (game->map[mapY][mapX] == 2)
		// 	color = get_wall_color(game->map[mapY][mapX], wall_dir, side);
		// else if (game->map[mapY][mapX] == 3)
		// 	color = get_wall_color(game->map[mapY][mapX], wall_dir, side);
		// else if (game->map[mapY][mapX] == 4)
		// 	color = get_wall_color(game->map[mapY][mapX], wall_dir, side);
		// else if (game->map[mapY][mapX] == 5)
		// 	color = get_wall_color(game->map[mapY][mapX], wall_dir, side);
		// else
		// 	color = get_rgba(0, 0, 0, 255);
		draw_ver_line(game, x, drawStart, drawEnd, color);
		x++;
	}
}
