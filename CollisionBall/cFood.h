#pragma once
#include "cCircle.h"
class cFood :
	public MyEngine::cCircle
{
public:
	cFood();
	~cFood();
	unsigned int m_tag; //��ǩ
	POINT m_worldPos;  //��������
};