/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperea-d <pperea-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 18:07:01 by pperea-d          #+#    #+#             */
/*   Updated: 2021/02/04 16:51:19 by pperea-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx.h"
# include <string.h>
# include <float.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef enum		e_error{
	DEF_ERR,
	ARGS_ERR,
	FILE_ERR,
	OPT_ERR,
	FILE_NAME_ERR,
	RES_DECLARED,
	AMB_DECLARED,
	NO_CAM_ERR,
	VALUE_RANGE_ERR,
	RGB_RANGE_ERR,
	VEC_RANGE_ERR,
	NULL_VEC_ERR,
	FOV_RANGE_ERR
}					t_error;

typedef struct		s_vars
{
	double			a;
	double			b;
	double			c;

}					t_vars;

typedef struct		s_display
{
	void			*img;
	char			*addr;
	int				x;
	int				y;
	int				bpp;
	int				length;
	int				end;
}					t_display;

typedef struct		s_color
{
	double	r;
	double	g;
	double	b;
}					t_color;

typedef struct		s_vec3
{
	double	x;
	double	y;
	double	z;
}					t_vec3;

typedef struct		s_mat3{
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
}					t_mat3;

typedef struct		s_camera
{
	t_vec3			position;
	t_vec3			orientation;
	double			fov;
	struct s_camera	*next;
}					t_camera;

typedef struct		s_resolution
{
	int				declared;
	int				width;
	int				heigth;
}					t_resolution;

typedef struct		s_ambient
{
	int				declared;
	double			intensity;
	t_color			color;
}					t_ambient;

typedef struct		s_sphere
{
	t_vec3			center;
	double			diameter;
	t_color			color;
	struct s_sphere	*next;
}					t_sphere;

typedef struct		s_plane
{
	t_vec3			point;
	t_vec3			normal;
	t_color			color;
	struct s_plane	*next;

}					t_plane;

typedef struct		s_light
{
	t_vec3			point;
	double			intensity;
	t_color			color;
	struct s_light	*next;
}					t_light;

typedef struct		s_dlight
{
	t_vec3			orientation;
	double			intensity;
	t_color			color;
	struct s_dlight	*next;
}					t_dlight;

typedef struct		s_ray
{
	t_vec3			origin;
	t_vec3			direction;
	double			t;
	t_color			color;
}					t_ray;

typedef struct		s_cyl
{
	t_vec3			point;
	t_vec3			orientation;
	double			diameter;
	double			height;
	t_color			color;
	struct s_cyl	*next;
}					t_cylinder;

typedef struct		s_square
{
	t_vec3			point;
	t_vec3			orientation;
	double			height;
	t_color			color;
	struct s_square	*next;
}					t_square;

typedef struct		s_trian
{
	t_vec3			p1;
	t_vec3			p2;
	t_vec3			p3;
	t_color			color;
	struct s_trian	*next;
}					t_triangle;

typedef struct		s_hit
{
	t_vec3			point;
	t_vec3			normal;
	double			distance;
	t_vec3			light;
	t_ray			shadow_ray;
	t_color			color;
	double			cyl_m;
	t_vec3			cyl_center;
}					t_hit;

typedef struct		s_scene
{
	int				save;
	t_resolution	res;
	t_ambient		amb;
	t_mat3			cam_rot;
	t_camera		*cams;
	t_light			*lights;
	t_dlight		*dirlights;
	t_sphere		*spheres;
	t_plane			*planes;
	t_cylinder		*cylinders;
	t_square		*squares;
	t_triangle		*triangles;
	int				num_cam;
	void			*mlx;
	void			*mlx_win;
	t_display		img;
	t_display		*img2;
	char			*img_save;
	t_camera		*aux_cam;
	t_hit			p;
}					t_scene;

void				checker(int argc, char **argv, t_scene *scene);
void				read_cam(char *line, t_scene *scene);
void				read_sphere(char *line, t_scene *scene);
void				delete_cams(t_scene *scene);
int					ft_isblank(int c);
void				skip_blanks(char **s);
void				skip_digits(char **s);
void				skip_char(char **s, int c);
int					get_int(char **line, t_scene *scene);
double				get_double(char **line, t_scene *scene);
t_vec3				get_vec3(char **line, t_scene *scene);
t_color				get_color(char **line, t_scene *scene);
double				mod_vec3(t_vec3 a);
t_vec3				norm(t_vec3 a);
void				delete_spheres(t_scene *scene);
void				delete_planes(t_scene *scene);
void				delete_cylinders(t_scene *scene);
void				delete_squares(t_scene *scene);
void				delete_triangles(t_scene *scene);
t_vec3				new_vec3(double a, double b, double c);
t_vec3				prod_vec3_mat3(t_vec3 a, t_mat3 m);
t_vec3				sum_vec3(t_vec3 a, t_vec3 b);
t_vec3				sub_vec3(t_vec3 a, t_vec3 b);
t_mat3				new_mat3(t_vec3 a, t_vec3 b, t_vec3 c);
t_vec3				cross_prod(t_vec3 a, t_vec3 b);
t_vec3				scal_vec3(double c, t_vec3 a);
void				render_scene(t_scene *scene);
void				render_sphere(t_ray *ray, t_scene *scene, t_sphere *aux);
double				intersect_sphere(t_ray *ray, t_sphere *aux);
double				dot_prod(t_vec3 a, t_vec3 b);
t_color				ray_cast(t_ray *ray, t_scene *scene);
void				read_plane(char *line, t_scene *scene);
void				render_plane(t_ray *ray, t_scene *scene, t_plane *aux);
void				read_cylinder(char *line, t_scene *scene);
void				read_light(char *line, t_scene *scene);
void				delete_scene(t_scene *scene);
void				read_triangle(char *line, t_scene *scene);
void				read_square(char *line, t_scene *scene);
void				render_cyl(t_ray *ray, t_scene *scene, t_cylinder *aux);
double				intersect_plane(t_ray *ray, t_plane *aux);
void				render_caps(t_ray *ray, t_scene *scene, t_cylinder *aux);
t_color				add_amb(t_scene *s, t_color point);
t_color				sepia_filter(t_color color);
t_color				mono_filter(t_color color);
void				save_image_bmp(t_scene *scene);
t_color				shading(t_scene *scene, t_hit *p);
int					shad_1(t_scene *scene, t_ray *shadow_ray, t_vec3 light_pos);
double				intersect_sphere2(t_ray *ray, t_sphere *aux);
double				intersect_plane(t_ray *ray, t_plane *aux);
void				skip_string(char **s);
void				render_square(t_ray *ray, t_scene *scene, t_square *aux);
void				read_dir_light(char *line, t_scene *scene);
int					dir_shadows_1(t_scene *scene, t_ray *shadow_ray);
t_color				red_filter(t_color color);
t_color				green_filter(t_color color);
t_color				blue_filter(t_color color);
int					in_square(t_square *aux, t_vec3 point);
double				intersect_square(t_ray *ray, t_square *square);
double				intersect_cylinder(t_ray *ray, t_cylinder *aux);
double				intersect_caps(t_ray *ray, t_cylinder *aux);
double				intersect_cyl(t_ray *ray, t_scene *scene, t_cylinder *cyl);
void				render_tr(t_ray *ray, t_scene *scene, t_triangle *aux);
int					intersect_triangle(t_ray *ray, t_triangle *aux);
void				delete_lights(t_scene *scene);
double				intersect_sphere3(t_ray *ray, t_sphere *aux);
void				exit_error_msg(t_error id, t_scene *scene);
void				read_file(char *file, t_scene *scene);
void				cam_rot_matrix(t_scene *scene);

#endif
