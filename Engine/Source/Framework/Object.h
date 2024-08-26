#pragma once
#include <string>
#include "../Core/Serializable.h"

#define CLASS_DECLARATION(class) \
	static const char * GetTypeName() { return #class; }\
	virtual void Read(const json_t& value);\
	virtual void Write(json_t& value);
#define FACTORY_REGISTER(className)\
	class Register##className\
	{\
	public:\
		Register##className()\
		{\
		Factory::Instance().Register<className>(#className);\
		}\
	};\
	static Register##className register_instance;

#define CLASS_PROTOTYPE(classname) \
	virtual std::unique_ptr<Object> Clone() \
	{\
		return std::make_unique<classname>(*this);\
	}


class Object: public Serializable
{
public:
	Object() = default;
	Object(const std::string& name) : name{ name } {}
	virtual ~Object() = default;

	virtual std::unique_ptr<Object> Clone() = 0;

	CLASS_DECLARATION(Object);

	virtual void Initialize() = 0;
	virtual void Activate() { active = true; }
	virtual void Deactivate() { active = false; }

	

public:
	std::string name;
	bool active = true;
};