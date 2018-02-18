
#ifndef CEMESH
#define CEMESH

#include <CEentity.hpp>

class CEMesh : public CEEntity{
public:
	CEMesh();
	~CEMesh();

	void loadSource(const char* p_urlSource);

	void beginDraw();
	void endDraw();

private:
	//CEResourceMesh* m_mesh;
};

#endif