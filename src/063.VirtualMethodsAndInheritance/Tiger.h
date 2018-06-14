#pragma once
class Tiger : public Cat, public Lion
{
public:
	Tiger();
	~Tiger();

	virtual void Say();
};

