#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"


const int MAP_WIDTH = 800;
const int MAP_HEIGHT = 800;

class Map
{
    public:
        Map()
        {
            // MIGRACIÓN: Inicializar el grid del mapa aquí
        }
        ~Map() { }

        int getSizeX() const {return size_x;}
        int getSizeY() const {return size_y;}

        int getCell(int x, int y);
        void draw_map(Camera3D cam); //para paredes en 3D
        void DrawCube();

    private:
        int size_x = MAP_WIDTH;
        int size_y = MAP_HEIGHT;
        int m_grid[MAP_WIDTH][MAP_HEIGHT];
        Texture2D m_wall_textures[];
};
