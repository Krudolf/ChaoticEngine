
#include <iostream>

#include "../../include/manager/CEshader.hpp"
#include "../../include/fachada/CEShader.hpp"

CEShaderProgram::CEShaderProgram(const char* p_pathVertex, const char* p_pathFragment){
	m_shader = new CEShader();

	loadShader(p_pathVertex, p_pathFragment);
	useShaderProgram(m_shaderProgram[0]);
}

CEShaderProgram::~CEShaderProgram(){}

void CEShaderProgram::loadShader(const char* p_pathVertex, const char* p_pathFragment){
	m_shaderProgram.push_back(m_shader->LoadShader(p_pathVertex, p_pathFragment));
}

void CEShaderProgram::useShaderProgram(GLuint p_shader){
	m_shader->useShader(p_shader);
}
