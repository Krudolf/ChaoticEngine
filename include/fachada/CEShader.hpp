 
#ifndef CE_SHADER
#define CE_SHADER

#include <glew.h>
#include <vector>

class CEShader;

class CEShaderProgram{
public:
	CEShaderProgram(const char*	p_pathVertex, const char* p_pathFragment);
	~CEShaderProgram();

	void	loadShader(const char* p_pathVertex, const char* p_pathFragment);
	void 	useShaderProgram(GLuint p_shader);

	GLuint 	getShaderProgram(int p_iterator){ return m_shaderProgram[p_iterator]; }

private:
	CEShader*	m_shader;
	std::vector<GLuint>	m_shaderProgram;
};

#endif
