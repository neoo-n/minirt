/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvauthey <dvauthey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:26:30 by akabbaj           #+#    #+#             */
/*   Updated: 2025/06/11 14:18:51 by dvauthey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "parsing/parsing.h"
# include "camera/camera.h"
# include "vector/vector.h"
# include "intersections/intersections.h"
# include "utils/utils.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <math.h>
# include <stdio.h>

t_rgb	specular(t_vars *vars, t_coords vision, t_shape *shape);

#endif