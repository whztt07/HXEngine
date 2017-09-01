#include "..\include\HXResourceManager.h"
#include "HXMesh.h"
#include "HXMaterial.h"
#include "HXBitmap.h"

namespace HX3D
{
	HXResourceManager* HXResourceManager::m_pInstance = NULL;

	HXResourceManager::HXResourceManager()
	{
	}


	HXResourceManager::~HXResourceManager()
	{
		for (std::map<std::string, HXMesh*>::iterator itr = meshMap.begin(); itr != meshMap.end(); itr++)
		{
			delete(itr->second);
		}
		meshMap.clear();

		for (std::map<std::string, HXMaterial*>::iterator itr = materialMap.begin(); itr != materialMap.end(); itr++)
		{
			delete itr->second;
		}
		materialMap.clear();

		for (std::map<std::string, HXBitmap*>::iterator itr = bitmapMap.begin(); itr != bitmapMap.end(); itr++)
		{
			delete itr->second;
		}
		bitmapMap.clear();
	}

	HXMesh* HXResourceManager::GetMesh(std::string strMeshName)
	{
		std::map<std::string, HXMesh*>::iterator itr = meshMap.find(strMeshName);
		if (itr != meshMap.end())
		{
			return itr->second;
		}
		else
		{
			HXMesh* pMesh = new HXMesh;
			if (pMesh->LoadMeshFile(strMeshName))
			{
				meshMap.insert(make_pair(strMeshName, pMesh));
				return pMesh;
			}
			else
			{
				delete pMesh;
				return NULL;
			}
		}
	}

	HXMaterial* HXResourceManager::GetMaterial(std::string strMaterialName)
	{
		std::map<std::string, HXMaterial*>::iterator itr = materialMap.find(strMaterialName);
		if (itr != materialMap.end())
		{
			return itr->second;
		}
		else
		{
			HXMaterial* pMaterial = new HXMaterial;
			if (pMaterial->LoadMaterialFile(strMaterialName))
			{
				materialMap.insert(make_pair(strMaterialName, pMaterial));
				return pMaterial;
			}
			else
			{
				delete pMaterial;
				return NULL;
			}
		}
	}

	HXBitmap* HXResourceManager::GetBitmap(std::string strBitmap)
	{
		std::map<std::string, HXBitmap*>::iterator itr = bitmapMap.find(strBitmap);
		if (itr != bitmapMap.end())
		{
			return itr->second;
		}
		else
		{
			HXBitmap* pBitmap = new HXBitmap;
			if (pBitmap->LoadBitmapFile(strBitmap))
			{
				bitmapMap.insert(make_pair(strBitmap, pBitmap));
				return pBitmap;
			}
			else
			{
				delete pBitmap;
				return NULL;
			}
		}
	}
}
