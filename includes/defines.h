/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zeatilga <zeatilga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:14:13 by facetint          #+#    #+#             */
/*   Updated: 2024/08/10 20:42:01 by zeatilga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define VIOLET_BOLD "\033[1m\033[38;2;238;130;238m"
# define RESET "\033[0m"
# define ERROR "Error\n"
# define MAP_EXTENSION_SHORT "Map file extension is too short\n"
# define MAP_EXTENSION_IS_NOT_CUB "Map file extension is not .cub\n"
# define WRONG_ARGS "Wrong arguments\n"
# define OPEN_ERROR "Map file does not exist\n"
# define READ_ERROR "Error while reading the map file, could be empty!\n"
# define SAFE_MALLOC_ERROR "Memory allocation error\n"
# define MALLOC_ERROR "Memory allocation error\n"
# define INVALID_CHARACTER "Invalid character in map\n"
# define INVALID_METADATA_ID_LENGTH "Invalid metadata id length\n"
# define MISSING_METADATA "Missing metadata\n"
# define EMPTY_MAP "Empty map\n"
# define MAP_NOT_SURROUNDED_BY_WALL "Map is not surrounded by walls\n"
# define DUPLICATE_OR_TOO_LONG "Duplicate key or ceiling, floor key too long\n"
# define DUPLICATE "Duplicate value\n"
# define INVALID_RGB "Invalid RGB\n"
# define LONG_METADATA_KEY "Metadata key is too long\n"
# define MULTIPLE_SPAWN_POINTS "Multiple spawn points\n"
# define NO_SPAWN_POINT "No spawn point\n"

#endif