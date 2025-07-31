#include "cub3d.h"

void	rotate_dvector(t_dvector *vec, double rot)
{
	double	old_x;

	old_x = (*vec)[X];
	(*vec)[X] = (*vec)[X] * cos(rot) - (*vec)[Y] * sin(rot);
	(*vec)[Y] = old_x * sin(rot) + (*vec)[Y] * cos(rot);
}

void	set_dvector(t_dvector *vec, double x, double y)
{
	(*vec)[X] = x;
	(*vec)[Y] = y;
}

void	set_ivector(t_ivector *vec, int x, int y)
{
	(*vec)[X] = x;
	(*vec)[Y] = y;
}
