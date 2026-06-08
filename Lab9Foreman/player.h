#ifndef PLAYERH
#define PLAYERH
class player
{
public:
	player(int HEIGHT);
	~player();
	void DrawPlayer(int lives);
	void DrawLives(int lives);
	void MoveUp();
	void MoveDown(int HEIGHT);
	void MoveLeft();
	void MoveRight();
	int getLives();
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
	void removeLife() { lives--; }
	void addScore();
	int getScore();
private:
	int x;
	int y;
	int lives;
	int speed;
	int boundx;
	int boundy;
	int score;
	ALLEGRO_BITMAP* kirbies[5];

	ALLEGRO_BITMAP* image;
	ALLEGRO_BITMAP* image1;
	ALLEGRO_BITMAP* image2;
	ALLEGRO_BITMAP* image3;
	ALLEGRO_BITMAP* image4;
};
#endif
