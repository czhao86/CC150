#include <iostream>
#include <stack>
using namespace std;

struct op
{
	int begin, end;
	char src, bri, des;
	op() {}
	op(int pbegin, int pend, char psrc, char pbri, char pdes) :begin(pbegin), end(pend), src(psrc), bri(pbri), des(pdes){}
};

void hanoi(int n, char src, char bri, char des)
{
	stack<op> st;
	op temp;
	st.push(op(1, n, src, bri, des));
	while (!st.empty())
	{
		temp=st.top();
		st.pop();
		if (temp.begin!=temp.end)
		{
			st.push(op(temp.begin,temp.end-1,temp.bri,temp.src,temp.des));
			st.push(op(temp.end,temp.end,temp.src,temp.bri,temp.des));
			st.push(op(temp.begin,temp.end-1,temp.src,temp.des,temp.bri));
		}
		else
		{
			cout << "move "<<temp.begin<<" from "<<temp.src<<" to "<<temp.des<< endl;
		}
	}


}

int main()
{
	hanoi(3, 'a', 'b', 'c');
	return 0;
}
