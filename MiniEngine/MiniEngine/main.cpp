#include "stdafx.h"
#include "system.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
  // ゲームの初期化
  InitGame(hInstance, hPrevInstance, lpCmdLine, nCmdShow, TEXT("Game"));

  // ゲームループ
  while (DispatchWindowMessage())
  {

  }

  return 0;
}
