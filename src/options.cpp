#include "../include/options.h"

extern bool close_game;
extern int screen_width;
extern int screen_height;
static int m_selected_option = 0;
int res_index = 2;



void draw_options(int width, int height)
{

    const char* options[] = {"VOLVER AL MENU", "RESOLUCION", "VOLUMEN", "SALIR DEL JUEGO"};


    DrawRectangle(0, 0, width, height, (Color){0,0,0,200});
    DrawText("OPCIONES", width/2 - 50, 100, 40, WHITE);

    for(int i = 0; i < num_options_options; i++)
    {
        Color color = (i == m_selected_option) ? YELLOW : WHITE;
        DrawText(options[i], 60, 200 + i * 50, 30, color);
        if(i == 1)
        {
            DrawText(m_resolution[res_index].label,260,260,25,color);
        }
    }
}

bool update_options()
{
    
    if(IsKeyPressed(KEY_UP) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        m_selected_option--;
        if(m_selected_option < 0)
        {
            m_selected_option = num_options_options - 1;
        }
    }
    if(IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        m_selected_option++;
        if(m_selected_option >= num_options_options)
        {
            m_selected_option = 0;
        }
    }
    if(m_selected_option == 1)
    {
        if(IsKeyPressed(KEY_LEFT))
        {
            res_index--;
            if(res_index < 0)
            {
                res_index = 5;
            }   
        }  
        if(IsKeyPressed(KEY_RIGHT))
        {
            res_index++;
            if(res_index > 5)
            {
                res_index = 0;
            }
        }
        
    }
    if(IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
    {
        switch (m_selected_option) 
        {
            case 0: //VOLVER AL MENU
                return true;
            case 1: //RESOLUCION
                if(res_index == 0)
                {
                    int monitor = GetCurrentMonitor();
                    screen_width = GetMonitorWidth(monitor);
                    screen_height = GetMonitorHeight(monitor);
                }
                else
                {
                    screen_width = m_resolution[res_index].width;
                    screen_height = m_resolution[res_index].height;
                }
                SetWindowSize(screen_width, screen_height);
                break;
            case 2: //VOLUMEN JUEGO
                break;
            case 3: //
                close_game = true;
                return true;
        }
    }
    if(IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT))
    {
        return true;
    }
    return false;
}

void game_options(int width, int height)
{
    draw_options(width, height);
    update_options();
}