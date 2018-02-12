
#ifndef CETRANSFORM
#define CETRANSFORM

#include <glm.hpp>
#include <CEentity.hpp>

/*La API de GLM la podeis ver aqui: http://glm.g-truc.net/0.9.8/api/modules.html*/
class CETransform : public CEEntity{
public:
	CETransform(int p_num);
	~CETransform();

    void        loadIdentity();
    void        loadMatrix(glm::mat4 p_matrix);
    void        showMatrix();
    void        transpose();
    glm::mat4   transpose(glm::mat4 p_matrix);

    void        translate(float p_tx, float p_ty, float p_tz);
    void        rotate(float p_rx, float p_ry, float p_rz);
    void        scale (float p_sx, float p_sy, float p_sz);

	void        beginDraw();
	void        endDraw();

private:
	glm::mat4 m_matrix;
	int m_num;
};

#endif