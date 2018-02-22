
#ifndef CEMESH
#define CEMESH

#include <CEentity.hpp>
#include <CEresourceMesh.hpp>
#include <vector>

class CEMesh : public CEEntity{
public:
	CEMesh();
	~CEMesh();

	void loadResource(const char* p_urlSource);

	void beginDraw();
	void endDraw();

private:
	std::vector<CEResourceMesh*> m_mesh;
};

#endif