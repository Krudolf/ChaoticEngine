
#ifndef CETRANSFORM
#define CETRANSFORM

#include <glm.hpp>
#include <CEentity.hpp>

/*La API de GLM la podeis ver aqui: http://glm.g-truc.net/0.9.8/api/modules.html*/
class CETransform : public CEEntity{
public:
	CETransform(int p_num);
	~CETransform();

	void beginDraw();
	void endDraw();

private:
	glm::mat4 m_matrix;
	int num;
};

#endif