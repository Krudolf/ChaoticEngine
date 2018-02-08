
#ifndef TRANSFORM
#define TRANSFORM

#include <glm.hpp>
#include <entity.hpp>

/*La API de GLM la podeis ver aqui: http://glm.g-truc.net/0.9.8/api/modules.html*/
class Transform : public Entity{
public:
	Transform(int p_num);
	~Transform();

	void beginDraw();
	void endDraw();

private:
	glm::mat4 m_matrix;
	int num;
};

#endif