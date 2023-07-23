// ModifyInfo.h
#pragma once
class CModifyInfo
{
public:
	enum class eSource { None = 0, BayWindow, Beam };
	CModifyInfo(eSource source_) : source(source_) {}
	eSource source;
};