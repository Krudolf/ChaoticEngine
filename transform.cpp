
#include <include/transform.hpp>

Transform::Transform(){}

Transform::~Transform(){}

Transform::load(){
	for(int i = 0; i < 4; i++){
		m_matrix[i] = new int*;
		for(int j = 0; j < 4; j++){
			m_matrix[i][j] = new int;
		}
	}
}

Transform::release(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			delete m_matrix[i][j];
		}
		delete m_matrix[i];
	}
}
