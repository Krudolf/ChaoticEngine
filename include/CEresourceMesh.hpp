 
#ifndef CERESOURMESH
#define CERESOURMESH

#include <vector>

#include "manager/resource.hpp"

class CEResourceMesh: public CEResource{
public:
	CEResourceMesh();
	~CEResourceMesh();

	void loadFile(const char* p_name);
	void draw();

private:
	std::vector<float*> vertices, normals, textures, vertTriangles, normTriangles, textTriangles;
	long int nTriangles;
};

#endif