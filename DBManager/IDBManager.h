/**
  * File: IDBManager.h
  *
  * Author:  Timothy B. Finn (tbf.lodi@gmail.com)
  * Date:     Spring 2021
  * Project:   Portfolio Project
  *
  * Summary of File:
  *
  *
  *
  */
#pragma once
#ifdef DBMANAGER_EXPORTS
#define DBMANAGER_API __declspec(dllexport)
#else
#define DBMANAGER_API __declspec(dllimport)
#endif

class IDBManager
{
public:
	virtual void foo() = 0;
};

DBMANAGER_API IDBManager* GetDbManagerInstance();