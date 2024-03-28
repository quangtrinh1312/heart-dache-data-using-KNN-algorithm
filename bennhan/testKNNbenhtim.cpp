#include<bits/stdc++.h>
using namespace std;
struct T{
	float x1,x2;
	float z;
	bool nhan;
};
int n=16;
int m=4;
		T a[17];
		T b[5];
		bool c[5];
void sapxep(){
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(a[i].z>a[j].z) 		swap(a[i],a[j]);
}
void nhap(){
		ifstream ip1("testbennhan1.txt");//dia chi file training dataset
		
		for(int i=1;i<=n;i++){
			ip1>>a[i].x1>>a[i].x2>>a[i].nhan;
		}
		ip1.close();
		ifstream ip2("testbennhan2.txt");//dia chi file training dataset
		
		for(int i=1;i<=m;i++){
			ip2>>b[i].x1>>b[i].x2>>b[i].nhan;
		}
		ip2.close();
		for(int i=1;i<=m;i++){
			c[i]=b[i].nhan;
		}
}

void xuat(T a[],int n){
	for(int i=1;i<=n;i++){
			cout<<a[i].x1<<" "<<a[i].x2<<" "<<a[i].nhan<<"   "<<c[i]<<endl;
	}
}

main(){
	int k;
	do{
		cout<<"nhap k: ";cin>>k;
		nhap();
		for(int j=1;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
			{
				a[i].z=sqrt((a[i].x1-b[j].x1)*(a[i].x1-b[j].x1)+(a[i].x2-b[j].x2)*(a[i].x2-b[j].x2));
			}
			sapxep();
			int count=0;
			b[j].nhan=0;
			for(int i=1;i<=k;i++) 
				if(a[i].nhan==1) count++;
			if(k-count<count) b[j].nhan=1;
		}
		xuat(b,m);
		int count=0;
		for(int i=1;i<m;i++){
			if(b[i].nhan==c[i]) count++;
		}
		cout<<"xac suat thanh cong theo bang test lay ngau nhien: "<<((float)count/m)*100<<"%"<<endl<<endl;
	}
	while(k>0);
}
