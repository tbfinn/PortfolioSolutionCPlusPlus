#include "IRunManager.h"

// This class is exported from the dll
class RUNMANAGER_API CRunManager : public IRunManager
{
protected:
	CRunManager() = default;
	~CRunManager() {
		delete singleton_;
	}

	static CRunManager* singleton_;

public:
	static CRunManager* GetInstance();
	void foo() override;
};
