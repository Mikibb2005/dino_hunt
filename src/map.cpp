#include "../include/map.h"

void Map::load_texture()
{
    if(m_file)
    {
        m_texture = LoadTexture(m_file);
    }
}

void Map::render_texture()
{
    
}

void Map::draw_map()
{
    if(m_file != nullptr)
    {
        //load_texture();
        //render_texture();
        DrawTexture(m_texture, 0, 0, WHITE);
    }
}