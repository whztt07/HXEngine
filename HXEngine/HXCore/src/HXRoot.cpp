#include "..\include\HXRoot.h"
#include "HXGLRenderSystem.h"
#include "HXGDIRenderSystem.h"

namespace HX3D
{
	HXRoot* HXRoot::m_pInstance = NULL;

	HXRoot::HXRoot():m_pRenderSystem(NULL)
	{
	}

	HXRoot::~HXRoot()
	{
	}

	void HXRoot::Initialize(ERenderSystem rs)
	{
		switch (rs)
		{
		case RenderSystem_GDI:
			m_pRenderSystem = new HXGDIRenderSystem();
			break;
		case RenderSystem_GL:
			m_pRenderSystem = new HXGLRenderSystem();
			break;
		case RenderSystem_D3D:
			break;
		default:
			break;
		}
	}

	void HXRoot::CreateRenderWindow(std::string strName, int nWidth, int nHeight, bool bFullScreen)
	{
		if (m_pRenderSystem)
		{
			m_pRenderSystem->CreateRenderWindow(strName, nWidth, nHeight, bFullScreen);
		}
	}

	void HXRoot::SetDisplayListener(HXDisplayListener* pDisplayListener)
	{
		if (m_pRenderSystem)
		{
			m_pRenderSystem->SetDisplayListener(pDisplayListener);
		}
	}

	void HXRoot::MainLoop()
	{
		if (m_pRenderSystem)
		{
			m_pRenderSystem->MainLoop();
		}
	}

	HXRenderSystem* HXRoot::GetRenderSystem()
	{
		return m_pRenderSystem;
	}
}