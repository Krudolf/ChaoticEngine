
#ifndef MESH
#define MESH

#include <entity.hpp>

class Mesh : public Entity{
public:
	Mesh();
	~Mesh();

	void beginDraw();
	void endDraw();

private:

};

#endif