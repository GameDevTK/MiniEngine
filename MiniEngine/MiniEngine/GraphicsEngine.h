#pragma once

#include <d3d12.h>
#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include "RenderContext.h"

// DirectX12に依存するグラフィックスエンジン
class GraphicsEngine {
public:
  // デストラクタ
  ~GraphicsEngine();

  // 初期化
  // DirectX12の初期化が行われます
  bool Init(HWND hwnd, UINT frameBufferWidth, UINT frameBufferHeight);

  // レンダリング開始
  // 1フレームのレンダリングの開始時に呼び出す
  void BeginRender();

  // レンダリング終了
  // 1フレームのレンダリングの終了時に呼び出す
  void EndRender();

  // D3Dデバイス取得
  ID3D12Device5* GetD3DDevice()
  {
    return m_d3dDevice;
  }

  // バックバッファの番号を取得
  UINT GetBackBufferIndex() const
  {
    return m_frameIndex;
  }

  // コマンドキューを取得
  ID3D12CommandQueue* GetCommandQueue() const
  {
    return m_commandQueue;
  }

  // コマンドリストを取得
  ID3D12GraphicsCommandList4* GetCommandList() const
  {
    return m_commandList;
  }

  // CBR_SRVのディスクリプタのサイズを取得
  UINT GetCbrSrvDescriptorSize() const
  {
    return m_cbrSrvDescriptorSize;
  }

  // サンプラのディスクリプタヒープサイズを取得
  UINT GetSamplerDescriptorSize() const
  {
    return m_samplerDescriptorSize;
  }

  // レンダリングコンテキストを取得
  RenderContext& GetRenderContext()
  {
    return m_renderContext;
  }

  // フレームバッファの幅を取得
  UINT GetFrameBufferWidth() const
  {
    return m_frameBufferWidth;
  }

  // フレームバッファの高さを取得
  UINT GetFrameBufferHeight() const
  {
    return m_frameBufferHeight;
  }

  // レンダリングターゲットをフレームバッファに変更する
  void ChangeRenderTargetToFrameBuffer(RenderContext& rc);

  // 現在のフレームバッファのレンダリングターゲットを取得
  D3D12_CPU_DESCRIPTOR_HANDLE GetCurrentFrameBufferRTV() const
  {
    return m_currentFrameBufferRTVHandle;
  }

  // フレームバッファへの描画時に使用されているデプスステンシルビューを取得
  D3D12_CPU_DESCRIPTOR_HANDLE GetCurrentFrameBufferDSV() const
  {
    return m_currentFrameBufferDSVHandle;
  }

  // 描画の完了待ち
  void WaitDraw();

private:
  ID3D12Device5* m_d3dDevice; //D3Dデバイス
  ID3D12CommandQueue* m_commandQueue; // コマンドキュー
  ID3D12GraphicsCommandList4* m_commandList;  //コマンドリスト

  RenderContext m_renderContext;
  D3D12_CPU_DESCRIPTOR_HANDLE m_currentFrameBufferRTVHandle;
  D3D12_CPU_DESCRIPTOR_HANDLE m_currentFrameBufferDSVHandle;

  UINT m_cbrSrvDescriptorSize;
  UINT m_samplerDescriptorSize;

  // GPUとの同期で使用する変数
  UINT m_frameIndex = 0;
  UINT64 m_fenceValue = 0;
  UINT m_frameBufferWidth = 0;  // フレームバッファの幅
  UINT m_frameBufferHeight = 0; // フレームバッファの高さ
  


};
extern GraphicsEngine* g_graphicsEngine;


