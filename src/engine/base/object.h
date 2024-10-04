#pragma once
#include <vector>
class object {
public:
	object();
	const char* name;
	static void Destroy(object* o);
	virtual void Destroy();
	virtual void DestroyImmediate();

	bool GetWillBeDestroyed() const;
protected:

private:
	void setWillBeDestroyed();

	bool m_WillBeDestroyed = false;
};