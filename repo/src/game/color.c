#include "cub3d.h"

int32_t	get_rgba(int32_t r, int32_t g, int32_t b, int32_t a)
{
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || a < 0 || a > 255)
		return (0);
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	get_r(int32_t rgba)
{
	return ((rgba >> 24) & 0xFF);
}

int32_t	get_g(int32_t rgba)
{
	return ((rgba >> 16) & 0xFF);
}

int32_t	get_b(int32_t rgba)
{
	return ((rgba >> 8) & 0xFF);
}

int32_t	get_a(int32_t rgba)
{
	return (rgba & 0xFF);
}
