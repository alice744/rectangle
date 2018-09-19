// rectangle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h> 
#include <windowsx.h>
#include <stdio.h>
#include <conio.h>

void circuit(HDC hdc,HWND hwnd) {		//контур
	RECT rt;
	char buf[100];
	SetBkColor(hdc, RGB(0, 0, 0));		//цвет фона
	SetTextColor(hdc, RGB(255, 0, 0));
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	GetClientRect(hwnd, &rt);				//определение размера области окна
	sprintf (buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	TextOutA(hdc, 10, 10, buf, strlen(buf));
	Rectangle(hdc, 40, 30, 120, 150);
	getch() != 27; 
	SelectPen(hdc, hOldPen);				// выбираем в контекст отображения предыдущую кисть
	DeletePen(hRedPen);						// удаляем зеленую кисть
	hRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
}

void paint(HDC hdc,HWND hwnd) {			//закрашенный
	RECT rt;
	char buf[100];
	SetBkColor(hdc, RGB(0, 0, 0));		//цвет фона
	SetTextColor(hdc, RGB(255, 0, 0));
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	GetClientRect(hwnd, &rt);				//определение размера области окна
	sprintf_s (buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	TextOutA(hdc, 10, 10, buf, strlen(buf));
	Rectangle(hdc, 40, 30, 120, 150);
	getch() != 27;
	SelectPen(hdc, hOldPen);				// выбираем в контекст отображения предыдущую кисть
	SelectBrush(hdc, hOldBrush);			// удаляем красное перо
	DeletePen(hRedPen);						// удаляем зеленую кисть
	hRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	DeleteBrush(hGreenBrush);				// освобождаем контекст отображения
	hGreenBrush = CreateSolidBrush(RGB(0, 255, 255));
}

void embed(HDC hdc, HWND hwnd) {			//вложеннный

	RECT rt;
	char buf[100];
	//SetBkColor(hdc, RGB(0, 0, 0));												//цвет фона
	//SetTextColor(hdc, RGB(255, 0, 0));
	//HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	//HPEN hOldPen = SelectPen(hdc, hRedPen);
	//HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	//HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	//GetClientRect(hwnd, &rt);														//определение размера области окна
	//sprintf_s(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
	//TextOutA(hdc, 10, 10, buf, strlen(buf));
	//Rectangle(hdc, 150, 150, 350, 450);
	
		SetBkColor(hdc, RGB(0, 0, 0));											//цвет фона
		SetTextColor(hdc, RGB(255, 0, 0));
		HPEN zRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
		HPEN zOldPen = SelectPen(hdc, zRedPen);
		HBRUSH zGreenBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH zOldBrush = SelectBrush(hdc, zGreenBrush);
		GetClientRect(hwnd, &rt);																			//определение размера области окна
		sprintf_s(buf, "Размер окна %d на %d пикселей", rt.right, rt.bottom);
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		Rectangle(hdc, 70, 30, 120, 150);
		SelectPen(hdc, zOldPen);																	// выбираем в контекст отображения предыдущую кисть
		SelectBrush(hdc, zOldBrush);														// удаляем красное перо
		DeletePen(zRedPen);																			// удаляем зеленую кисть
		zRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
		DeleteBrush(zGreenBrush);															// освобождаем контекст отображения
		zGreenBrush = CreateSolidBrush(RGB(0, 255, 255));

	getch() != 27;
	//SelectPen(hdc, hOldPen);				// выбираем в контекст отображения предыдущую кисть
	//SelectBrush(hdc, hOldBrush);			// удаляем красное перо
	//DeletePen(hRedPen);						// удаляем зеленую кисть
	//hRedPen = CreatePen(PS_SOLID, 5, RGB(0, 255, 0));
	//DeleteBrush(hGreenBrush);				// освобождаем контекст отображения
	//hGreenBrush = CreateSolidBrush(RGB(0, 255, 255));

}



void main() {
	HWND hwnd = GetConsoleWindow();      //индентификатор окна
	HDC hdc = GetDC(hwnd);					//контекст изображения
	RECT rt;							//структура с полями left,top,right,buttom
	
	circuit(hdc, hwnd);
	paint(hdc, hwnd);
	embed(hdc,  hwnd);



	ReleaseDC(hwnd, hdc);
}




/**
void main()
{
	// получаем идентификатор окна
	HWND hwnd = GetConsoleWindow();
	// получаем контекст отображения
	HDC hdc = GetDC(hwnd);
	RECT rt;
	char buf[100];
	// устанавливаем цвет фона 
	SetBkColor(hdc, RGB(0, 0, 0));
	// устанавливаем цвет текста
	SetTextColor(hdc, RGB(255, 0, 0));
	// создаем красное перо 
	HPEN hRedPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	// и выбираем его в контекст отображения, 
	// сохраняя предыдущее перо
	HPEN hOldPen = SelectPen(hdc, hRedPen);
	// создаем зеленую кисть 
	HBRUSH hGreenBrush = CreateSolidBrush(RGB(0, 255, 0));
	// и выбираем ее в контекст отображения,
	// сохраняя предыдущую кисть
	HBRUSH hOldBrush = SelectBrush(hdc, hGreenBrush);
	// выводим строку стандартными средствами
	printf("Graphics in Console Window.");
	do {
		// получаем размер окна
		GetClientRect(hwnd, &rt);
		// формируем выводимую строку
		sprintf(buf, "Размер окна %d на %d пикселей",
			rt.right, rt.bottom);
		// выводим строку графическими средствами
		TextOutA(hdc, 10, 10, buf, strlen(buf));
		// рисуем закрашенный эллипс
		Ellipse(hdc, 10, 30, rt.right-10, rt.bottom-10);
	} while (getch() != 27); // при нажатии любой клавиши 
							 // (кроме Esc) перерисовываем изображение, 
							 // изображение изменится, если изменились размеры окна,
							 // нажатие Esc – выход
							 // выбираем в контекст отображения предыдущее перо
	SelectPen(hdc, hOldPen);
	// выбираем в контекст отображения предыдущую кисть
	SelectBrush(hdc, hOldBrush);
	// удаляем красное перо
	DeletePen(hRedPen);
	// удаляем зеленую кисть
	DeleteBrush(hGreenBrush);
	// освобождаем контекст отображения
	ReleaseDC(hwnd, hdc);
}
**/