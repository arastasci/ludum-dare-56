#pragma once
#include <vector>
class Object {
public:
	Object();
	Object(const char* name);
	const char* name;
	virtual void Destroy();
	virtual void DestroyImmediate();

	bool GetWillBeDestroyed() const;
protected:

private:
	void setWillBeDestroyed();

	bool m_WillBeDestroyed = false;
};