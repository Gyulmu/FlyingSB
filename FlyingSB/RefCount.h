#pragma once

class RefCount
{
protected:
	RefCount() {}
	virtual ~RefCount() = 0 {}

public:
	void AddRef() { ++m_ref; }
	void Release() 
	{
		--m_ref;

		if (!m_ref)
			delete this;
	}

private:
	int m_ref = 1;
};