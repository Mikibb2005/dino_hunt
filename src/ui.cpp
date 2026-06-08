#include "../include/ui.h"
#include "../include/options.h"

bool close_game = false;
int m_selected_option = 0;
bool in_options = false;


bool close_g() { return close_game; }


bool pause_menu(int width, int height)
{
    if(in_options)
    {
        if(update_options())
        {
            in_options = false;
        }   
        return false;
    }
    if(IsKeyPressed(KEY_UP) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_UP))
    {
        m_selected_option--;
        if(m_selected_option < 0)
        {
            m_selected_option = num_options - 1;
        }
    }
    if(IsKeyPressed(KEY_DOWN) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN))
    {
        m_selected_option++;
        if(m_selected_option >= num_options)
        {
            m_selected_option = 0;
        }
    }
    if(IsKeyPressed(KEY_ENTER) || IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN))
    {
        switch (m_selected_option) 
        {
            case 0: //VOLVER AL JUEGO
                return true;
            case 1: //GUARDAR
                //save_game();
                break;
            case 2: //OPCIONES
                in_options = true;
                //game_options(width, height);
                break;
            case 3: //SALIR
                //dibujar flecha en cuarta pos
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


void draw_pause_menu(int width, int height)
{
    if(in_options)
    {
        draw_options(width, height);
        return;
    }
    const char* options[] = {"VOLVER AL JUEGO", "GUARDAR PARTIDA", "OPCIONES", "SALIR DEL JUEGO"};


    DrawRectangle(0, 0, width, height, (Color){0,0,0,200});
    DrawText("PAUSA", width/2 - 50, 100, 40, WHITE);

    for(int i = 0; i < num_options; i++)
    {
        Color color = (i == m_selected_option) ? YELLOW : WHITE;
        DrawText(options[i], 60, 200 + i * 50, 30, color);
    }
}



void draw_hud(int height, int width, Gun g, int health)
{
    draw_minimap(height, width);
    draw_life(height, width, health);
    //draw_mision(height, width);
    draw_weapon(height, width, g);
}


void draw_minimap(int height, int width)
{
    int x = width * 0.15625;
    int y = height * 0.27777778;
    int px = width * 0.03125;
    int py = height * 0.0555555556;
    DrawRectangle(px, py, x, y, Color{0,0,0,100});
}

void draw_mision(int height, int width)
{
    int px = width * 0.03125;
    int py = height * 0.3888888889;
    int x = width * 0.15625;
    int y = height * 0.125;
    DrawRectangle(px, py, x, y, Color{0,0,0,100});

}

void draw_weapon(int height, int width, Gun g)
{
    int px = width * 0.03125;
    int py = height * 0.0555555556;
    int x = width * 0.2109375;
    int y = height * 0.13888889;
    DrawRectangle(px, height - py - y, x, y, Color{0,0,0,100});

    switch (g.getType()) 
    {
        case NONE:
            DrawText("NO GUN!!",px + 10 , height - py - 60  , 20, WHITE);
            DrawText("0 / 0",px + 10 , height - py - 35  , 20, WHITE);
            break;
        case PISTOL:
            DrawText("Pistol",px + 10 , height - py - 60  , 20, WHITE);
            DrawText(TextFormat("%i / %i", g.getAmmo(), g.getChargerSize()), px + 10, height - py - 35, 20, WHITE);
            break;
        case RIFLE:
            DrawText("Rifle",px + 10 , height - py - 60  , 20, WHITE);
            DrawText(TextFormat("%i / %i", g.getAmmo(), g.getChargerSize()), px + 10, height - py - 35, 20, WHITE);
            break;
        case BAT:
            DrawText("Bat",px + 10 , height - py - 60  , 20, WHITE);
            break;
        case KNIFE:
            DrawText("Knife",px + 10 , height - py - 60  , 20, WHITE);
            break;
    }
}

void draw_life(int height, int width, int health)
{
    int px = width * 0.03125;
    int py = height * 0.0555555556;
    int x = width * 0.3125;
    int y = height * 0.0555555556;
    DrawRectangle(width - px - x, height - py - y, x, y, Color{0,0,0,100});

    float n_px = x *(1 - ((float)health / 100.0f));
    float n_x = ((float)health / 100.0f);


    if(health >= 75) 
    {
        DrawRectangle(width - px - x + 5, height - py - y + 5, (x- 10)*n_x , y - 10, Color{0,255,0,255});
    }
    if(health < 75 && health >= 50)
    {
        DrawRectangle(width - px - x + 5, height - py - y + 5, (x- 10)*n_x, y - 10, LIME);
    }
    if(health < 50 && health >=25)
    {
        DrawRectangle(width - px - x + 5, height - py - y + 5, (x- 10)*n_x, y - 10, ORANGE);
    }
    if(health < 25)
    {
        DrawRectangle(width - px - x + 5, height - py - y + 5, (x- 10)*n_x, y - 10, RED);
    }
    
    

}