
#ifndef MESH
#define MESH

#include <entity.hpp>

class Mesh : public Entity{
public:
	Mesh();
	~Mesh();

	void loadSource(const char* p_urlSource);

	void beginDraw();
	void endDraw();

private:
	//ResourceMesh* m_mesh;
};

#endif