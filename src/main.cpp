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


#include "../raylib-5.5_linux_amd64/include/raylib.h"
#include "../include/guns.h"
#include "../include/player.h"


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

    //TODO: clase Player
    //Player player;

    Camera2D cam = {};

    while(1)
    {
        
    }




    CloseAudioDevice();
    CloseWindow();
    return 0;
}