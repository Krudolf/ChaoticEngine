
#include <iostream>

#include "../../include/manager/CEshader.hpp"
#include "../../include/fachada/CEShader.hpp"

CEShaderProgram::CEShaderProgram(const char* p_pathVertex, const char* p_pathFragment){
	m_shader = new CEShader();

	m_pathVertex 	= p_pathVertex;
	m_pathFragment 	= p_pathFragment;

	loadShader();
	useShaderProgram(m_shaderProgram);
}

CEShaderProgram::~CEShaderProgram(){}

void CEShaderProgram::loadShader(){
	m_shaderProgram = m_shader->LoadShader(m_pathVertex, m_pathFragment);
}

void CEShaderProgram::useShaderProgram(GLuint p_shader){
	m_shader->useShader(p_shader);
}

GLuint CEShaderProgram::getShaderProgram(){
	return m_shaderProgram;
}
