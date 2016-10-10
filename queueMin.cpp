/*
Modifying queue for finding the minimum in O (1) with 2 stacks.
Read more. http://e-maxx.ru/algo/stacks_for_minima
*/
#include <cstdio>
#include <string>
#include <stack>
#include <stdio.h>
#include <string.h>
using namespace std;
class queueMin{
	stack< pair<int,int> > s1,s2;
	public:
		void add(int newElement){
			int minima = s1.empty() ? newElement : min (newElement, s1.top().second);
			s1.push (make_pair (newElement, minima));
		}
		void pop(){
			if (s2.empty())
				while (!s1.empty()) {
					int element = s1.top().first;
					s1.pop();
					int minima = s2.empty() ? element : min (element, s2.top().second);
					s2.push (make_pair (element, minima));
				}
			s2.pop();
		}
		int getMin(){
			int currentMinimum;
			if (s1.empty())
				currentMinimum = s2.top().second;
			else if(s2.empty()) 
				currentMinimum = s1.top().second;
			else
				currentMinimum = min (s1.top().second, s2.top().second);
			return currentMinimum;
		}
};
int main() {
	
	freopen("queuemin.in", "r", stdin);
	freopen("queuemin.out", "w", stdout);
	queueMin queue;
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		char cmd;
		scanf(" %c", &cmd);
		if (cmd == '+'){
			int x;
			scanf("%d", &x);
			queue.add(x);
		}
		else if (cmd == '?'){
			int x = queue.getMin();
			printf("%d\n",x);
		}
		else {
			queue.pop();
		}	
	}
  	return 0;
}


