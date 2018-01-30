
#ifndef TRANSFORM
#define TRANSFORM

class Transform: public Entity{
public:
	Transform();
	~Transform();

	void load();
	void release();

	void identity();
	void transpose();

	void translate(float p_x, float p_y, float p_z);
	void rotate(float p_x, float p_y, float p_z, float p_w);

	void beginDraw();
	void endDraw();

private:
	int** m_matrix;
}

#endif