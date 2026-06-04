# Dino Hunt — Notas de Migración desde shooting_zombies

## Origen
Proyecto migrado desde `shooting_zombies` (top-down 2D) a FPS estilo Doom con Camera3D de raylib y sprites 2D direccionales.

---

## Comentarios de diseño encontrados en el código original

### player.h
- `"En un futuro posible ampliacion para comprovar colision con partes del mapa de colision"` → En el nuevo proyecto esto es **obligatorio**: las colisiones con paredes del grid son fundamentales para el FPS.

### enemy.h
- `"para restar la vida, ademas de comprovar si muere"` → `take_damage()` debe comprobar muerte.
- `"devuelve true si esta muerto"` → `is_dead()` funciona, se mantiene.

### guns.cpp
- Cadencia expresada en disparos/segundo: pistola=3, rifle=5, cuchillo=0.75, bate=0.5.
- Velocidad de bala en coords/s: pistola=5, rifle=7.
- Estas unidades necesitarán ajuste al nuevo sistema de coordenadas 3D (las distancias cambian).

### main.cpp
- `"TODO: Hay que centrar la camara a las coordenadas del player"` → Resuelto en el original, pero en el nuevo proyecto la cámara es Camera3D, hay que recalcular target con `cos(angle)`/`sin(angle)`.
- `"TODO: asignar archivo"` → Ya no aplica, el mapa ahora es un grid de tiles, no un archivo PNG.

---

## Archivos copiados sin cambios (100% reutilizables)

| Archivo | Motivo |
|---------|--------|
| `include/guns.h` | Sistema de armas completo, agnóstico a la perspectiva |
| `src/guns.cpp` | Lógica de disparo, recarga, cadencia — no depende de 2D/3D |
| `include/ui.h` | Menú de pausa en coordenadas de pantalla |
| `src/ui.cpp` | Lógica y renderizado del menú de pausa |

## Archivos copiados con recortes (código 2D eliminado)

| Archivo | Qué se eliminó |
|---------|----------------|
| `include/player.h` | `m_aim_direction`, `m_hitbox`, `draw_player()`, `update_collision()` |
| `src/player.cpp` | `draw_player()`, `update_collision()`, movimiento WASD 2D |
| `include/enemy.h` | `m_hitbox` (Rectangle) |
| `src/enemy.cpp` | `enemy_draw()` body (DrawRectangle) |
| `include/map.h` | Texture2D, RenderTexture2D, file loading |
| `src/map.cpp` | load_texture(), draw_map() con DrawTexture |
| `src/main.cpp` | Camera2D, BeginMode2D, carga de textura de mapa |

---

## Tareas de implementación pendientes (por orden)

### Fase 1: Camera3D + Mapa basado en grid
- [ ] Definir `int m_grid[][]` en `Map` con tiles de pared
- [ ] Implementar `draw_map()` con `DrawCube()` por cada tile sólido
- [ ] Dibujar suelo con `DrawPlane()` o un quad
- [ ] Crear `Camera3D` en `main.cpp` con perspectiva primera persona
- [ ] Usar `BeginMode3D()` / `EndMode3D()`

### Fase 2: Movimiento en primera persona
- [ ] Añadir `float m_angle` al Player
- [ ] W/S = avanzar/retroceder en dirección del ángulo (`cos`/`sin`)
- [ ] A/D = strafe lateral
- [ ] Ratón X = rotar (cambiar `m_angle`)
- [ ] `DisableCursor()` para capturar el ratón

### Fase 3: Colisiones 3D
- [ ] Colisión jugador vs paredes del grid (comprobar celda destino)
- [ ] Colisión jugador vs enemigos (radio en plano XZ)

### Fase 4: Enemigos como billboards direccionales
- [ ] Añadir `m_facing_angle`, `m_anim_frame`, `m_anim_timer` al Enemy
- [ ] Cargar spritesheet con 4 filas (frente/espalda/izq/der) × N frames
- [ ] Calcular ángulo relativo jugador→enemigo para seleccionar fila
- [ ] `DrawBillboardRec()` con rectángulo del spritesheet
- [ ] Avanzar frames de animación con timer

### Fase 5: HUD en primera persona
- [ ] Sprite del arma activa en la parte inferior de la pantalla (después de `EndMode3D()`)
- [ ] Crosshair / punto de mira centrado
- [ ] Indicadores: vida, munición, arma activa

---

## Decisiones de diseño pendientes

1. **Tamaño de tile**: ¿Cuántas unidades 3D mide cada celda del grid? (ej: 2.0f)
2. **Altura de las paredes**: ¿Cuánto de altas? (ej: 3.0f)
3. **Altura de ojos del jugador**: ¿A qué Y se pone la cámara? (ej: 1.6f)
4. **FOV**: ¿Qué campo de visión? (ej: 60°-90°)
5. **Sprites de enemigos**: ¿Resolución? ¿Cuántos frames por dirección?
6. **Sprites de armas HUD**: ¿Animación de disparo? ¿Cuántos frames?
