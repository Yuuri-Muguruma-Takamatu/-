
#include "TaskManager.h"
#include "CPlayer.h"
void main() {
	//一回だけの処理
	TaskManager::m_instan = new TaskManager();
	for (int i = 0; i < 10; i++) {
		new Player();
	}
	//ループ処理
	while (1) {
		TaskManager::m_instan->Update();
	}
}