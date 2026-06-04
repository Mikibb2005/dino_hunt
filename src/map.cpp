#include "../include/map.h"



void Map::draw_paredes()
{
    float map_width_world = size_x * TILE_SIZE;
    float map_height_world = size_y * TILE_SIZE;

    DrawPlane({ map_width_world / 2.0f, 0.0f, map_height_world / 2.0f }, { map_width_world, map_height_world }, DARKGRAY);

    for(int x = 0; x < size_x; x++)
    {
        for(int z = 0; z < size_y; z++)
        {
            if(m_grid[x][z] > 0)
            {
                float pos_x = x * TILE_SIZE + TILE_SIZE / 2.0f;
                float pos_y = WALL_HEIGHT / 2.0f;
                float pos_z = z * TILE_SIZE + TILE_SIZE / 2.0f;

                DrawCube({pos_x, pos_y, pos_z}, TILE_SIZE, WALL_HEIGHT, TILE_SIZE, GRAY);
                DrawCubeWires({pos_x, pos_y, pos_z}, TILE_SIZE, WALL_HEIGHT, TILE_SIZE, DARKGRAY);
            }
        }   
    }
}