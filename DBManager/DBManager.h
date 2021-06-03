#include "IDBManager.h"

// This class is exported from the dll
class DBMANAGER_API CDBManager : public IDBManager
{
protected:
	CDBManager() = default;
	~CDBManager() {
		delete singleton_;
	}

	static CDBManager* singleton_;

public:
	static CDBManager* GetInstance();
	void foo() override;
};

