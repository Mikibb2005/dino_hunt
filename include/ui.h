#pragma once

#include "../raylib-6.0_linux_amd64/include/raylib.h"
#include "guns.h"


const int num_options = 4;


void draw_pause_menu();
bool close_g();
bool pause_menu();

void draw_hud(int height, int width, Gun g, int health);


void draw_minimap(int height, int width);
//TODO: draw_mision()
void draw_mision(int height, int width);
void draw_weapon(int height, int width, Gun g);
void draw_life(int height, int width, int health);
