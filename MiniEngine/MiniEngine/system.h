﻿#pragma once

extern HWND g_hWnd;

// ゲームの初期化
void InitGame(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow, const TCHAR* appName);
// ウィンドウメッセージをディスパッチ
bool DispatchWindowMessage();