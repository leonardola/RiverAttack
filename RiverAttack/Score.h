#pragma once
class Score
{
public:
	Score(void);
	~Score(void);
	Score(int windowHeight, int windowWidth);
	void addScore();
	int getScore();
	void draw();
private: 
	int windowHeight;
	int windowWidth;
	int score;
};

