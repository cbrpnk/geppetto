#ifndef _ENGINE_CUSTOM_CLASS_H_
#define _ENGINE_CUSTOM_CLASS_H_

class Entity;

class CustomClass {
public:
	CustomClass();
	~CustomClass();
	virtual void load();
	virtual void update(Entity* entity);
};

#endif
