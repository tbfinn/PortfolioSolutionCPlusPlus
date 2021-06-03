#include "IDetectorManager.h"

// This class is exported from the dll
class CDetectorManager : public IDetectorManager
{
protected:
	CDetectorManager() = default;
	~CDetectorManager() {
		delete singleton_;
	}

	static CDetectorManager* singleton_;

public:
	static CDetectorManager* GetInstance();
	void foo() override;
};


