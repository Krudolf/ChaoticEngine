
#include <../include/transform.hpp>

Transform::Transform() : Entity(){}

Transform::~Transform(){}

int*** Transform::load(){
	int*** t_matrix = new int**[4];
    for(int i = 0; i < 4; i++)
    	t_matrix[i] = new int*[4];

    return t_matrix;
}

int Transform::release(int*** p_matrix){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            delete p_matrix[i][j];
        }
        delete[] p_matrix[i];
    }
    delete[] p_matrix;
}

void Transform::beginDraw(){}
void Transform::endDraw(){}