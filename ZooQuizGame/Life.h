#pragma once

#include <iostream>
#include <string>

enum class LifeType
{
	LT_NULL = 0, LT_ANIMAL, LT_PLANT
};

class Life
{
public:
	Life(void) {}
	Life(const std::string& name, LifeType nType, const std::string& sciName, const std::string& family, const std::string& home)
	{
		setParam(name, nType, sciName, family, home);
	}
	~Life() {}

	std::string getName(void) const { return m_name; }
	LifeType getType(void) const { return m_nType; }
	std::string getSciName(void) const { return m_sciName; }
	std::string getFamily(void) const { return m_family; }
	std::string getHome(void) const { return m_home; }
	void setParam(const std::string& name, LifeType nType, const std::string& sciName, const std::string& family, const std::string& home)
	{
		m_name = name;
		m_nType = nType;
		m_sciName = sciName;
		m_family = family;
		m_home = home;
	}

	// 프로퍼티를 접근하지 않는 메소드는 정적 메소드로 선언; 함수 선언 앞에 static을 추가
	static std::string toStr(LifeType nType);

private:
	std::string m_name;
	LifeType m_nType = LifeType::LT_NULL;
	std::string m_sciName;
	std::string m_family;
	std::string m_home;
};

inline std::ostream& operator<<(std::ostream& stream, const Life& life)
{
	// 정적 메소드는 접근할 때 클래스명::멤버명을 사용
	stream << life.getName() << "는 " << Life::toStr(life.getType()) << "입니다. ";
	stream << "학명은 " << life.getSciName() << "이고, 계통은 " << life.getFamily() << "입니다. ";
	stream << life.getName() << "는 " << life.getHome() << "에 서식하고 있습니다.";
	return stream;
}

inline std::string Life::toStr(LifeType nType)
{
	switch (nType)
	{
	case LifeType::LT_ANIMAL: return "동물";
	case LifeType::LT_PLANT: return "식물";
	default: return "불분명";
	}
}