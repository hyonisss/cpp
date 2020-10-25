#include <string.h>
#include "MString.h"

MString::MString()
{
	m_str = (char *)"";
}
MString::MString(const char * str)
{
	size_t len;
	len = ::strlen(str);
	if (len == 0) m_str = (char *)"";
	else
	{
		m_str = new char[++len];
		::strcpy_s(m_str, len, str);
	}
}
MString::~MString()
{
	if (*m_str != '\0') delete[] m_str;
}
const char * MString::GetString(void) const
{
	return m_str; // char * imsi = m_str;
}

MString & MString::operator =(const MString &rstr)
{
	size_t len;
	if (this == &rstr) return *this; //실제 호출한 object의 주소와 인수로 전달된 object의 주소가 같다면 아무 작업X
	if (*m_str != '\0') delete[] m_str; // 복사 받을 object에 이전 값이 있다면 우선 지우기
	len = ::strlen(rstr.m_str);
	if (len == 0) m_str = (char *)""; //인수로 전달된 object가 비어있다면
	else
	{
		m_str = new char[++len];
		::strcpy_s(m_str, len, rstr.m_str);
		return *this;
	}
}
