#include<iostream>
#include<stack>
using namespace std;


class Graph{
	private:
		stack<int> S;
		stack<int> g;
		stack<int> h;
		int adj[4][4]={
			{0,3,5,7},
			{3,0,1,6},
			{5,1,0,5},
			{7,6,5,0}
			};
	public:
		Graph(){
			this->g.push(0);
			this->h.push(0);
			cout<<"you created a new graph"<<endl;
		}


		void displayAdj(){
			for(int i =0;i<4;i++){
				for(int j=0;j<4;j++){
					cout<<this->adj[i][j]<<"\t";
				}
				cout<<endl;
			}
		}

		void Searching(int start){
			//f = g + h
			int min = 999999;
			int indice = 0;
			int exp = this->g.top()+this->h.top();
			this->S.push(start);
			for(int i=0;i<4;i++){
				if( i!=start && !noedExist(i) ){
					if( min > this->adj[start][i] + exp  ){
						min = this->adj[start][i];
						indice = i;
						//cout<<this->h.top();
					}
				}
			}
			if(!noedExist(indice)){
				//dfsdfdsfs
				this->h.push(this->h.top()+this->maxIn());
				this->g.push(min+this->g.top());
				//this->S.push(indice);
				this->Searching(indice);
			};
		}

		bool noedExist(int i){
			bool exist = false;
			stack<int> copyS = this->S;
			while(!copyS.empty() && exist==false ){
				if(i == copyS.top()){
					exist = true;
				}
				copyS.pop();
			}
			return exist;
		}

		int maxIn(){
			int max = -1 ;
			for(int i=0;i<4;i++){
				for(int j=0;j<4;j++){
					if(i!=j && !noedExist(i) && !noedExist(j)){
						if(max>this->adj[i][j]){
							max=this->adj[i][j];
						}
					}
				}
			}
			return max;
		}

		void displayStack(){
			stack<int> c=this->S;
			while(!c.empty()){
				cout<<c.top()<<endl;
				c.pop();
			}
		}

};


int main(){
	Graph g;
	//g.displayAdj();
	g.Searching(2);
	g.displayStack();
}
