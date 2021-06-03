#include "IRobotManager.h"

// This class is exported from the dll
class ROBOTMANAGER_API CRobotManager : public IRobotManager
{
protected:
	CRobotManager() = default;
	~CRobotManager() {
		delete singleton_;
	}

	static CRobotManager* singleton_;

public:
	static CRobotManager* GetInstance();
	void foo() override;
};
