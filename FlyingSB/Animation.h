#pragma once
#include "RefCount.h"
#include <vector>

struct AnimationFrame;

class Animation : public RefCount
{
public:
	Animation();

private:
	virtual ~Animation() override;

public:
	void Initialize(const std::vector<AnimationFrame*>& frames);
	const std::vector<AnimationFrame*>& Frames() { return m_frame; }

private:
	std::vector<AnimationFrame*> m_frame;
};