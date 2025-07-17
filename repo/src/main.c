/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtivan-r <jtivan-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:59:02 by erde-la-          #+#    #+#             */
/*   Updated: 2025/07/17 22:51:00 by jtivan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define SCREEN_W 640
#define SCREEN_H 480
#define TEX_W 64
#define TEX_H 64
#define MAP_W 24
#define MAP_H 24

int32_t get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int worldMap[MAP_H][MAP_W]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

// -----------------------------------------------------------------------------

void	draw_ver_line(mlx_image_t *img, int x, int start, int end, int32_t color)
{
	int	temp;

	if (!img)
		return ;
	if (start < 0 || start > SCREEN_H)
		return ;
	if (end < 0 || end > SCREEN_H)
		return ;
	if (start > end)
	{
		temp = end;
		end = start;
		start = temp;
	}
	while (start < end)
	{
		mlx_put_pixel(img, x, start, color);
		start++;
	}
}

void	raycasting(mlx_t *mlx, mlx_image_t *image)
{
	double posX = 22, posY = 12; // x and y start position;
	double dirX = -1, dirY = 0; // initial direction vector;
	double planeX = 0, planeY = 0.66;

	double time = 0; // time of current frame
	double oldTime = 0; // time of previous frame

	int x = 0;

	ft_memset(image->pixels, 255, image->width * image->height * sizeof(int32_t));
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
		int side; // Fue un lateral o en la direccion Y (+1 o -1)

		// Calcular stepX/Y y sideDistx/Y inicial
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		} else
		{
			stepX = 1;
			sideDistX = (mapX + 1 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		} else
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
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		// Calcular la distanci proyectada a la direccion de la camara (La distancia Euclidea causaria efecto ojo de pescado);
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		// Tamaño de la linea que tenemos que dibujar en pantalla
		int lineHeight = (int)(SCREEN_H / (perpWallDist)) * 2;

		int drawStart = -lineHeight / 2 + SCREEN_H /2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + SCREEN_H / 2;
		if (drawEnd >= SCREEN_H) drawEnd = SCREEN_H - 1;

		int32_t color;
		int32_t alpha = side == 1 ? 128 : 255;
		if (worldMap[mapX][mapY] == 1)
			color = get_rgba(255, 0, 0, alpha);
		else if (worldMap[mapX][mapY] == 2)
			color = get_rgba(0, 255, 0, alpha);
		else if (worldMap[mapX][mapY] == 3)
			color = get_rgba(0, 0, 255, alpha);
		else if (worldMap[mapX][mapY] == 4)
			color = get_rgba(255, 131, 255, alpha);
		else
			color = get_rgba(0,0,0, 255);
		draw_ver_line(image, x, drawStart, drawEnd, color);
		x++;
	}
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	((void)time, (void)oldTime);
}

int32_t	main(int argc, char *args[])
{
	((void)argc, (void)args);

	mlx_t		*mlx;
	mlx_image_t	*image;

	// Gotta error check this stuff
	mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", false);
	if (!mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, SCREEN_W, SCREEN_H)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}

	raycasting(mlx, image);
	mlx_terminate(mlx);

	return (EXIT_SUCCESS);
}
