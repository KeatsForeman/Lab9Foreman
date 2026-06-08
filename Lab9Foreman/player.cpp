#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"


player::~player()
{
	al_destroy_bitmap(kirbies[0]);
	al_destroy_bitmap(kirbies[1]);
	al_destroy_bitmap(kirbies[2]);
	al_destroy_bitmap(kirbies[3]);
	al_destroy_bitmap(kirbies[4]);
}
player::player(int HEIGHT)
{
	kirbies[4] = al_load_bitmap("Kirby.png");
	kirbies[3] = al_load_bitmap("Kirby1.png");
	kirbies[2] = al_load_bitmap("Kirby2.png");
	kirbies[1] = al_load_bitmap("Kirby3.png");
	kirbies[0] = al_load_bitmap("Kirby4.png");

	x = 20;
	y = HEIGHT / 2;
	lives = 5;
	speed = 7;
	boundx = al_get_bitmap_width(kirbies[0]);
	boundy = al_get_bitmap_height(kirbies[0]);
	score = 0;
}
void player::DrawPlayer(int lives)
{
	al_draw_bitmap(kirbies[lives - 1], x, y, 0);
}

//draws the number of kirbies left
void player::DrawLives(int lives) {
	int lx = 20;
	int ly = 20;
	for (int i = 0; i < lives; i++) {
		al_draw_scaled_bitmap(kirbies[4], 0, 0, 50, 50, lx, ly, 20, 20, 0);
		lx += 20;
	}
}
void player::MoveUp()
{
	y -= speed;
	if (y < 0)
		y = 0;
}
//fixed collision
void player::MoveDown(int HEIGHT)
{
	y += speed;
	if (y > HEIGHT - boundy)
		y = HEIGHT - boundy;
}
void player::MoveLeft()
{
	x -= speed;
	if (x < 0)
		x = 0;
}
void player::MoveRight()
{
	x += speed;
	if (x > 300)
		x = 300;
}
int player::getLives() {
	return this->lives;
}
void player::addScore() {
	score += 1;
}
int player::getScore() {
	return score;
}