#pragma once

//#ifdef FRAMEBASE_EXPORTS
//#define FRAMEBASE_API  __declspec(dllexport)
//#else
//#define FRAMEBASE_API  __declspec(dllimport)
//#endif
//
//#ifndef FRAMEBASE_EXPORTS
//#define FRAMEBASE_TEMPLATE
//#else //EXPORT
//#define FRAMEBASE_TEMPLATE __declspec(dllexport)
//#endif

//hh������Ϊ�˺�ϵͳ��������ֹĪ������ı�����󣬱���beginthreadex�Ҳ��������ֹ淶��ͻ��
WIN32_LEAN_AND_MEAN

#include "Net/PingUtil.h"
#include "File/DirMonitor.h"
#include "CmdLine.h"
#include "Event.h"
#include "FactoryBase.h"
#include "Img/GDIPHelper.h"
#include "File/IniFile.h"
#include "ThreadHelper.h"
#include "SimpleMemPool.h"
#include "SimpleTimer.h"
#include "Tray/TrayIcon.h"
#include "Tray/ToTray.h"
#include "Hardware/NetTraffic.h"
#include "Hardware/GPUusage.h"
#include "Hardware/DiskUsage.h"


#include "c_plus_plus_serializer.h"


//std::thread������XP
#define THREAD_BEGIN std::thread([&](){
#define  THREAD_END 	}).detach();


#define THREAD_BEGIN2 std::thread([=](){
#define  THREAD_END2 	}).detach();

//#define    THREAD_BEGIN(TypeName, ProcName) \
//	DWORD WINAPI TypeName##_Proc(LPVOID p) { \
//         p->TypeName##ProcName##_Proc(); \
//        return 0}; \
//
//
//#define    THREAD_END \
//
//HANDLE m_hThread = CreateThread(NULL, 0, &TypeName##_Proc, this, 0, NULL); \
//    CloseHandle(m_hThread); \

//#define ENABLE_MFC

#define  LAZY_CREATE_IF_NULL(RetClass, CreateClass, IntfName) \
	private: \
		RetClass* m_p##IntfName; \
	public: \
	    virtual RetClass* IntfName##() { \
		    if (!m_p##IntfName) { \
			   m_p##IntfName = new  CreateClass; } \
		 return m_p##IntfName; };

#define    DISABLE_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&);                \
    TypeName& operator=(const TypeName&)

/*��ʵ��
/TypeName() {}; ��ֹ�˹��캯�����岿�֣������Ҫ������ȥ��{}, Ȼ����CPP���Լ�ʵ�ֶ���

�÷���
���������֣�DECLARE_SINGLETON(����)���뾡����������Ϊ˽��
CPP���ʼ��Static������ IMPLEMENT_SINGLETON(����)
*/
#ifndef _MACRO_MAKE_SINGLETON
#define _MACRO_MAKE_SINGLETON

#define    DECLARE_SINGLETON(TypeName) \
	private: \
		static TypeName* g_pGlobal_##TypeName; \
	public: \
		static TypeName* GetInstance() { \
			if (!g_pGlobal_##TypeName) { \
				g_pGlobal_##TypeName = new TypeName; } \
			return g_pGlobal_##TypeName; }  \
		static void FreeInstance() { \
				delete  g_pGlobal_##TypeName; \
                g_pGlobal_##TypeName = NULL;  } \
		static void ReleaseInstance() { \
                g_pGlobal_##TypeName = NULL;  } \

#define    IMPLEMENT_SINGLETON(TypeName) \
	TypeName* TypeName::g_pGlobal_##TypeName = NULL;


#define    DECLARE_SINGLETON_WITH_NEW_PARAM1(TypeName, param1) \
	private: \
		static TypeName* g_pGlobal_##TypeName; \
	public: \
		static TypeName* GetInstance() { \
			if (!g_pGlobal_##TypeName) { \
				g_pGlobal_##TypeName = new TypeName(param1); } \
			return g_pGlobal_##TypeName; }  

#define    IMPLEMENT_SINGLETON(TypeName) \
	TypeName* TypeName::g_pGlobal_##TypeName = NULL;


#define    DECLARE_SINGLETON_WITH_NEW_PARAM2(TypeName, param1, param2) \
	private: \
		static TypeName* g_pGlobal_##TypeName; \
	public: \
		static TypeName* GetInstance() { \
			if (!g_pGlobal_##TypeName) { \
				g_pGlobal_##TypeName = new TypeName(param1, param2); } \
			return g_pGlobal_##TypeName; }  

#define    IMPLEMENT_SINGLETON(TypeName) \
	TypeName* TypeName::g_pGlobal_##TypeName = NULL;


#define    DECLARE_SINGLETON_WITH_NEW_PARAM3(TypeName, param1, param2, param3) \
	private: \
		static TypeName* g_pGlobal_##TypeName; \
	public: \
		static TypeName* GetInstance() { \
			if (!g_pGlobal_##TypeName) { \
				g_pGlobal_##TypeName = new TypeName(param1, param2, param3); } \
			return g_pGlobal_##TypeName; }  

#define    IMPLEMENT_SINGLETON(TypeName) \
	TypeName* TypeName::g_pGlobal_##TypeName = NULL;

#endif

template <class T>
struct TVector : public vector<T>
{
	bool contains(const T& v) const
	{
		for (auto& m : *this)
		{
			if (m == v)
				return true;
		}

		return false;
	};

	void append(const T& v)
	{
		this->push_back(v);
	}

	const T& at(UINT index)
	{
		assert(i < this->size())

			int i = 0;
		for (auto iter = this->begin(); iter != this->end(); ++iter)
		{
			if (i == index)
			{
				return *iter;
				break;
			}
			i++;
		}
	}
};

