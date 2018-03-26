/* Simple Version */
class CMyString
{
public:
	CMyString(char* pData = NULL) { m_pData = pData; };
	CMyString(const CMyString& str) { m_pData = str.m_pData; };
	~CMyString(void);
	CMyString& CMyString::operator = (const CMyString& str) {
		if(this = &str)
			return *this;

		delete []m_pData;
		m_pData = NULL;
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);

		return *this;
	};

private:
	char* m_pData;
}


/* Complicate Version */
class CMyString
{
public:
	CMyString(char* pData = NULL) { m_pData = pData; };
	CMyString(const CMyString& str) { m_pData = str.m_pData; };
	~CMyString(void);
	CMyString& CMyString::operator = (const CMyString& str) {
		if(this != &str) {
			CMyString& strTemp(str);

			//swap strTemp.m_pData and this.m_pData
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = pTemp;
		}

		return *this;
	};

private:
	char* m_pData;
}
