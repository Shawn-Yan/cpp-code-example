/********************************************************************
	
    filename: 	数据类型之间的转换.cpp
	purpose:	介绍几种数据类型之间转换的方法

*********************************************************************/

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void int_str();
void double_str();
void complex_str();

template<typename T> string to_str(T val)
{
	ostringstream oss;
	oss<<val;
	return oss.str();
}

int main(int argc, char* argv[])
{
// 	int_str();
//  double_str();
//  complex_str();

	string strFromInt = to_str(10);
	cout<<strFromInt<<endl;
	string strFromDouble = to_str(3.1415926);
	cout<<strFromDouble<<endl;
	return 0;
}

void int_str()
{
	cout<<endl<<"int_str fucntion #######################"<<endl;
	int i = 10;
	char szBuf[10] = "";
	string strRel;

    //使用C转换函数族进行转换
	cout<<"Using itoa and atoi:-----------------"<<endl;
	itoa(i, szBuf, 10);
	cout<<"itoa: szBuf = "<<szBuf<<endl;
	i = 0;
	i = atoi(szBuf);
	cout<<"atoi: i = "<<i<<endl;

	//使用snprintf进行转换
	cout<<endl<<"Using _snprintf:----------------"<<endl;
	i = 20;
	memset(szBuf, 0, sizeof(szBuf));
	_snprintf(szBuf, sizeof(szBuf), "%d", i);
	cout<<"_snprintf: szBuf = "<<szBuf<<endl;
	i = 0;
	sscanf(szBuf,"%d",&i);
	cout<<"sscanf: i = "<<i<<endl;
	
	//使用stringstream
	cout<<endl<<"Using stringstream:----------------"<<endl;
	i = 30;
	ostringstream oss;
	oss<<i;
	strRel = oss.str();
	cout<<"ostringstream: strRel = "<<strRel<<endl;
	i = 0;
	istringstream iss(strRel);
	iss>>i;
	cout<<"istringstream: i = "<<i<<endl;
}

void double_str()
{
	cout<<endl<<"double_str fucntion#######################"<<endl;
	double d = 3.1415926;
	char szBuf[18] = "";
	string strRel;
    //使用C转换函数族进行转换
	cout<<"Using _gcvt and strtod:-----------------"<<endl;
	_gcvt(d, 9, szBuf);
	cout<<"_gcvt: szBuf = "<<szBuf<<endl;
	d = 0;
	char* stopstring;
	d = strtod(szBuf, &stopstring);
	cout<<"strtod: d = "<<d<<endl;

	//使用snprintf进行转换
	cout<<endl<<"Using sprintf:----------------"<<endl;
	d = 6.1415926;
	memset(szBuf, 0, sizeof(szBuf));
	_snprintf(szBuf, sizeof(szBuf), "%f", d);
	cout<<"sprintf: szBuf = "<<szBuf<<endl;
	sscanf(szBuf, "%f", &d);
	cout<<"sscanf: d = "<<d<<endl;
	
	//使用stringstream
	cout<<endl<<"Using stringstream:----------------"<<endl;
	d = 9.1415926;
	ostringstream oss;
	oss<<d;
	strRel = oss.str();
	cout<<"ostringstream: strRel = "<<strRel<<endl;
	d = 0;
	istringstream iss(strRel);
	iss>>d;
	cout<<"istringstream: d = "<<d<<endl;
}

void complex_str()
{
	cout<<endl<<"complex_str fucntion#######################"<<endl;
	int iAge = 25;
	float fPayment = 3.25;
	string strName ="Wang";
	char szBuf[100] = "";
	string strRel;
    //使用C转换函数族进行转换
	cout<<"Using C Data-Conversion functions:-----------------"<<endl;
	char szTemp[100];
	strcpy(szBuf,"Age= ");
	itoa(iAge, szTemp, 10);
	strcat(szBuf, szTemp);
	strcat(szBuf," ,Payment= ");
    _gcvt(fPayment, 4, szTemp);
	strcat(szBuf,szTemp);
	strcat(szBuf," ,Name= ");
	strcat(szBuf, strName.c_str());
	cout<<"szBuf = "<<szBuf<<endl;
	cout<<"使用C转换函数族很难从复杂字符串转换回来了"<<endl;

	//使用snprintf进行转换
	cout<<endl<<"Using sprintf:----------------"<<endl;
	memset(szBuf, 0, sizeof(szBuf));
	_snprintf(szBuf, sizeof(szBuf), "Age = %d, Payment = %f, Name = %s",iAge,fPayment,strName.c_str());
	cout<<"sprintf: szBuf = "<<szBuf<<endl;
	iAge = 0;
	fPayment = 0.0;
	memset(szTemp, 0, sizeof(szTemp));
	sscanf(szBuf,"Age = %d, Payment = %f, Name = %s",&iAge,&fPayment,&szTemp);
	strName = szTemp;
	cout<<"sscanf: Age = "<<iAge<<",Payment="<<fPayment<<",name="<<strName<<endl;
	
	//使用stringstream
	cout<<endl<<"Using stringstream:----------------"<<endl;
	ostringstream oss;
	oss<<"Age = "<<iAge<<", Payment = "<<fPayment<<", Name = "<<strName;
	strRel = oss.str();
	cout<<"ostringstream: strRel = "<<strRel<<endl;
	iAge = 0;
	fPayment = 0.0;
	strName = "";
	istringstream iss(strRel);
	string strTemp;
	iss>>strTemp>>strTemp>>iAge>>strTemp>>strTemp>>strTemp>>fPayment
		>>strTemp>>strTemp>>strTemp>>strName;

	cout<<"istringstream: Age = "<<iAge<<",Payment="<<fPayment<<",name="<<strName<<endl;
}
