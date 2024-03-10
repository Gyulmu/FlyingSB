#include "Animation.h"
#include "AnimationFrame.h"

Animation::Animation()
{
}

Animation::~Animation()
{
	std::vector<AnimationFrame*>::iterator iter;
	std::vector<AnimationFrame*>::iterator iterEnd = m_frame.end();

	for (iter = m_frame.begin(); iter != iterEnd; ++iter)
	{
		delete (*iter);
	}

}

void Animation::Initialize(const std::vector<AnimationFrame*>& frames)
{
	m_frame = frames;
}
