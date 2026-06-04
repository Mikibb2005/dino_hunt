#include "../include/map.h"

// MIGRACIÓN: load_texture() eliminado
// Antes cargaba una imagen PNG como textura del mapa.
// Reimplementar: cargar texturas de pared individuales (Texture2D por tipo de tile)

// MIGRACIÓN: render_texture() eliminado

// MIGRACIÓN: draw_map() eliminado
// Antes: DrawTexture(m_texture, 0, 0, WHITE)
// Reimplementar: recorrer el grid, por cada celda con valor > 0 dibujar
void Map::DrawCube()
{
    for (int x = 0; x < size_x; x++)
        for (int z = 0; z < size_y; z++)
            if (m_grid[x][z] > 0)
                DrawCube({x*TILE_SIZE, WALL_HEIGHT/2, z*TILE_SIZE}, TILE_SIZE, WALL_HEIGHT, TILE_SIZE, GRAY);
}