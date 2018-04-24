
#ifndef CESKYBOX
#define CESKYBOX

#include <CEentity.hpp>
#include <glew.h> 
#include <glm.hpp>

class CESkybox : public CEEntity{
public:
	CESkybox();
	virtual ~CESkybox();

	void makeSkyCube();

	void beginDraw() override;
	void endDraw() override;

private:

	void create_cube_map(const char* p_textures[6], GLuint* p_tex_cube);
	bool load_cube_map_side(GLuint p_texture, GLenum p_side_target, const char* p_file_name);
};

#endif