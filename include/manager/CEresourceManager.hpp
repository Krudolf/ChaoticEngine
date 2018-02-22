 
#ifndef CERESOURCEMANAGER
#define CERESOURCEMANAGER

#include <vector>
#include <iostream>

#include "CEresource.hpp"

class CEResourceManager{
public:
	static CEResourceManager* instance();

	CEResourceManager();
	~CEResourceManager();

	CEResource* getResource(const char* p_name);
	void deleteResources();
	void showResources();

private:
	static CEResourceManager* m_instance;

	std::vector<CEResource*> m_resources;
};

#endif