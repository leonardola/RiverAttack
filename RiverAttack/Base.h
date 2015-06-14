#include "Airplane.h"
#include "Shape.h"

class Base: public Shape
{
public:
	Base(void);
	~Base(void);
	Base(int windowHeight, int windowWidth);
	int draw(int position);
	bool hasColided(Airplane plane);
private:
	int windowHeight;
	int windowWidth;
	bool hasColidedWithLeftBase(Airplane plane);
	bool hasColidedWithRightBase(Airplane plane);
};
