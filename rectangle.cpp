// rectangle.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <windows.h> 
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

void circuit(HDC hdc,HWND hwnd) {		//������
	RECT rt;
	char buf[100];
	SetBkColor(hdc, RGB(0, 0, 0));		//���� ����
	SetTextColor(hdc, RGB(255, 0, 0));
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	GetClientRect(hwnd, &rt);				//����������� ������� ������� ����
	sprintf (buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
	TextOutA(hdc, 10, 10, buf, strlen(buf));
	Rectangle(hdc, 40, 30, 120, 150);
	getch() != 27; 
	SelectPen(hdc, hOldPen);				// �������� � �������� ����������� ���������� �����
	DeletePen(hRedPen);						// ������� ������� �����
	hRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
}

void paint(HDC hdc,HWND hwnd) {			//�����������
	RECT rt;
	char buf[100];
	SetBkColor(hdc, RGB(0, 0, 0));		//���� ����
	SetTextColor(hdc, RGB(255, 0, 0));
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	GetClientRect(hwnd, &rt);				//����������� ������� ������� ����
	sprintf_s (buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
	TextOutA(hdc, 10, 10, buf, strlen(buf));
	Rectangle(hdc, 40, 30, 120, 150);
	getch() != 27;
	SelectPen(hdc, hOldPen);				// �������� � �������� ����������� ���������� �����
	SelectBrush(hdc, hOldBrush);			// ������� ������� ����
	DeletePen(hRedPen);						// ������� ������� �����
	hRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	DeleteBrush(hGreenBrush);				// ����������� �������� �����������
	hGreenBrush = CreateSolidBrush(RGB(0, 255, 255));
}

void embed(HDC hdc, HWND hwnd) {			//����������

	RECT rt;
	char buf[100];
	
		SetBkColor(hdc, RGB(0, 0, 0));											//���� ����
		SetTextColor(hdc, RGB(255, 0, 0));
		HPEN zRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HPEN zOldPen = SelectPen(hdc, zRedPen);
		HBRUSH zGreenBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH zOldBrush = SelectBrush(hdc, zGreenBrush);
		GetClientRect(hwnd, &rt);																			//����������� ������� ������� ����
		sprintf_s(buf, "������ ���� %d �� %d ��������", rt.right, rt.bottom);
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		Rectangle(hdc, 70, 30, 120, 150);
		SelectPen(hdc, zOldPen);																	// �������� � �������� ����������� ���������� �����
		SelectBrush(hdc, zOldBrush);														// ������� ������� ����
		DeletePen(zRedPen);																			// ������� ������� �����
		zRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
		DeleteBrush(zGreenBrush);															// ����������� �������� �����������
		zGreenBrush = CreateSolidBrush(RGB(0, 255, 255));

	getch() != 27;
	

}



void main() {
	HWND hwnd = GetConsoleWindow();      //�������������� ����
	HDC hdc = GetDC(hwnd);					//�������� �����������
	RECT rt;							//��������� � ������ left,top,right,buttom
	
	std::ifstream file1("coordinates1.txt");
	std::ifstream file2("coordinates2.txt");

	file1.is_open();
	file2.is_open();

	int x1, y1, x2, y2;
	int a, b, c, d;

	while (file1 >> x1 >> y1 >> x2 >> y2)
	{
		cout << "x1:" << x1 << "		y1:" << y1 << "		x2:" << x2 << "		y2:" << y2 << endl;
	}

	while (file2 >> a >> b >> c >> d) {
		cout << "a:" << a << "		b:" << b << "		c:" << c << "		d:" << d << endl;
	}











	//circuit(hdc, hwnd);
	//paint(hdc, hwnd);







	//embed(hdc,  hwnd);



	ReleaseDC(hwnd, hdc);
}
