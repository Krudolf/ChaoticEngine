
#ifndef TRANSFORM
#define TRANSFORM

#include <entity.hpp>

class Transform : public Entity{
public:
	Transform();
	~Transform();

	int*** load();
	int release(int*** p_matrix);

	void identity();
	void transpose();

	void translate(float p_x, float p_y, float p_z);
	void rotate(float p_x, float p_y, float p_z, float p_w);

	void beginDraw();
	void endDraw();

private:
	int*** m_matrix;
};

#endif