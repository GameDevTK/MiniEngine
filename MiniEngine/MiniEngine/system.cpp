#include "stdafx.h"
#include "system.h"
#include "GraphicsEngine.h"

HWND g_hWnd = NULL;// ウィンドウハンドル

// メッセージプロシージャ
// hWndがメッセージを送ってきたウィンドウのハンドル
// msgがメッセージの種類
// wParamとlParamは引数
LRESULT CALLBACK MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  // 送られてきたメッセージで処理を分岐させる
  switch (msg)
  {
  case WM_DESTROY:
    delete g_engine;
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, msg, wParam, lParam);
  }

  return 0;
}


// ウィンドウの初期化
void InitWindow(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
  // ウィンドウクラスのパラメータを設定
  WNDCLASSEX wc =
  {
    sizeof(WNDCLASSEX), // 構造体のサイズ
    CS_CLASSDC, // ウィンドウのスタイル
    MsgProc,  // メッセージプロシージャ
    0,
    0,
    GetModuleHandle(NULL), // このクラスのためのウィンドウプロシージャがあるインスタンスハンドル
    NULL, // アイコンのハンドル
    NULL, // マウスカーソルのハンドル
    NULL, // ウィンドウの背景色
    NULL, // メニュー名
    appName, // ウィンドウクラスに付ける名前
    NULL
  };
  // ウィンドウクラスの登録
  RegisterClassEx(&wc);

  // ウィンドウの作成
  g_hWnd = CreateWindow(
    appName,  // 使用するウィンドウラクラス
    appName,  // ウィンドウの名前
    WS_OVERLAPPEDWINDOW,  // ウィンドウスタイル
    0,
    0,
    FRAME_BUFFER_W, // ウィンドウの幅
    FRAME_BUFFER_H, // ウィンドウの高さ
    NULL, // 親ウィンドウ
    NULL, // メニュー
    hInstance,  // アプリケーションのインスタンス
    NULL
  );

  ShowWindow(g_hWnd, nCmdShow);

}

// ゲームの初期化
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName)
{
  // ウィンドウを初期化
  InitWindow(hInstance, hPrevInstance, lpCmdLine, nCmdShow, appName);
  
  // TKエンジンの初期化
  g_engine = new TkEngine;
  g_engine->Init(g_hWnd, FRAME_BUFFER_W, FRAME_BUFFER_H);
}

// ウィンドウメッセージをディスパッチ
bool DispatchWindowMessage()
{
  MSG msg = { 0 };
  while (WM_QUIT != msg.message) {
    // ウィンドウからのメッセージを受け取る
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else
    {
      // ウィンドウメッセージが空
      break;
    }
  }
  return msg.message != WM_QUIT;
}
