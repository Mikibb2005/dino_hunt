#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"


const int MAP_WIDTH = 800;
const  int MAP_HEIGHT = 800;


class Map
{
    public:
        Map()
        {
            m_file = nullptr;
        }
        ~Map() { }
        void setTexture(Texture2D t) { m_texture = t; }
        void setSizeX(int x) { size_x = x; }
        void setSizeY(int y) { size_y = y; }
        void setRender(RenderTexture2D r) { m_render = r; }
        void setFile(const char *f) { m_file = f; }
        
        
        Texture2D getTexture() { return m_texture; }
        int getSizeX() {return size_x;}
        int getSizeY() {return size_y;}
        RenderTexture2D getRender() { return m_render; }
        const char* getFile() {return m_file; }

        void load_texture();
        void render_texture();
        void draw_map();

    private:
        int size_x = MAP_WIDTH;
        int size_y = MAP_HEIGHT;
        Texture2D m_texture;
        RenderTexture2D m_render;
        const char *m_file;
};
