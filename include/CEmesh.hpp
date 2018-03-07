
#ifndef CEMESH
#define CEMESH

#include <CEentity.hpp>
#include <CEresourceMesh.hpp>

class CEMesh : public CEEntity{
public:
	CEMesh();
	virtual ~CEMesh();

	void loadResource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw() override;

private:
	CEResourceMesh* m_mesh;
};

#endif