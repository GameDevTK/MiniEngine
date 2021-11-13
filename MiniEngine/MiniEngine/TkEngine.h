#pragma once

class GraphicsEngine;


// DirectX12に依存するグラフィックスエンジン
class TkEngine {
public:
  // デストラクタ
  ~TkEngine();

  // フレームの開始時に呼ばれる処理
  void BeginFrame();

  // フレームの終了時に呼ばれる処理
  void EndFrame();

  // ゲームエンジンの初期化
  void Init(HWND hwnd, UINT frameBufferWidth, UINT frameBufferHeight);
  

private:
  GraphicsEngine* m_graphicsEngine = nullptr; // グラフィックスエンジン


};

extern TkEngine* g_engine;  // TKエンジン