/*Написать программу, которая определяет, 
является ли введенная скобочная структура правильной. 
Примеры правильных скобочных выражений: 
(), (())(), ()(), ((())), 
неправильных — )(, ())((), (, )))), ((()).*/
#include <iostream>
struct Stack
{
	char data;
	Stack* last;
};
//---------------------------------------------------------
Stack* Start()
{
	return NULL;
}
//---------------------------------------------------------
Stack* Stack_push(Stack* stack,char ch)
{
	Stack* new_stack=new Stack;//виділяєм памятьь під нову вершину стека
	new_stack->last=stack;//кажем що вказівник last вказує на попередню вершину
	new_stack->data=ch;//записуєм дані в нову вершину
	stack=new_stack;//Присвоюю стеку нову вершину
	new_stack=NULL;//зануляє непотрібний вказвіник
	return stack;//повертаєм вказвіник на нову вершину
}
//---------------------------------------------------------
Stack* Stack_pop(Stack* stack)
{
	Stack* del_stack;
	//тут повина бути перевірка але я вважаю що вона тут не потрібна
	del_stack=stack;//зчитуєм адресу памяті яку потрібно звільнити
	stack=stack->last;//кажем вказівнику вказувати на попередній елемент
	delete del_stack;//звільняєм память
	del_stack=NULL;//зануляєм зміну
	return stack;//повертаєм значення
}
//---------------------------------------------------------
Stack* clear(Stack * stack)
{
	if (stack==NULL)
		return NULL;//якщо стек уже пустий виходим
	Stack* del_stack;
	del_stack=stack;//зчитуєм адресу памяті яку потрібно звільнити
	while(true)
	{
		if (stack->last!=NULL)//перевіряєм чи не вивільнили весь стек
		{
			del_stack=stack;//зчитуєм адресу памяті яку потрібно звільнити
			stack=stack->last;//кажем вказівнику вказувати на попередній елемент
			delete del_stack;//звільняєм память
		}
		else 
		{
			delete stack;//звільняєм память
			return NULL;//зануляєм вказвіник
		}
	}
}
//---------------------------------------------------------
void keep_window_open()
{
	std::cin.clear();
	char ch;
	std::cout<<"Wedit sumvol dla zavershena\n";
	std::cin>>ch;
}
//---------------------------------------------------------
int main()
{
	Stack *StackToken=NULL;
	std::cout<<"Dla zavershena vvody wedit sumwol 'Q'"<<std::endl;
	char s;
	while(std::cin>>s)
	{//Зчитуємо дані поки не введуть 'Q'
		if (s=='(')
			StackToken=Stack_push(StackToken,s);//створюєм новий екземпляр стеку
		else if (s==')')
		{
			if (StackToken==NULL)//перевіряєм чи стек не пустий
			{
				std::cout<<"Wedeno zabagato ')' dujok\n";
				break;
			}
			StackToken=Stack_pop(StackToken);//видаляєм елемент стеку
		}
		else if (s==(char)'Q')//перевіряєм чи не закінчли введення
		{
			if (StackToken==NULL)//перевіряєм чи стек порожній
				std::cout<<"Wse wedeno pravelno\n";
			else
				std::cout<<"Wedeno zabagato '(' dujok\n";
			break;
		}
	}
	StackToken=clear(StackToken);//очищаєм стек
	keep_window_open();
}
