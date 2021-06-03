#include "IPlanManager.h"

// This class is exported from the dll
class PLANMANAGER_API CPlanManager : public IPlanManager
{
protected:
	CPlanManager() = default;
	~CPlanManager() {
		delete singleton_;
	}

	static CPlanManager* singleton_;

public:
	static CPlanManager* GetInstance();
	void foo() override;
};
