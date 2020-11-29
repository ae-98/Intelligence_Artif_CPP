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

		int coutMin(){
			int min = 9999;
			for(int i = 0 ; i<4 ; i++){
				for (int j=0 ; j<4 ; j++){
					if(this->adj[i][j]<min && i!=j)
						min = this->adj[i][j];
				}
			}
			return min;
		}

		void Searching(int start){
			//f = g + h
			int min = 999999;
			int indice = 0;
			int exp = this->g.top()+this->h.top();
			this->S.push(start);
			for(int i=0;i<4;i++){
				if(i!=start && !noedExist(i) ){
					if( min > this->adj[start][i] + exp  ){
						min = this->adj[start][i];
						indice = i;
						//cout<<this->h.top();
					}
				}
			}
			if(!noedExist(indice)){
				int pushed = ((4*3)/2)-(this->S.size()-1)*this->coutMin();
				//dfsdfdsfs
				this->h.push(pushed);
				this->g.push(min+this->g.top());
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

	// 4 sommets = alors 5*4 = 20 / 2 = 10
	//stack => 3 sommets : 10 - (3-1)
}
