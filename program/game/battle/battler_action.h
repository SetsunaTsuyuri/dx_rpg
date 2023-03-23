#pragma once

/// <summary>
/// �퓬�҂̍s��
/// </summary>
class BattlerAction {
public:

	/// <summary>
	/// �Ώ�
	/// </summary>
	enum class TargetType {

		/// <summary>
		/// ����
		/// </summary>
		Allies,

		/// <summary>
		/// �G
		/// </summary>
		Enemies
	};

	/// <summary>
	/// ����
	/// </summary>
	enum class EffectType {

		/// <summary>
		/// �_���[�W
		/// </summary>
		Damage,

		/// <summary>
		/// ��
		/// </summary>
		Healing
	};

	/// <summary>
	/// �ˑ��X�e�[�^�X
	/// </summary>
	enum  class DependentStatusType {
		
		/// <summary>
		/// ����
		/// </summary>
		Physical,

		/// <summary>
		/// ���@
		/// </summary>
		Magical
	};

	/// <summary>
	/// �Ώۂ̎�ނ��擾����
	/// </summary>
	/// <returns></returns>
	TargetType getTargetType();

	/// <summary>
	/// ���ʂ̎�ނ��擾����
	/// </summary>
	/// <returns></returns>
	EffectType getEffectType();

	/// <summary>
	/// �ˑ��X�e�[�^�X���擾����
	/// </summary>
	/// <returns></returns>
	DependentStatusType getDependentStatusType();

	float getPower();

private:

	/// <summary>
	/// �Ώ�
	/// </summary>
	TargetType targetType_ = TargetType::Allies;

	/// <summary>
	/// ����
	/// </summary>
	EffectType effectType_ = EffectType::Damage;

	/// <summary>
	/// �ˑ��X�e�[�^�X
	/// </summary>
	DependentStatusType dependentStatusType_ = DependentStatusType::Physical;

	/// <summary>
	/// �З�
	/// </summary>
	float power_ = 0.0f;
};
