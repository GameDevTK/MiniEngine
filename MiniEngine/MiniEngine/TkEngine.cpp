#include "stdafx.h"
#include "TkEngine.h"
#include "GraphicsEngine.h"

TkEngine* g_engine = nullptr;

TkEngine::~TkEngine()
{
  if (m_graphicsEngine)
  {
    delete m_graphicsEngine;
  }
}

void TkEngine::Init(HWND hwnd, UINT frameBufferWidth, UINT frameBufferHeight)
{
  // グラフィックスエンジンの初期化
  m_graphicsEngine = new GraphicsEngine();
  m_graphicsEngine->Init(hwnd, frameBufferWidth, frameBufferHeight);
 }

void TkEngine::BeginFrame()
{
  m_graphicsEngine->BeginRender();
}

void TkEngine::EndFrame()
{
  m_graphicsEngine->EndRender();
}
