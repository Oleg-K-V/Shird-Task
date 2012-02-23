/*�������� ���������, ������� ����������, 
�������� �� ��������� ��������� ��������� ����������. 
������� ���������� ��������� ���������: 
(), (())(), ()(), ((())), 
������������ � )(, ())((), (, )))), ((()).*/
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
	Stack* new_stack=new Stack;//������� ������� �� ���� ������� �����
	new_stack->last=stack;//����� �� �������� last ����� �� ��������� �������
	new_stack->data=ch;//������� ��� � ���� �������
	stack=new_stack;//�������� ����� ���� �������
	new_stack=NULL;//������� ���������� ��������
	return stack;//�������� �������� �� ���� �������
}
//---------------------------------------------------------
Stack* Stack_pop(Stack* stack)
{
	Stack* del_stack;
	//��� ������ ���� �������� ��� � ������ �� ���� ��� �� �������
	del_stack=stack;//������ ������ ����� ��� ������� ��������
	stack=stack->last;//����� ��������� ��������� �� ��������� �������
	delete del_stack;//�������� ������
	del_stack=NULL;//�������� ����
	return stack;//�������� ��������
}
//---------------------------------------------------------
Stack* clear(Stack * stack)
{
	if (stack==NULL)
		return NULL;//���� ���� ��� ������ �������
	Stack* del_stack;
	del_stack=stack;//������ ������ ����� ��� ������� ��������
	while(true)
	{
		if (stack->last!=NULL)//��������� �� �� ��������� ���� ����
		{
			del_stack=stack;//������ ������ ����� ��� ������� ��������
			stack=stack->last;//����� ��������� ��������� �� ��������� �������
			delete del_stack;//�������� ������
		}
		else 
		{
			delete stack;//�������� ������
			return NULL;//�������� ��������
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
	{//������� ��� ���� �� ������� 'Q'
		if (s=='(')
			StackToken=Stack_push(StackToken,s);//�������� ����� ��������� �����
		else if (s==')')
		{
			if (StackToken==NULL)//��������� �� ���� �� ������
			{
				std::cout<<"Wedeno zabagato ')' dujok\n";
				break;
			}
			StackToken=Stack_pop(StackToken);//�������� ������� �����
		}
		else if (s==(char)'Q')//��������� �� �� ������� ��������
		{
			if (StackToken==NULL)//��������� �� ���� �������
				std::cout<<"Wse wedeno pravelno\n";
			else
				std::cout<<"Wedeno zabagato '(' dujok\n";
			break;
		}
	}
	StackToken=clear(StackToken);//������ ����
	keep_window_open();
}
