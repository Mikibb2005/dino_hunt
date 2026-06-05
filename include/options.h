#include "../raylib-6.0_linux_amd64/include/raylib.h"

const int num_options_options = 4;

struct Resolucion
{
    int width;
    int height;
    const char* label;
};


const Resolucion m_resolution[] =
{
    {0,0,"< AUTO >"},
    {854, 480, "< 480p >"},
    {1280, 720, "< 720p >"},
    {1920, 1080, "< 1080p >"},
    {2560, 1440, "< 1440p >"},
    {3840, 2160, "< 2160p (4K) >"},
};

extern int res_index;

void game_options(int width, int height);
void draw_options(int width, int height);
bool update_options();