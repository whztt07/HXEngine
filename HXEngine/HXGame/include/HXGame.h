#pragma once
#include "HXPaintListener.h"
#include "HXInputListener.h"
#include "HXDisplayListener.h"

using namespace HX3D;
class HXGame : public HXPaintListener, public HXInputListener , public HXDisplayListener
{
public:
	HXGame();
	~HXGame();

	void CreateGameScene();
	//virtual void OnUpdate();
	virtual void OnPaint();
	virtual void OnDisplay();
	virtual void OnViewPortResize(int nScreenWidth, int nScreenHeight);

	virtual void OnKeyDown(int msg);
	virtual void OnKeyUp(int msg);
};

