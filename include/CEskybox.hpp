
#ifndef CESKYBOX
#define CESKYBOX

#include <CEentity.hpp>
#include <glew.h> 
#include <glm.hpp>

class CESkybox : public CEEntity{
public:
	CESkybox GLuint p_shaderProgram();
	virtual ~CESkybox();

	void makeSkyCube();

	void beginDraw() override;
	void endDraw() override;

private:

	void create_cube_map(const char* p_textures[6], GLuint* p_tex_cube);
};

#endif