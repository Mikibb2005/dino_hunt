#include "../include/map.h"
#include <fstream>
#include <sstream>
#include <iostream>


void Map::draw_paredes()
{
    float map_width_world = size_x * TILE_SIZE;
    float map_height_world = size_y * TILE_SIZE;
    DrawPlane({ map_width_world / 2.0f, 0.0f, map_height_world / 2.0f }, { map_width_world, map_height_world }, DARKGRAY);
    for(int z = 0; z < size_y; z++)
    {
        for(int x = 0; x < size_x; x++)
        {
            if(m_grid[z][x] > 0)
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


bool Map::load_from_csv(const std::string& filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        std::cerr << "Error: No se pudo abrir el mapa en " << filepath << std::endl;
        return false;
    }
    m_grid.clear();
    std::string line;
    
    while (std::getline(file, line))
    {
        std::vector<int> row;
        std::stringstream ss(line);
        std::string value;
        while (std::getline(ss, value, ','))
        {
            row.push_back(std::stoi(value));
        }
        if (!row.empty())
        {
            m_grid.push_back(row);
        }
    }
    file.close();
    size_y = m_grid.size();
    size_x = (size_y > 0) ? m_grid[0].size() : 0;
    std::cout << "Mapa cargado con exito. Dimensiones: " << size_x << "x" << size_y << std::endl;
    return true;
}

int Map::getCell(int x, int y)
{
    if (x >= 0 && x < size_x && y >= 0 && y < size_y)
    {
        return m_grid[y][x];
    }
    return 1;
}
