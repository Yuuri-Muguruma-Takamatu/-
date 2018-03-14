/*!
@brief	�G�Ǘ��N���X hpp
@author	s.namizashi
**/

#ifndef __MAP_MANAGER__
#define __MAP_MANAGER__

#include "Include.h"

#include "map.h"

class CMapManager
{
private:
	static CMapManager* mp_Instance;
	CMapControl *m_map;
	//int			m_Elapsed;
	/// �R���X�g���N�^
	CMapManager();
public:
	/// �f�X�g���N�^
	~CMapManager();

	static CMapManager* GetInstance();
	static void ClearInstance();

	/*!
	@brief	����������
	**/
	void Init(CMapControl *map);

	/*!
	@brief	�I������
	**/
	void Finish();

	/*!
	@brief	�G�̃��X�g�擾
	**/
	CMapControl* GetPlayerAdress() const;

	/*!
	@brief	�X�V����
	**/
	void Update();

	//���s�����̎󂯓n��
};

#endif	// #ifndef __ENEMY_MANAGER_HPP__