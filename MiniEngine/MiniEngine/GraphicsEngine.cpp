#include "stdafx.h"
#include "GraphicsEngine.h"

GraphicsEngine::~GraphicsEngine()
{
  WaitDraw();
  
}

bool GraphicsEngine::Init(HWND hwnd, UINT frameBufferWidth, UINT frameBufferHeight)
{


  return false;
}

void GraphicsEngine::BeginRender()
{

}

void GraphicsEngine::EndRender()
{
}

void GraphicsEngine::ChangeRenderTargetToFrameBuffer(RenderContext& rc)
{
}

void GraphicsEngine::WaitDraw()
{
  // 描画終了待ち
  // Signal and increment the fence value
  const UINT64 fence = m_fenceValue;
}
