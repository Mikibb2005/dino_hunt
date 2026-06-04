/******************************************************************************
 * Archivo: main.cpp
 * Autor:   Miguel Blánquez Bravo
 * Fecha:   04-06-2026
 *
 * Descripción:
 * Dino Hunt
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

#include "../include/enemy.h"
#include "../include/map.h"
#include "../include/player.h"
#include "../include/ui.h"
#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include <cstdio>
#include <math.h>

// VARIABLES DE SISTEMA
int screen_width = 1280;
int screen_height = 720;

bool close = false;

int main() {
  // Inicializar ventana
  InitWindow(screen_width, screen_height, "Dino Hunt");

  // Inicializar sistema de sonido
  InitAudioDevice();

  // Hacer que ESC no cierre la ventana / limitar fps a 60
  SetExitKey(0);
  SetTargetFPS(60);

  // Creamos el player
  Player m_player = {};
  m_player.setPosition(500.0f, 600.0f);

  // camara 3d configurada
  Camera3D m_cam = {};
  m_cam.position = {m_player.getPosition().x, EYE_HEIGHT, m_player.getPosition().y};
  m_cam.target = {};
  m_cam.up = {0.0f, 1.0f, 0.0f};
  m_cam.fovy = 60.0f;
  m_cam.projection = CAMERA_PERSPECTIVE;

  // Creamos el mapa
  Map m_map;
  // TODO:falta cargar el grid del mapa y de las paredes
  if(!m_map.load_from_csv("resources/mapa1.csv"))
  {
    printf("Erorr cargando CSV\n");
  }

  // creamos los enemies
  EnemyManager m_enemies;
  m_enemies.load_resources();

  Enemy a1;
  a1 = Enemy();
  m_enemies.add_enemy(a1);

  bool paused = false;

  while (!WindowShouldClose() && !close) {
    if (IsKeyPressed(KEY_ESCAPE) ||
        (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_MIDDLE_RIGHT)))
      paused = !paused;

    if (!paused) {
      m_player.update_player(m_enemies, m_map);
      // m_player.setHealth(m_player.getHealth() - 1);

      float angle = m_player.getAngle();
      float pitch = m_player.getPitch();
      Vector2 pos = m_player.getPosition();
      m_cam.position = {pos.x, EYE_HEIGHT, pos.y};
      m_cam.target = {m_cam.position.x + cosf(pitch) * cosf(angle), m_cam.position.y + sinf(pitch), m_cam.position.z + cosf(pitch) * sinf(angle)};

      m_enemies.update_all();

    } 
    else 
    {
      if (pause_menu())
      {
        paused = false;
      }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    BeginMode3D(m_cam);
    m_map.draw_paredes();
    // TODO: dibujar enemigos como billboards
    // TODO: dibujar los dinos como billboards
    EndMode3D();

    // TODO: Aqui se dibuja el HUD
    draw_hud(screen_height, screen_width, m_player.getActiveGun(), m_player.getHealth());

    if (paused) 
    {
      draw_pause_menu();
    }

    DrawFPS(screen_width - 80, 10);
    EndDrawing();
    close = close_g();
  }

  // TODO: Unloadear texturas del mapa

  CloseAudioDevice();
  CloseWindow();
  return 0;
}
