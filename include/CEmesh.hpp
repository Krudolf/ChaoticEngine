
#ifndef CEMESH
#define CEMESH

#include <CEentity.hpp>
#include <CEresourceMesh.hpp>

class CEMesh : public CEEntity{
public:
	CEMesh();
	~CEMesh();

	void loadResource(const char* p_urlSource);

	void beginDraw();
	void endDraw();

private:
	CEResourceMesh* m_mesh;
};

#endif