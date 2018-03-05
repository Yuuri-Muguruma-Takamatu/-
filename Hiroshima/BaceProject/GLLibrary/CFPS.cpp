#include "CFPS.h"

//１秒間のカウント数
LARGE_INTEGER CFPS::freq;
//前フレームのカウント数
LARGE_INTEGER CFPS::time_buf;
int CFPS::fps;
int CFPS::m_Setfps = 60;
float CFPS::deltaTime;

void CFPS::Init(){
	//時間計測用
	//システムの１秒間のカウント数（周波数）を取得
	QueryPerformanceFrequency(&freq);
	//現在のシステムのカウント数を取得
	QueryPerformanceCounter(&time_buf);
}


int CFPS::GetTimeCnt() {
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart/(freq.QuadPart/ m_Setfps);
}void CFPS::Wait() {
	//freq.QuadPart　	1秒当たりのカウント数（固定）
	//time.QuadPart　	今のカウント数
	//time_buf.QuadPart　前回のカウント数

	//上記の3つの情報から、ここで前回呼び出し時より1/60秒経つまで待機する

	LARGE_INTEGER time;
	//前フレームと今のカウントの差が1/60秒未満ならループ
	do{
		//現在のシステムのカウント数を取得
		QueryPerformanceCounter(&time);

		//　今のカウント　前回のカウント　 < 1秒当たりのカウント数を60で割る(1/60秒当たりのカウント数)
	}while(time.QuadPart-time_buf.QuadPart < freq.QuadPart / m_Setfps);

	fps = (int)(freq.QuadPart/(time.QuadPart-time_buf.QuadPart));
	deltaTime = ((time.QuadPart - time_buf.QuadPart) / (float)freq.QuadPart);
	time_buf = time;

}

void CFPS::SetFPS(int fps)
{
	m_Setfps = fps;
}
