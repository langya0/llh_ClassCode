#include<iostream>
using namespace std;
#include<assert.h>

typedef enum{ATOM,LIST}ElemTag;

typedef char AtomType;
struct GLNode
{
	ElemTag tag;
	union 
	{
		AtomType _atom;
		struct GLNode *_hp;
	};
	struct GLNode*_next;

	GLNode(AtomType atom, GLNode*next = NULL)
		:tag(ATOM)
		, _atom(atom)
		, _next(next){}

	GLNode(GLNode* hp, GLNode*next = NULL)
		:tag(LIST)
		, _hp(hp)
		, _next(next){}
};

class GList
{
public:
	GList()
	{}
	GList& operator=(GList x)
	{
		::swap(x._head, _head);
	}

	GList(const char *str)
		:_head(NULL)
	{
		_head = _CreatGList(str);
	}
	
	GList(const GList& gl)
	{
		_head = _Copy(gl._head);
	}

	~GList()
	{
		_Destroy(_head);
	}

	void Print()
	{
		_Print(_head);
		cout << endl;
	}
	size_t Size()
	{
		return _Size(_head);
	}
	
	size_t Depth()
	{
		return _Depth(_head);
	}
protected:


	void _Destroy(GLNode* head)
	{
		while (head)
		{
			GLNode*del = head;
			head = head->_next;
			if (del->tag == LIST)
			{
				_Destroy(del->_hp);
				delete del;
			}
			else
			{
				delete del;
			}
		}
	}
	GLNode* _Copy(GLNode* head)
	{
		if (head == NULL)
			return NULL;
		GLNode* newH = new GLNode(nullptr);
		GLNode* ret = newH;
		head = head->_next;
		while (head)
		{
			if (head->tag == LIST)
			{
				ret->_next= new GLNode(nullptr);
				ret->_next->_hp = _Copy(head->_hp);
			}
			else if (head->tag == ATOM)
				ret->_next = new GLNode(head->_atom);
			ret = ret->_next;
			head = head->_next;
		}
		return newH;
	}
	size_t _Depth(GLNode*head)
	{
		if (head == NULL)
			return 1;
		size_t max = 1;
		head = head->_next;
		while (head)
		{
			if (head->tag == LIST)
			{	
				size_t dep =_Depth(head->_hp);
				if (dep > max)
					max = dep;
			}
			head = head->_next;
		}
		return max;
	}

	size_t _Size(GLNode* head)
	{
		size_t size = 0;
		if (head == NULL)
			return size;
		head = head->_next;
		while (head)
		{
			if (head->tag == ATOM)
			{
				size++;
			}
			else
				size += _Size(head->_hp);
			head = head->_next;
		}
		return size;
	}
	void _Print(GLNode*head)
	{
		if (head == NULL)
		{
			cout << "()";
			return;
		}
		cout << '(';
		head = head->_next;
		while (head)
		{
			if (head->tag == LIST)
			{
				_Print(head->_hp);
				head = head->_next;
			}
		
			else if (head->tag == ATOM)
			{
				cout << head->_atom;
				head = head->_next;
				
			}
			if (head != NULL)
				cout << ',';
		}
		cout << ')';
	}
	GLNode* _CreatGList(const char* &str)
	{
		if (*str == '\0')
		{
			return NULL;
		}
		GLNode* head =new GLNode(nullptr);
		GLNode*cur = head;
		++str;
		while (*str)
		{
			if (*str == '(')
			{
				cur->_next = new GLNode(nullptr);
				cur = cur->_next;
				cur->_hp = _CreatGList(str);
			}
			else if (*str >= '0'&&*str <= '9'
				|| *str >= 'a'&&*str <= 'z'
				|| *str >= 'A'&&*str <= 'Z')
			{
				cur->_next = new GLNode(*str);
				cur = cur->_next;
			}
			else if (*str == ')')
			{
				break;
			}
			str++;
		}
		return head;
	}

private:
	GLNode*_head;
};


int main()
{
	char a[] = "(a,b,(c,d),(e,(f),h))";
	char b[] = "";
	GList gl(a);
	gl.Print();
	cout << "gl.Size():"<<gl.Size()<< endl;
	cout << "gl.Depth():" << gl.Depth() << endl;

	GList gg(gl);
	gg.Print();
	system("pause");
	return	0;
}
