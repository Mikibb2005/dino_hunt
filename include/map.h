#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"


const int MAP_WIDTH = 800;
const int MAP_HEIGHT = 800;

const float TILE_SIZE = 64.0f;
const float WALL_HEIGHT = 128.0f;
const float EYE_HEIGHT = 48.0f;

class Map
{
    public:
        Map()
        {
            // MIGRACIÓN: Inicializar el grid del mapa aquí
            for (int x = 0; x < size_x; x++)
            {
                for (int z = 0; z < size_y; z++)
                {
                    // Crear paredes en los bordes del mapa
                    if (x == 0 || x == size_x - 1 || z == 0 || z == size_y - 1)
                    {
                        m_grid[x][z] = 1;
                    }
                    // Crear 4 pilares interiores
                    else if ((x == 4 && z == 4) || (x == 4 && z == 11) || 
                            (x == 11 && z == 4) || (x == 11 && z == 11))
                    {
                        m_grid[x][z] = 1;
                    }
                    else
                    {
                        m_grid[x][z] = 0; // Espacio vacío
                    }
                }
            }
        }
        ~Map() { }

        int getSizeX() const {return size_x;}
        int getSizeY() const {return size_y;}

        int getCell(int x, int y);
        void draw_map(Camera3D cam); //para paredes en 3D
        void draw_paredes();

    private:
        int size_x = MAP_WIDTH;
        int size_y = MAP_HEIGHT;
        int m_grid[MAP_WIDTH][MAP_HEIGHT];
        Texture2D m_wall_textures[];
};
