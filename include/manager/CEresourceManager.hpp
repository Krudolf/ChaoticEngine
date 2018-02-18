 
#ifndef CERESOURCEMANAGER
#define CERESOURCEMANAGER

#include <vector>
#include <iostream>

#include "CEresource.hpp"

class CEResourceManager{
public:
	CEResourceManager();
	~CEResourceManager();

	CEResource* getResource(const char* p_name);

private:
	std::vector<CEResource*> m_resources;
};

#endif