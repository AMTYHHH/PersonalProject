#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<string,int> wf;
map<string,int> pre_word;
void save(string s){
	//cout<<s<<endl; 
	//if(pre_word.find(s)!=pre_word.end())return ;
	map<string,int>::iterator iter;
	iter = wf.find(s);
	if(iter!=wf.end())
		iter->second++;
	else
		wf[s]=1;
}
int judge(string &s){
	//cout<<s<<endl;
	int flag=1;
	if(!isalpha(s[0]))return 0;
	s[0]=tolower(s[0]);
	for(int i=1;i<s.size();i++){
		if(isalpha(s[i])&&flag){
			s[i]=tolower(s[i]);
		}
		else if(s[i]=='\'')continue;
		else if(isdigit(s[i])){
			flag=0;
			continue;
		}
		//else if(s[i]==' ')return 0;
		else{
			string s2(s,i+1);
			if(s2[0]&&judge(s2))save(s2);
			s[i]=0;
			return 1;
		}
	}
	return 1;
}
void init_pre_world(){
	FILE *file=freopen("stopwords.txt","r",stdin);
	string s;
	while(cin>>s){
		cout<<s<<endl;
		pre_word[s]=1;
	}
	fclose(stdin);
	//freopen("CON","r",stdin);
	map<string,int>::iterator iter;
	for(iter=pre_word.begin();iter!=pre_word.end();iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
}

int main(int args,char* argv[]){
	//init_pre_world();
	
	freopen(argv[1],"r",stdin);
	//freopen("essay.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	
	string s;
	map<string,int>::iterator iter;
	//cout<<"sdf"<<endl;
	while(cin>>s){//cout<<s<<endl;
		if(!judge(s))continue;
		save(s);
		
	}
	for(iter=wf.begin();iter!=wf.end();iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

