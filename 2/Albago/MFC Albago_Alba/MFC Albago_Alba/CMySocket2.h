#pragma once

// CMySocket2 명령 대상

class CMySocket2 : public CAsyncSocket
{
private:
	CDialog* m_pWnd;
	
public:
	CMySocket2();
	virtual ~CMySocket2();
	void SetParent(CDialog* pWnd);
	virtual void OnClose(int nErrorCode);
	virtual void OnAccept(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


