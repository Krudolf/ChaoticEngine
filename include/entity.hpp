 
#ifndef ENTITY
#define ENTITY

/*Virtual class*/
class Entity{
public:
	virtual void beginDraw() = 0;
	virtual void endDraw() = 0;
};

#endif