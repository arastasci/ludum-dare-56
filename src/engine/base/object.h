#pragma once
#include <vector>
class object {
public:
	object();
	const char* name;
	static void Destroy(object* o);
	bool GetWillBeDestroyed() const;
protected:

private:
	void setWillBeDestroyed();

	bool m_WillBeDestroyed = false;
};