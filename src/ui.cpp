#include "../include/ui.h"

bool close_game = false;
int m_selected_option = 0;


bool close_g() { return close_game; }


bool pause_menu()
{
    if(IsKeyPressed(KEY_UP))
    {
        m_selected_option--;
        if(m_selected_option < 0)
        {
            m_selected_option = num_options - 1;
        }
    }
    if(IsKeyPressed(KEY_DOWN))
    {
        m_selected_option++;
        if(m_selected_option >= num_options)
        {
            m_selected_option = 0;
        }
    }
    if(IsKeyPressed(KEY_ENTER))
    {
        switch (m_selected_option) 
        {
            case 0: //VOLVER AL JUEGO
                return true;
            case 1: //GUARDAR
                //save_game();
                break;
            case 2: //OPCIONES
                //game_options();
                break;
            case 3: //SALIR
                //dibujar flecha en cuarta pos
                close_game = true;
                return true;
        }
    }
    /*if(IsKeyPressed(KEY_ESCAPE))
    {
        return true;
    }*/
    return false;
}


void draw_pause_menu()
{
    const char* options[] = {"VOLVER AL JUEGO", "GUARDAR PARTIDA", "OPCIONES", "SALIR DEL JUEGO"};

    DrawRectangle(0, 0, 1280, 720, (Color){0,0,0,200});
    DrawText("PAUSA", 1280/2 - 50, 100, 40, WHITE);

    for(int i = 0; i < num_options; i++)
    {
        Color color = (i == m_selected_option) ? YELLOW : WHITE;
        DrawText(options[i], 1280/2 - 60, 200 + i * 50, 30, color);
    }
}
