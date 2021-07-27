#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	short R;
	cin >> R;
	__asm {
		mov ax, 1; ax = 1
		mov bx, 1; bx = 1
		mov dx, 0; результат
	begin_loop_1:
	begin_loop_2:
		push ax; кладем в стэк ax
		push bx; кладем в стэк bx
		imul ax, ax; ax^2
		imul bx, bx; bx^2
		add ax, bx; ax^2 + bx^2 
		mov bx, R; bx = R
		imul bx, bx; R^2
		cmp ax, bx; сравниваем R^2 и (ax^2 + bx^2)
			jle loop_ ;
	loop_:
		inc dx;

		pop bx;
		pop ax;
		
		inc ax;
		cmp ax, R;
		jle begin_loop_1;
		
		mov ax, 1;

		inc bx;
		cmp bx, R;
		jle begin_loop_2;
		jmp END;
		
	END:
		imul dx, 4; ответ умножаем на 4, потому что нашли результат для 1 / 4 окружности(кроме a)
			inc dx; центр(0, 0)
			mov ax, R;
			imul ax, 4; точки с осей
			add dx, ax;
	}
}
