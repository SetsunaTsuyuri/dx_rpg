#pragma once

/// <summary>
/// 戦闘者の行動
/// </summary>
class BattlerAction {
public:

	/// <summary>
	/// 対象
	/// </summary>
	enum class TargetType {

		/// <summary>
		/// 味方
		/// </summary>
		Allies,

		/// <summary>
		/// 敵
		/// </summary>
		Enemies
	};

	/// <summary>
	/// 効果
	/// </summary>
	enum class EffectType {

		/// <summary>
		/// ダメージ
		/// </summary>
		Damage,

		/// <summary>
		/// 回復
		/// </summary>
		Healing
	};

	/// <summary>
	/// 依存ステータス
	/// </summary>
	enum  class DependentStatusType {
		
		/// <summary>
		/// 物理
		/// </summary>
		Physical,

		/// <summary>
		/// 魔法
		/// </summary>
		Magical
	};

	/// <summary>
	/// 対象の種類を取得する
	/// </summary>
	/// <returns></returns>
	TargetType getTargetType();

	/// <summary>
	/// 効果の種類を取得する
	/// </summary>
	/// <returns></returns>
	EffectType getEffectType();

	/// <summary>
	/// 依存ステータスを取得する
	/// </summary>
	/// <returns></returns>
	DependentStatusType getDependentStatusType();

	float getPower();

private:

	/// <summary>
	/// 対象
	/// </summary>
	TargetType targetType_ = TargetType::Allies;

	/// <summary>
	/// 効果
	/// </summary>
	EffectType effectType_ = EffectType::Damage;

	/// <summary>
	/// 依存ステータス
	/// </summary>
	DependentStatusType dependentStatusType_ = DependentStatusType::Physical;

	/// <summary>
	/// 威力
	/// </summary>
	float power_ = 0.0f;
};
