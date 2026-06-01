/******************************************************************************
 * Archivo: main.cpp
 * Autor:   Miguel Blánquez Bravo
 * Fecha:   28-05-2026
 *
 * Descripción:
 * 
 *
 * ---------------------------------------------------------------------------
 * COPYRIGHT NOTICE / AVISO DE DERECHOS DE AUTOR
 * ---------------------------------------------------------------------------
 * Copyright (c) 2026 Miguel Blánquez Bravo.
 * Todos los derechos reservados.
 *
 * Este código fuente es PROPIEDAD EXCLUSIVA y CONFIDENCIAL de
 * Miguel Blánquez Bravo.
 *
 * Queda estrictamente prohibida la copia, reproducción, distribución,
 * publicación, transmisión, modificación, o uso de este archivo o cualquier
 * parte del mismo, ya sea en formato fuente o binario, sin el permiso
 * previo, expreso y por escrito del autor.
 *
 * Cualquier uso no autorizado será sujeto a acciones legales.
 ******************************************************************************/


#include "../raylib-6.0_linux_amd64/include/raylib.h"
//#include "../include/guns.h"
#include "../include/player.h"
#include "../include/map.h"
#include <cstdio>


//VARIABLES DE SISTEMA
int screen_width = 1280;
int screen_height = 720;


int main()
{
    //Inicializar ventana
    InitWindow(screen_width, screen_height, "Game-dev");

    // Inicializar sistema de sonido
    //SoundSystem soundSystem;
    InitAudioDevice();

    // Hacer que ESC no cierre la ventana / limitar fps a 60
    SetExitKey(0);
    SetTargetFPS(60);

    //Creamos el player
    Player player = {};
    player.setPosition(500.0f,600.0f);

    // Creamos la camara
    // TODO: Hay que centrar la camara a las coordenadas del player
    Camera2D cam = {};

    
    cam.target = player.getPosition();
    cam.offset = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f};
    cam.rotation = 0.0f;
    cam.zoom = 1.0f;

    Map m_map;
    //TODO:asignar archivo
    m_map.setFile("resources/mapa.png");
    m_map.load_texture();
    printf("Texture ID: %d\n", m_map.getTexture().id);
    
 
    while(!WindowShouldClose())
    {
        //TODO        
        player.update_player();
        cam.target = player.getPosition();


        BeginDrawing();

        ClearBackground(BLACK);
        BeginMode2D(cam);

        m_map.draw_map();
        player.draw_player();
        //printf("%d , %d\n", int(player.getPosition().x), int(player.getPosition().y));


        EndMode2D();
        DrawFPS(screen_width - 80, 10);
        DrawText(TextFormat("X: %.0f  Y: %.0f", player.getPosition().x, player.getPosition().y), 10, 10, 20, WHITE);
        EndDrawing();
    }

    UnloadTexture(m_map.getTexture());

    CloseAudioDevice();
    CloseWindow();
    return 0;
}