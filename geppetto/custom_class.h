#ifndef _GEPPETTO_CUSTOM_CLASS_H_
#define _GEPPETTO_CUSTOM_CLASS_H_

class Entity;

class CustomClass
{
public:
	CustomClass();
	~CustomClass();
	virtual void load(Entity* entity);
	virtual void update(Entity* entity);
};

#endif
