 
#ifndef CERESOURCE
#define CERESOURCE

class CEResource{
public:
	CEResource(){};
	virtual ~CEResource(){};

	const char* getName(){	return m_name;	};
	void setName(const char* p_name){	m_name = p_name;	};
	virtual bool loadFile(const char* p_name){};

protected:

private:
	const char* m_name;
};

#endif 
