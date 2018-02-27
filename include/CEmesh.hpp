
#ifndef CEMESH
#define CEMESH

#include <CEentity.hpp>

class CEMesh : public CEEntity{
public:
	CEMesh();
	virtual ~CEMesh();

	void loadSource(const char* p_urlSource);

	void beginDraw() override;
	void endDraw() override;

private:
	//ResourceMesh* m_mesh;
};

#endif